class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        s+=s;
        for(int i=0;i<n;i++){
            string l=s.substr(i,n);
            if(l==goal)return true;
        }
        return false;
    }
};