class DisjointSet{
    public:
    vector<int>size;
    vector<int>parent;
    DisjointSet(int n){
        size.assign(n+1,1);
        parent.assign(n+1,0);
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
            size[pv]+=size[pu];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& account) {
        int n=account.size();
        DisjointSet ds(n);
        map<string,int>email;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<account[i].size();j++){
                if(email.find(account[i][j])!=email.end()){
                   ds.findunion(i,email[account[i][j]]);
                }
                else{
                    email[account[i][j]]=i;
                }
            }
        }

        map<int,set<string>>allEmails;
        for(int i=0;i<n;i++){
            int firstAccount=ds.findUltiPar(i);
            allEmails[firstAccount].insert(account[i].begin()+1,account[i].end());
        }

        vector<vector<string>>mergeAccounts;
        for(auto it:allEmails){
            vector<string> temp;
            temp.push_back(account[it.first][0]); // name
            temp.insert(temp.end(),it.second.begin(),it.second.end());
            mergeAccounts.push_back(temp);
        }
        return mergeAccounts;
    }
};
