class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int>pre;
        pre.push_back(1);
        vector<vector<int>>ans;
        ans.push_back(pre);
        for(int i=2;i<=numRows;i++){
            vector<int>share(i);
            share[0]=pre[0];
            share[i-1]=pre[pre.size()-1];
            for(int j=1;j<i-1;j++){
                share[j]=pre[j]+pre[j-1];
            }
            pre=share;
            ans.push_back(share);
        }
        return ans;
        
    }
};