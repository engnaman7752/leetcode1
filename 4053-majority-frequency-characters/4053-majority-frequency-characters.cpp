class Solution {
public:
    string majorityFrequencyGroup(string s) {
        map<int,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        map<int,string>ans;
        string a="";int curr=0;
        for(auto it:mp ){
            ans[it.second].push_back(it.first);
                if((ans[it.second].size()==a.size()&&curr<it.second)||(ans[it.second].size()>a.size())){
                    a=ans[it.second];
                    curr=it.second;}
            }
        return a;
    }
};