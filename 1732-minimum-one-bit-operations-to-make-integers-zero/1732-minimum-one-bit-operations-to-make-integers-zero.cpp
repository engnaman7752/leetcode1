class Solution {
public:
    int minimumOneBitOperations(int n) {
        long long b = n;
        while(n >>= 1) {
            b ^= n;
        }
        return b;
    
    }
};