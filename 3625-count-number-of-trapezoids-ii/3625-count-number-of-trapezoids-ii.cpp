class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        float INF = 1e9 + 7;

        unordered_map<float, vector<float>> slopeToIntercept;
        unordered_map<long long, vector<float>> midToSlope;   

        int ans = 0;

        for (int i = 0; i < n; i++) {
            float x1 = points[i][0];
            float y1 = points[i][1];

            for (int j = i + 1; j < n; j++) {
                float x2 = points[j][0];
                float y2 = points[j][1];

                float dx = x1 - x2;
                float dy = y1 - y2;

                float k, b;

                if (x1 == x2) {
                    k = INF;
                    b = x1;        
                }
                else {
                    k = dy / dx;
                    b = (y1 * dx - x1 * dy) / dx;
                }

                long long mx = (long long)(x1 + x2);
                long long my = (long long)(y1 + y2);
                long long mid = (mx << 32) ^ (my & 0xffffffff);

                slopeToIntercept[k].push_back(b);
                midToSlope[mid].push_back(k);
            }
        }
        for (auto &p : slopeToIntercept) {
            auto &sti = p.second;
            if (sti.size() <= 1) continue;

            map<float, int> cnt;

            for (float b : sti)
                cnt[b]++;

            int sum = 0;
            for (auto &q : cnt) {
                int c = q.second;
                ans += sum * c;
                sum += c;
            }
        }
        for (auto &p : midToSlope) {
            auto &mts = p.second;
            if (mts.size() <= 1) continue;
            map<float, int> cnt;
            for (float k : mts)
                cnt[k]++;
            int sum = 0;
            for (auto &q : cnt) {
                int c = q.second;
                ans -= sum * c;
                sum += c;
            }
        }
        return ans;
    }
};
