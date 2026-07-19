class Solution {
public:
    string smallestSubsequence(string s) {
       vector<int>arr(26,0),vis(26,0);
       int n=s.size();
       string ans="";
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            if(!vis[s[i]-'a']){
            while(!ans.empty() && ans.back()>s[i]){
                if(arr[ans.back()-'a']==0){
                    break;
                }
                else{
                vis[ans.back()-'a']=0;
                ans.pop_back();
                }
            }
            ans.push_back(s[i]); 
            vis[s[i]-'a']=1;
        }
        arr[s[i]-'a']--;
        }
       
        return ans;
    }
};