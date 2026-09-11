class Solution {
public:
bool check(int row,int col,vector<string>&t){
    int n=t.size();
    for(int i=row-1;i>=0;i--){
        if(t[i][col]=='Q')return false;
    }
    for(int i=row,j=col;i>=0 && j>=0 ;i--,j--){
        if(t[i][j]=='Q')return false;
    }
    for(int i=row,j=col;i>=0 && j<n ;i--,j++){
        if(t[i][j]=='Q')return false;
    }
    return true;

}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>t(n,string(n,'.'));
        solve(0,ans,t);
        return ans;
    }
    void solve(int i,vector<vector<string>>&ans,
        vector<string>&t){
            int n=t.size();
            if(i==n){
                ans.push_back(t);
            }
            for(int k=0;k<n;k++){
               if(check(i,k,t)){
                t[i][k]='Q';
                solve(i+1,ans,t);
                t[i][k]='.';
               }
            }
        }
};