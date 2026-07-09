class DSU{
    public:
    vector<int>parent;
    vector<int>size;
    DSU(int n){
        parent.resize(n+1);
        for(int i=0;i<=n;i++)parent[i]=i;
        size.assign(n+1,1);
    }
    int ultiPar(int u){
        if(parent[u]==u)return u;
        else return parent[u]=ultiPar(parent[u]);
    }
    bool unite(int u,int v){
        int pu=ultiPar(u);
        int pv=ultiPar(v);
        if(pu==pv)return false;
        if(size[pv]>size[pu])swap(pu,pv);
        parent[pv]=parent[pu];
        size[pu]+=size[pv];
        return true;
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>ans;
        DSU ds(n);
        int i=0;
        while(i<n){
            int j=i+1;
            bool flag=true;
            while(j<n&&nums[j]-nums[i]<=maxDiff){
                ds.unite(i,j);
                j++;
                flag=false;
            }
            if(j==n)break;
            if(flag)i=j;
            else
            i=j-1;
        }
        for(auto q:queries){
            int u=q[0];
            int v=q[1];
            if(ds.parent[u]==ds.parent[v]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};