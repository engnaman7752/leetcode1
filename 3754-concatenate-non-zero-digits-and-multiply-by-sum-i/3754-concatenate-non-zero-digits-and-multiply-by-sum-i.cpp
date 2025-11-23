class Solution {
public:
    long long sumAndMultiply(int n) {
    long long ans=0;
    string a=to_string(n);
    string b;
    for(int i=0;i<a.size();i++){
        if(a[i]!='0'){b.push_back(a[i]);}
        ans+=a[i]-'0';
    }
    if(b.size()==0)return 0;
    return stoll(b)*ans;
    }
};