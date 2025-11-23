class Solution {
public:
    int minimumFlips(int n) {
        int len=(int)(log2(n));
        string s=bitset<64>(n).to_string().substr(64 - len - 1);
        string r=s;
        reverse(r.begin(), r.end());
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=r[i])ans++;
        }
        return ans;
    }
};