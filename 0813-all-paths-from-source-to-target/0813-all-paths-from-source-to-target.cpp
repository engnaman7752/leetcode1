class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>allPaths;
        vector<int>path;
        int n=graph.size();
         path.push_back(0);
        solve(n,0,path,allPaths,graph);
        return allPaths;
    }
    void solve(int n,int node,vector<int>&path,vector<vector<int>>&allPaths,vector<vector<int>>& graph){
        if(node==n-1){
            allPaths.push_back(path);
            return;
        }
        for(auto neighbour:graph[node]){
            path.push_back(neighbour);
            solve(n,neighbour,path,allPaths,graph);
            path.pop_back();
        }
    }
};