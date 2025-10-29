class Solution {
public:
    int smallestNumber(int n) {
        int num=0;
        vector<int>a;
        int k=11;
        while(k--){
            num=(num<<1)|1;
            a.push_back(num);
        }
        return *lower_bound(a.begin(),a.end(),n);
    }
};