class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>pre;
        pre.push_back(1);
        ans.push_back(pre);
        for(int i=2;i<=numRows;i++){
            vector<int>post(i);
            post[0]=1;
            post[i-1]=1;
            for(int i=1;i<pre.size();i++){
                post[i]=pre[i]+pre[i-1];
            }
            ans.push_back(post);
            pre=post;
        }
        return ans;
        
    }
};