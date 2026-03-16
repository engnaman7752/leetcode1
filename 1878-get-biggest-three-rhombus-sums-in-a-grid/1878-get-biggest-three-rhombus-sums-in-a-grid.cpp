class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        set<int> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                st.insert(grid[i][j]);
                for(int k=1;;k++){
                    if(i+2*k>=n || j-k<0 || j+k>=m) break;
                    int sum=0;
                    int x=i,y=j;
                    for(int t=0;t<k;t++) sum+=grid[x+t][y-t];
                    for(int t=0;t<k;t++) sum+=grid[x+k+t][y-k+t];
                    for(int t=0;t<k;t++) sum+=grid[x+2*k-t][y+t];
                    for(int t=0;t<k;t++) sum+=grid[x+k-t][y+k-t];
                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for(auto it=st.rbegin();it!=st.rend() && ans.size()<3;it++)
            ans.push_back(*it);

        return ans;
    }
};