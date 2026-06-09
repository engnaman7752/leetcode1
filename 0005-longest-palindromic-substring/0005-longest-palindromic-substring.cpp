class Solution {
public:
    bool pal(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])return 0;
            i++;
            j--;
        }
        return 1;
    }
    string longestPalindrome(string s) {
        map<char,vector<int>>mp;
        int left=0;
        int right=0;
        int n=s.size();
        for(int i=0;i<n;i++){
           if(mp.find(s[i])!=mp.end()){
                vector<int>temp=mp[s[i]];
                for(int k=0;k<temp.size();k++){
                    if(i-temp[k]>right-left){
                        if(pal(s,temp[k],i)){
                            right=i;left=temp[k];
                        }
                    }
             }
           }
           mp[s[i]].push_back(i);
        }
        return s.substr(left,right-left+1);
    }
};