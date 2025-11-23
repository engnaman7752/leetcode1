class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long sum = 1LL * n * (n + 1) / 2;
        if (llabs(target) > sum) return {};
        long long diff = sum - target;
        if (diff < 0 || (diff & 1)) return {};
        long long need = diff / 2;     

        vector<int> a(n + 1, 0);
        long long curr = 0;
        int start = n;
        while (start > 0 && curr < need) {
            if (curr + start <= need) {
                curr += start;
                a[start] = 1;           
            }
            start--;
        }

        if (curr != need) return {};    

        vector<int> ans;
        for (int i = n; i >= 1; --i) {
            if (a[i] == 1) ans.push_back(-i);
        }
     
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 0) ans.push_back(i);
        }

        return ans;
    }
};
