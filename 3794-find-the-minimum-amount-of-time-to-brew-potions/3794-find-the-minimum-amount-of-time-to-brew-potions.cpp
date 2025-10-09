class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mann) {
        int n = skill.size();
        int m = mann.size();
        vector<long long> times(n);

        times[0] = skill[0] * mann[0];
        for (int i = 1; i < n; i++) {
            times[i] = times[i - 1] + skill[i] * mann[0];
        }

        for (int j = 1; j < m; j++) {
            long long cur_time = 0;
            for (int i = 0; i < n; i++) {
                cur_time = max(cur_time, times[i]) + skill[i] * mann[j];
            }
            times[n - 1] = cur_time;
            for (int i = n - 2; i >= 0; i--) {
                times[i] = times[i + 1] - skill[i + 1] * mann[j];
            }
        }

        return times[n - 1];
    }
};
