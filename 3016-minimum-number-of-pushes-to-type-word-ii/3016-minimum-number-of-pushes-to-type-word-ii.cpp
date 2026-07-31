class Solution {
public:
    int minimumPushes(string word) {
        vector<int>a(26,0);
        for(char c:word){
            a[c-'a']++;
        }
        sort(a.rbegin(),a.rend());
        int cnt=0;
        int ans=0;
        int mul=1;
        for(int i=0;i<26;i++){
            ans+=mul*a[i];
            if(a[i]==0)break;
            cnt++;
            if(cnt==8){cnt=0;mul++;}
        }
        return ans;
    }
};