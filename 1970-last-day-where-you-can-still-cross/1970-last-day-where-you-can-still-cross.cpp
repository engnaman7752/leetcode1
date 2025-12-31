class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int start=1;
        int end=cells.size();
        int ans;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(possible(mid,row,col,cells)){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    return ans;
    }
bool possible(int day,int row, int col, vector<vector<int>>& cells){
vector<vector<int>>grid(row,vector<int>(col,0));
for(int i=0;i<day;i++){
    int r=cells[i][0];
    int c=cells[i][1];
    grid[r-1][c-1]=1;
}
for(int i=0;i<col;i++){
   if(dfs(0,i,grid))return true; 
}
return false;
}
bool dfs(int row,int col,vector<vector<int>>&grid){
    if(row < 0 || col < 0 || col >= grid[0].size()) return false;
    if(row == grid.size()) return true;
    if(grid[row][col] == 1) return false;
    grid[row][col] = 1;
     vector<int> r{1,-1,0,0};
     vector<int> c{0,0,1,-1};
    for(int i=0;i<4;i++){
        if(dfs(row + r[i], col + c[i], grid)) return true;
    }
    return false;
}
};