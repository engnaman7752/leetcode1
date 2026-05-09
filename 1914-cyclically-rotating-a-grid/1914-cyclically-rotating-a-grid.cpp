class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans = grid;

        for (int r = 0; r < min(n, m) / 2; r++) {

            vector<int> arr;

            int row = r;
            int col = r;
            while (col < m - r - 1) {
                arr.push_back(grid[row][col]);
                col++;
            }

            while (row < n - r - 1) {
                arr.push_back(grid[row][col]);
                row++;
            }
            while (col > r) {
                arr.push_back(grid[row][col]);
                col--;
            }
            while (row > r) {
                arr.push_back(grid[row][col]);
                row--;
            }
            int sz = arr.size();
            int actualK = k % sz; 
            reverse(arr.begin(), arr.begin() + actualK);
            reverse(arr.begin() + actualK, arr.end());
            reverse(arr.begin(), arr.end());
            row = r;
            col = r;
            int i = 0;
            while (col < m - r - 1) {
                ans[row][col] = arr[i++];
                col++;
            }
            while (row < n - r - 1) {
                ans[row][col] = arr[i++];
                row++;
            }

            while (col > r) {
                ans[row][col] = arr[i++];
                col--;
            }

            while (row > r) {
                ans[row][col] = arr[i++];
                row--;
            }
        }

        return ans;
    }
};