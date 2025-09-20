class DisjointSet{
    public:
    vector<int>size;
    vector<int>parent;
    DisjointSet(int n){
        size.assign(n+1,1);
        parent.assign(n+1,1);
        for(int i=0;i<n+1;i++)parent[i]=i;
    }
    int findUltiPar(int u){
        if(parent[u]==u)return u;
        return parent[u]=findUltiPar(parent[u]);
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
            size[pv]+=pu;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        map<int,int>row;
        map<int,int>col;
        int n=stones.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            if(row.find(stones[i][0])!=row.end()){
                ds.findunion(i,row[stones[i][0]]);
            }
            row[stones[i][0]]=i;
             if(col.find(stones[i][1])!=col.end()){
                ds.findunion(i,col[stones[i][1]]);
            }
            col[stones[i][1]]=i;

        }
        int connectedStones=0;
        for(int i=0;i<n;i++){
            if(ds.findUltiPar(i)==i)connectedStones++;
        }
        int deleted=n-connectedStones;
        return deleted;
    }
};