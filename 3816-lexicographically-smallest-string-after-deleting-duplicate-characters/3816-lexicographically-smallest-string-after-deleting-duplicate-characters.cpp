class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        map<char,int>mp;
        map<char,int>in;
        for(char c:s){
            mp[c]++;
        }
        string ans;
        int i=0;int n=s.size();
        while(i<n){
           char c=s[i];
           mp[c]--;
           while(!ans.empty()){
            char last=ans.back();
            if(last>c&&(mp[last]>0||in[last]>1)){
                ans.pop_back();
                in[last]--;
            }
            else break;
           }
           ans.push_back(c);
           in[c]++;
           i++;
        }
          while (!ans.empty() && in[ans.back() ] > 1) {
            in[ans.back()]--;
            ans.pop_back();
        }
        return ans;
    }
};