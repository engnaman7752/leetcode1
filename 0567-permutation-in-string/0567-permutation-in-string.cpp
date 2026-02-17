class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int w=s1.size();int n=s2.size();
        vector<int>a(26,0);vector<int>b(26,0);
        for(int i=0;i<w;i++)a[s1[i]-'a']++;
        int left=0;
        for(int right=0;right<n;right++){
            b[s2[right]-'a']++;
            if(right-left+1==w){
                if(a==b)return true;
                b[s2[left]-'a']--;
                left++;
            }
        }
        return false;
    }
};