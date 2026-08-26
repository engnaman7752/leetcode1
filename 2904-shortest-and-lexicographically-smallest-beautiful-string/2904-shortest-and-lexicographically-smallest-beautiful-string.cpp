class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
       string ans="";
       int n=s.size();
       int left=0;
       int cnt=0;
       while(left<n && s[left]!='1')left++;
       for(int right=left;right<n;right++){
        if(s[right]=='1'){
            cnt++;
        }
        if(cnt==k){
            string t=s.substr(left,right-left+1);
            if(ans.empty() || ans.size()>t.size()){
                ans=t;
            }
            else if(ans.size()==t.size() && ans!=t){
                int i=0;
                while(i<t.size()){
                    if(ans[i]>t[i]){
                        ans=t;
                        break;
                    }
                    else if(ans[i]<t[i])break;
                    i++;
                }
            }
            while(left<n && cnt==k){
                if(s[left]=='1')cnt--;
                left++;
            }
            while(left<n && s[left]!='1')left++;

        }
       }
       return ans;
    }
};