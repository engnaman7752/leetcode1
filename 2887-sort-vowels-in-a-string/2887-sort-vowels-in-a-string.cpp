class Solution {
public:
    string sortVowels(string s) {
        string v;
       int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a'|s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
            s[i]=='A'||s[i]=='E'||s[i]=='O'||s[i]=='I'||s[i]=='U')
            v.push_back(s[i]);
        }
        sort(v.begin(),v.end());
        int k=0;
         for(int i=0;i<n;i++){
            if(s[i]=='a'|s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
            s[i]=='A'||s[i]=='E'||s[i]=='O'||s[i]=='I'||s[i]=='U')
           { s[i]=v[k];
           k++;
           }
        }
        return s;
    }
};