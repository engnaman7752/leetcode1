class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> pre(n + 1);

        pre[0] = -1;
        for (int i = 0; i < n; i++) {
            if (i == 0 || s[i - 1] == '0')
                pre[i + 1] = i;
            else
                pre[i + 1] = pre[i];
        }

        long long res = 0;

        for (int i = 1; i <= n; i++) {

            int cnt0 = (s[i - 1] == '0');
            int j = i;

            while (j > 0 && 1LL * cnt0 * cnt0 <= n) {

                int len = i - pre[j];      
                int cnt1 = len - cnt0;     

                if (1LL * cnt0 * cnt0 <= cnt1) {

                    int maxExtend = cnt1 - cnt0 * cnt0 + 1;
                    int canTake = j - pre[j];

                    res += min(canTake, maxExtend);
                }

                j = pre[j];  
                cnt0++;
            }
        }

        return (int)res;
    }
};
