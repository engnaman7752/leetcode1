class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int oddCount = 0, evenCount = 1;  
        long long count = 0, prefixSum = 0;
        
        for (int num : arr) {
            prefixSum += num;
            if (prefixSum % 2) { 
                count = (count + evenCount) % MOD;
                oddCount++;
            } else { 
                count = (count + oddCount) % MOD;
                evenCount++;
            }
        }
        return count;
    }
};
