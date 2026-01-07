class Solution {
public:
    string largestEven(string s) {
        for(int i=s.size()-1;i>=0;i--){
            if((s[i]-'0')%2==0){
                string t(s.begin(),s.begin()+i+1);
                return t;
            }
        }
        return "";
    }
};