class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,vector<int>& waterStartTime, vector<int>& waterDuration) {
        auto hs = tie(landStartTime, landDuration, waterStartTime, waterDuration);

        int bestl = INT_MAX;
        for (int i = 0, n = landStartTime.size(); i < n; ++i) {
            bestl = min(bestl, landStartTime[i] + landDuration[i]);
        }

        int bw = INT_MAX;
        for (int j = 0, m = waterStartTime.size(); j < m; ++j) {
            bw = min(bw, waterStartTime[j] + waterDuration[j]);
        }

        int ans = INT_MAX;
        for (int j = 0, m = waterStartTime.size(); j < m; ++j) {
            int sw = waterStartTime[j];
            int finish = (bestl <= sw
                          ? sw + waterDuration[j]
                          : bestl + waterDuration[j]);
            ans = min(ans, finish);
        }

        for (int i = 0, n = landStartTime.size(); i < n; ++i) {
            int sl = landStartTime[i];
            int finish = (bw <= sl
                          ? sl + landDuration[i]
                          : bw + landDuration[i]);
            ans = min(ans, finish);
        }

        return ans;
    }
};
