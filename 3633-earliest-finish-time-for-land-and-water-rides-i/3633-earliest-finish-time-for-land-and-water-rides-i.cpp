class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minn = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int start1 = max(landStartTime[i], 0);
                int end1 = start1 + landDuration[i];
                int start2 = max(waterStartTime[j], end1);
                int total1 = start2 + waterDuration[j];

                int start3 = max(waterStartTime[j], 0);
                int end3 = start3 + waterDuration[j];
                int start4 = max(landStartTime[i], end3);
                int total2 = start4 + landDuration[i];

               minn = min({minn, total1, total2});
            }
        }

        return minn;
    }
};
