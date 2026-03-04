class Solution {
public:
bool check(int i,int j,vector<vector<int>>&mat){
     int n=mat.size();int m=mat[0].size();
    for(int k=0;k<m;k++){
        if(mat[i][k]==1&&k!=j)return false;
    }
    for(int k=0;k<n;k++){
        if(mat[k][j]==1&&k!=i)return false;
    }
    return true;
}
    int numSpecial(vector<vector<int>>& mat) {
        int cnt=0;
        int n=mat.size();int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1&&check(i,j,mat))cnt++;
            }
        }
        return cnt;
    }
};