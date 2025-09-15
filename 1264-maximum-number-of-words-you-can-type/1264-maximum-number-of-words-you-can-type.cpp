class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char>st(brokenLetters.begin(),brokenLetters.end());
        bool flag=false;
        int ans=0;
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                if(flag==false){
                    ans++;
                }
                flag=false;
            }
            else if(st.find(text[i])!=st.end())flag=true;
        }
        if(flag==false)ans++;
        return ans;
    }
};