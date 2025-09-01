class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double,int,int>> pq;

        for (auto &e : classes) {
            double g = (double)(e[0] + 1) / (e[1] + 1) - (double)e[0] / e[1];
            pq.push({g, e[0], e[1]});
        }

        while (extraStudents--) {
            auto [a, b, c] = pq.top(); 
            pq.pop();
            b++; c++;
            double g = (double)(b + 1) / (c + 1) - (double)b / c;
            pq.push({g, b, c});
        }

        double ans = 0;
        while (!pq.empty()) {
            auto [a, b, c] = pq.top();
            pq.pop();
            ans += (double)b / c; 
        }

        return ans / classes.size();
    }
};
