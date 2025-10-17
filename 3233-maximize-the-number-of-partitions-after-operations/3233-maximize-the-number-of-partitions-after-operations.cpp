
class Solution {
public:
    int n, K;
    string s;
    map<tuple<int,bool,int>, int> dp;

    int solve(int i, bool used, int mask) {
        if (i == n) return 0;
        auto key = make_tuple(i, used, mask);
        if (dp.count(key)) return dp[key];

        int bit = 1 << (s[i] - 'a');
        int distinct = __builtin_popcount(mask);
        int ans = 0;

        if ((mask & bit) || distinct < K) {
        
            ans = max(ans, solve(i + 1, used, mask | bit));
        } else {
            
            ans = max(ans, 1 + solve(i + 1, used, bit));
        }

    
        if (!used) {
            for (int c = 0; c < 26; ++c) {
                int newbit = 1 << c;
                if ((mask & newbit) || distinct < K) {
                    ans = max(ans, solve(i + 1, true, mask | newbit));
                } else {
                    ans = max(ans, 1 + solve(i + 1, true, newbit));
                }
            }
        }

        return dp[key] = ans;
    }

    int maxPartitionsAfterOperations(string str, int k) {
        s = str;
        n = s.size();
        K = k;
        dp.clear();
        return 1 + solve(0, false, 0);
    }
};
