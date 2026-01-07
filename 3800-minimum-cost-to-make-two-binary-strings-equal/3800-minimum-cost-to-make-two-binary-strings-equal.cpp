class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
      int a=0;
      int b=0;
      long long ans=0;
      for(int i=0;i<s.size();i++){
        if(s[i]==t[i])continue;
        if(s[i]=='1')a++;
        else b++;
      }
        int m = min(a, b);
        ans += m * min(1LL*swapCost, 2LL * flipCost);
        a -= m; b -= m;
    if(abs(a-b)%2)ans+=flipCost;
    ans+=min(1LL*(swapCost+crossCost),2LL*flipCost)*(abs(a-b)/2);

   return ans;
    }
};