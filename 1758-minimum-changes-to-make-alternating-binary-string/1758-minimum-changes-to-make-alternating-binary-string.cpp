class Solution {
public:
    int minOperations(string s) {
        int ans1=0,ans2=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                if(s[i]=='0')ans2++;
                else ans1++;
            }
            else{
                if(s[i]=='0')ans1++;
                else ans2++;
            }
        }
        return min(ans1,ans2);
    }
};