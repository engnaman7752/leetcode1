class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt=0;
        vector<bool>cap(26,false);
        vector<bool>sml(26,false);
        int n=word.size();
        for(int i=0;i<n;i++){
            if(word[i]>='A' && word[i]<='Z'){
              cap[word[i]-'A']=true;
            }
            else{
                sml[word[i]-'a']=true;
            }
        }
        for(int i=0;i<26;i++){
            if(cap[i] && sml[i])cnt++;
        }
        return cnt;
    }
};