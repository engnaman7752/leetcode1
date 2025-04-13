class Solution {
public:
    long long x = 1e9 + 7;

    long long pow(long long num, long long base) {
        long long result = 1;
        num %= x;
        while (base > 0) {
            if (base % 2 == 1) {
                result = (result * num) % x;
            }
            num = (num * num) % x;
            base /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long ans = (pow(5, (n / 2 + n % 2)) * pow(4, n / 2)) % x;
        return (int)ans;
    }
};
