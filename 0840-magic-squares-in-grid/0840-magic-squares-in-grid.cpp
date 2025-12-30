class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                set<int>st;
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        if(grid[i+k][j+l]>9||grid[i+k][j+l]==0){
                            break;
                        }
                        else
                        st.insert(grid[i+k][j+l]);
                    }
                    
                }
                if(st.size()==9){
                    int d1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                    int d2=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
                    int r1=0;
                    int r2=0;
                    int r3=0;
                    int c1=0;
                    int c2=0;
                    int c3=0;
                    for(int k=0;k<3;k++){
                        r1+=grid[i][j+k];
                        r2+=grid[i+1][j+k];
                        r3+=grid[i+2][j+k];
                        c1+=grid[i+k][j];
                        c2+=grid[i+k][j+1];
                        c3+=grid[i+k][j+2];
                        }
                        if(d1==d2&&d2==r1&&r2==r3&&r3==c1&&c1==c2&&c2==c3&&c3==d1)ans++;
                    
                }
            }
        }
        return ans;
    }
};