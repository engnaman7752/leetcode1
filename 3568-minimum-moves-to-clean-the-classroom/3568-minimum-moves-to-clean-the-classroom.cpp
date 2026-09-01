class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        queue<tuple<int, int, int, int, int>> q; // x, y, cnt, mask, eng
        int n = classroom.size();
        int m = classroom[0].size();
        
        // 1. Assign unique IDs to each litter to use a bitmask
        vector<vector<int>> litterId(n, vector<int>(m, -1));
        int totalLitters = 0;
        int startX = 0, startY = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (classroom[i][j] == 'L') {
                    litterId[i][j] = totalLitters++;
                }
            }
        }
        
        // 2. Initialize visited array: visited[row][col][mask] 
        // We store the max energy we've had at this state to avoid revisiting with equal or less energy
        vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(1 << totalLitters, -1)));
        
        q.push({startX, startY, 0, 0, energy});
        visited[startX][startY][0] = energy;
        
        vector<int> dc{0, 0, 1, -1};
        vector<int> dr{1, -1, 0, 0};
        int targetMask = (1 << totalLitters) - 1; // All 1s for every litter piece

        while (!q.empty()) {
            auto [x, y, cnt, mask, eng] = q.front();
            q.pop();
            
            // If the mask matches the target, all litter is collected
            if (mask == targetMask)
                return cnt;
                
            // Note: Use 'eng > 0' instead of the global 'energy > 0'
            if (eng > 0) { 
                for (int i = 0; i < 4; i++) {
                    int row = x + dr[i];
                    int col = y + dc[i];
                    
                    if (row >= 0 && row < n && col >= 0 && col < m && classroom[row][col] != 'X') {
                        int nextMask = mask;
                        int nextEng = eng - 1;
                        
                        // Update mask using bitwise OR if we step on litter
                        if (classroom[row][col] == 'L') {
                            nextMask |= (1 << litterId[row][col]);
                        }
                        
                        // Reset energy if we step on 'R'
                        if (classroom[row][col] == 'R') {
                            nextEng = energy; 
                        }
                        
                        // 3. Only push to queue if we arrive at this specific state with MORE energy than before
                        if (nextEng > visited[row][col][nextMask]) {
                            visited[row][col][nextMask] = nextEng;
                            q.push({row, col, cnt + 1, nextMask, nextEng});
                        }
                    }
                }
            }
        }
        return -1;
    }
};