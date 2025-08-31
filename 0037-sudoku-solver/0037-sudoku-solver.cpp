class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> nums = board;
        solve(0, 0, nums, board);
    }

    bool solve(int i, int j, vector<vector<char>>& nums, vector<vector<char>>& board) {
        if(i == 9) { // solved entire board
            board = nums;
            return true;
        }

        if(nums[i][j] != '.') {
            if(j < 8) return solve(i, j+1, nums, board);
            else return solve(i+1, 0, nums, board);
        }

        for(char k='1'; k<='9'; k++) {
            if(poss(i, j, k, nums)) {
                nums[i][j] = k;
                bool ok;
                if(j < 8) ok = solve(i, j+1, nums, board);
                else ok = solve(i+1, 0, nums, board);
                if(ok) return true; 
                nums[i][j] = '.';     
            }
        }
        return false; 
    }

    bool poss(int i, int j, char k, vector<vector<char>>& nums) {
        for(int l=0; l<9; l++) {
            if(nums[l][j] == k) return false;
            if(nums[i][l] == k) return false; 
        }
        int x = (i/3) * 3;
        int y = (j/3) * 3;
        for(int p=0; p<3; p++) {
            for(int q=0; q<3; q++) {
                if(nums[x+p][y+q] == k) return false;
            }
        }
        return true;
    }
};
