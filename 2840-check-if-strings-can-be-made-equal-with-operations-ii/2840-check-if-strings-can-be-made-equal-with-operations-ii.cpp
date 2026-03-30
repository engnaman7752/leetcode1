class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
       map<char,int>odd1;
       map<char,int>odd2;
       map<char,int>even1;
       map<char,int>even2;
       for(int i=0;i<n;i++){
        if(i%2){
            odd1[s1[i]]++;
            odd2[s2[i]]++;
        }
        else{
            even1[s1[i]]++;
            even2[s2[i]]++;
        }
       } 
       return odd1==odd2 && even1==even2;
    }
};