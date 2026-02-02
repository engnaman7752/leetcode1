class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        set<pair<int, int>> st;
        set<pair<int, int>> sh;
        long long sum = 0;

        for (int i = 1; i <= dist + 1 && i < n; i++) {
            st.insert({nums[i], i});
            sum += nums[i];
            if (st.size() > k - 1) {
                auto it = prev(st.end());
                sum -= it->first;
                sh.insert(*it);
                st.erase(it);
            }
        }

        long long ans = sum;

        for (int i = dist + 2; i < n; i++) {

            int out_idx = i - dist - 1;
            pair<int, int> out_pair = {nums[out_idx], out_idx};

            if (st.count(out_pair)) {
                sum -= out_pair.first;
                st.erase(out_pair);
            } else {
                sh.erase(out_pair);
            }
            sh.insert({nums[i], i});
            auto it_sh = sh.begin();
            sum += it_sh->first;
            st.insert(*it_sh);
            sh.erase(it_sh);
            if (st.size() > k - 1) {
                auto it_st = prev(st.end());
                sum -= it_st->first;
                sh.insert(*it_st);
                st.erase(it_st);
            }

            ans = min(ans, sum);
        }

        return ans + (long long)nums[0];
    }
};