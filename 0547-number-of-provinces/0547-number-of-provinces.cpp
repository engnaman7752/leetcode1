class Solution {
public:
 void dfs(int node, vector<int>& vis, vector<vector<int>>& isConnected) {
        vis[node] = true;
        for(int it = 0; it < isConnected.size(); it++) {
            if(isConnected[node][it] == 1 && !vis[it]) {
                dfs(it, vis, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         int count = 0;
        vector<int> vis(isConnected.size(), false);

        for(int i = 0; i < vis.size(); i++) {
            if(!vis[i]) {
                count++;
                dfs(i, vis, isConnected);
            }
        }
        return count;
        
    }
};