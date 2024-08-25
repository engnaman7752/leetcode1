class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        unordered_map<char,int>m;
        for(int i=0;i<n;i++)
        {
           char ch= s[i];
           m[ch]++;
        }
        for(int i=0;i<n;i++)
        {
           if (m[s[i]]==1)
           return i;
        }
        return -1;
        
    }
};