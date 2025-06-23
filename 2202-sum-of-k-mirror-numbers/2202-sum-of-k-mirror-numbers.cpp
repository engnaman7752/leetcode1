class Solution {
private:
    int digit[100];

public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;
        int left = 1;

        while (count < n) {
            int right = left * 10;
            for (int op = 0; op < 2 && count < n; ++op) {
                for (int i = left; i < right && count < n; ++i) {
                    long long num = makePalindrome(i, op == 0);
                    if (isBaseKPalindrome(num, k)) {
                        sum += num;
                        count++;
                    }
                }
            }
            left = right;
        }

        return sum;
    }

    bool isBaseKPalindrome(long long x, int k) {
        int len = 0;
        while (x) {
            digit[len++] = x % k;
            x /= k;
        }
        for (int i = 0, j = len - 1; i < j; ++i, --j) {
            if (digit[i] != digit[j]) return false;
        }
        return true;
    }

    long long makePalindrome(int half, bool isOdd) {
        long long res = half;
        if (isOdd) half /= 10;
        while (half) {
            res = res * 10 + (half % 10);
            half /= 10;
        }
        return res;
    }
};
