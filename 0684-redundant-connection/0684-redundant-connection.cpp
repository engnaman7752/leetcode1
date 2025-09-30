class DisjointSet{
    public:
    vector<int>parent;
    vector<int>size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.assign(n+1,1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    int findUltiPar(int u){
        if(parent[u]==u)return u;
        else return parent[u]=findUltiPar(parent[u]);
    }
   void findunion(int u,int v){
        int pu=findUltiPar(u);
        int pv=findUltiPar(v);
        if(pu==pv)return;
        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet ds(n);
        for(auto e:edges){
            if(ds.findUltiPar(e[0])==ds.findUltiPar(e[1]))return {e[0],e[1]};
            else{
                ds.findunion(e[0],e[1]);
            }
        }
       return {};
    }
};