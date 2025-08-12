class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        map<int,vector<int>>mp;
        for(int i=0;i<limit.size();i++){
            mp[limit[i]].push_back(value[i]);
        }
        long long ans=0;
        for(auto it:mp){
            sort(it.second.begin(),it.second.end());
            int x=it.second.size()-1;
            int count=0;
            while(x>=0&&count<it.first)
            {
                ans=ans+it.second[x];
                x--;
                count++;
            }
        }
        return ans;
    }
};