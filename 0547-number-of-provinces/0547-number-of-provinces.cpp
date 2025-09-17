class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>vis(n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int k=0;k<n;k++){
                        if(isConnected[node][k]==1&&!vis[k]){
                            vis[k]=true;
                            q.push(k);
                        }
                    }
                }
            }
        }
        return ans;
    }
};