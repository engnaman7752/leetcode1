class Solution {
public:
    int longestSubsequence(string s, int k) {
       int val=0;
       int pow=0;
       int bits=32 - __builtin_clz(k);
        int n=s.size();
        int count=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
            count++;
            else
            {
                if(pow<bits&&(1<<pow)+val<=k)
                {
                    count++;
                    val=(1<<pow)+val;
                }
            }
            pow++;
        }
        return count;
        
    }
};