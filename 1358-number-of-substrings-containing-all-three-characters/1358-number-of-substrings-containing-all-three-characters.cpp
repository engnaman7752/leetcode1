class Solution {
public:
    int numberOfSubstrings(string s) {
       int a=-1;
        int b=-1;
        int c=-1;
        int ans=0;
        int start=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a')a=i;
            else if(s[i]=='b')b=i;
            else c=i;
            if(a>=start && b>=start && c>=start && a!=-1 && b!=-1 && c!=-1){
                int left=min({a,b,c})-start+1;
                int right=n-max({a,b,c});
                ans+=(left*right);
                start=min({a,b,c})+1;
            }
        }
        return ans;  
    }
};