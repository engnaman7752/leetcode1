class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int row2=x+k-1;
        while(row2>x){
            for(int i=y;i<k+y;i++){
                swap(grid[row2][i],grid[x][i]);
            }
            row2--;
            x++;
        }
return grid;
    }
};