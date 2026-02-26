class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        int n=s.size();
        for(int i=n-1;i>0;){
            if(s[i]=='0'){
                ans++;
                i--;
            }
            else{
                ans+=2;
                while((i-1>=0)&&s[i-1]=='1'){
                    ans++;
                    i--;
                }
                if(i>0)s[i-1]='1';
                i--;
            }
        }
        return ans;
    }
};