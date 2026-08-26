class Solution {
public:
    int isPal(int i,int j,string &s){
       int cnt=0;
       int n=s.size();
       while(i>=0 && j<n&&s[i]==s[j]){
        cnt++;
        i--;j++;
       }
       return cnt;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
          cnt+=isPal(i,i,s);
          cnt+=isPal(i,i+1,s);  
        }
        return cnt;
    }
    
};