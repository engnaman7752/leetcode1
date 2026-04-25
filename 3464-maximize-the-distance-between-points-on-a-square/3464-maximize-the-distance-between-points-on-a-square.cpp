class Solution {
public:
    long long getDist(int x, int y, int side) {
        if (y == 0) return x;                   // Bottom edge
        if (x == side) return side + y;         // Right edge
        if (y == side) return 2LL * side + (side - x); // Top edge
        return 3LL * side + (side - y);         // Left edge
    }

    bool possible(int mid, vector<long long>& pos, int k, long long totalPerim) {
        int n = pos.size();
        for (int start = 0; start < n; ++start) {
            if (pos[start] > pos[0] + mid) break; 

            int cnt = 1;
            long long lastPos = pos[start];
            for (int i = start + 1; i < n; ++i) {
                if (pos[i] - lastPos >= mid) {
                    cnt++;
                    lastPos = pos[i];
                    if (cnt == k) break;
                }
            }

            if (cnt == k && (totalPerim - lastPos + pos[start] >= mid)) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> pos;
        for (auto& p : points) {
            pos.push_back(getDist(p[0], p[1], side));
        }
        sort(pos.begin(), pos.end());

        long long totalPerim = 4LL * side;
        int start = 0, end = side;
        int ans = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (possible(mid, pos, k, totalPerim)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};