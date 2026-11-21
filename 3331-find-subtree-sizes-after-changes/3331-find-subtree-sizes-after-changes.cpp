class Solution {
public:
int solve(int node,vector<set<int>>&adj,vector<int>&ans){
    int t=1;
    for(auto nd:adj[node]){
        t+=solve(nd,adj,ans);
    }
    return ans[node]=t;
}
void dfs(int node,vector<set<int>>&adj,string &s,map<char,int>&mp,vector<int>&newPar){
    int prev=-1;
     if(mp.find(s[node])!=mp.end()){
        prev=mp[s[node]];
       newPar[node]=mp[s[node]];
    }
    mp[s[node]]=node;
    for(auto nd:adj[node]){
        dfs(nd,adj,s,mp,newPar);
    }
    if (prev == -1) mp.erase(s[node]);
    else mp[s[node]] = prev;
}
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=s.size();
        vector<set<int>>adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].insert(i);
        }
        map<char,int>mp;
        vector<int>newPar=parent;
        dfs(0,adj,s,mp,newPar);
        vector<set<int>>adj2(n);
        for(int i=1;i<n;i++){
            adj2[newPar[i]].insert(i);

        }
        vector<int>ans(n,-1);
        solve(0,adj2,ans);
        return ans;

    }
};