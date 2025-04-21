class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long sum = 0, minSum = 0, maxSum = 0;

        for (int d : differences) {
            sum += d;
            minSum = min(minSum, sum);
            maxSum = max(maxSum, sum);
        }
        long long left = lower - minSum;
        long long right = upper - maxSum;

        return max(0LL, right - left + 1);
    }
};
