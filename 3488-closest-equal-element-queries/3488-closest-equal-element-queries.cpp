class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = queries.size();
        vector<int> ans;
        unordered_map<int, vector<int>> mp; // unordered_map is faster
        int r = nums.size();
        for (int i = 0; i < r; i++) {
            mp[nums[i]].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            vector<int>& t = mp[nums[queries[i]]]; // Added & to avoid copying
            int m = t.size();
            if (m == 1) {
                ans.push_back(-1);
            } else if (m == 2) {
                ans.push_back(min(abs(t[0] - t[1]), r - (abs(t[0] - t[1]))));
            } else {
                auto it = lower_bound(t.begin(), t.end(), queries[i]);
                int l = distance(t.begin(), it);
                int left = (l - 1 + m) % m;
                int right = (l + 1) % m;

                auto getDist = [&](int idx1, int idx2) {
                    int diff = abs(idx1 - idx2);
                    return min(diff, r - diff);
                };

                int k = min(getDist(queries[i], t[left]),
                            getDist(queries[i], t[right]));
                ans.push_back(k);
            }
        }
        return ans;
    }
};