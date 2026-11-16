class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string t="";
            for(int i=0;i<s.size();i+=k){
                int sum=0;
                for(int j=0;j<k && j+i<s.size();j++){
                    sum+=s[i+j]-'0';
                }
                string l=to_string(sum);
                t+=l;
            }
            s=t;
        }
        return s;
    }
};