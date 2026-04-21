class DisjointSet{
    public:
    vector<int>parent;
    vector<int>size;
    DisjointSet(int n){
        parent.resize(n);
        size.assign(n,1);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int ultiPar(int u){
        if(parent[u]==u)return u;
        return parent[u]=ultiPar(parent[u]);
    }
    void findUnion(int u,int v){
        int pu=ultiPar(u);
        int pv=ultiPar(v);
        if(pu==pv)return;
        if(size[pu]<size[pv])swap(pu,pv);
        parent[pv]=pu;
        size[pu]+=size[pv];
    }
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
       map<int,vector<int>>mp;
       int n=source.size();
       DisjointSet ds(n);
       for(int i=0;i<n;i++){
        mp[target[i]].push_back(i);
       }
       for(auto e:allowedSwaps){
        ds.findUnion(e[0],e[1]);
       }
       int ans=0;
       for(int i=0;i<n;i++){
        if(source[i]==target[i])continue;
        bool flag=true;
        for(auto e:mp[source[i]]){
            if(ds.ultiPar(i)==ds.ultiPar(e)){
                flag=false;
                break;
            }
        }
        if(flag)ans++;
       }
       return ans;
    }
};