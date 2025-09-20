class DisjointSet{
    public:
    vector<int>parent;
    vector<int>size;
    DisjointSet(int n){
        size.assign(n+1,1);
        parent.assign(n+1,0);
        for(int i=0;i<n+1;i++)
        parent[i]=i;
    }
    int findUltiPar(int u ){
        if(parent[u]==u)return u;
        return parent[u]=findUltiPar(parent[u]);
    }
    void unionfind(int u,int v){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        DisjointSet ds(n);
        int need=0;
        for(auto c:connections){
            ds.unionfind(c[0],c[1]);
        }
        for(int i=0;i<n;i++){
            if(ds.findUltiPar(i)==i)need++;
        }
        return need-1;
    }
};