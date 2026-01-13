class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        long long totalArea = 0;

        for (auto &s : squares)
            totalArea += 1LL * s[2] * s[2];

        // sort by bottom y
        sort(squares.begin(), squares.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });

        double currArea = 0;
        double activeWidth = 0;
        double prevY = squares[0][1];
        vector<pair<int,int>> ends;
        for (auto &s : squares)
            ends.push_back({s[1] + s[2], s[2]});
        sort(ends.begin(), ends.end());

        int i = 0, j = 0;

        while (i < n || j < n) {
            double y;
            if (j == n || (i < n && squares[i][1] <= ends[j].first)) {
                y = squares[i][1];
            } else {
                y = ends[j].first;
            }

            double height = y - prevY;
            if (height > 0) {
                double area = activeWidth * height;
                if (2 * (currArea + area) >= totalArea) {
                    return prevY +
                        (totalArea / 2.0 - currArea) / activeWidth;
                }
                currArea += area;
                prevY = y;
            }
            while (i < n && squares[i][1] == y) {
                activeWidth += squares[i][2];
                i++;
            }
            while (j < n && ends[j].first == y) {
                activeWidth -= ends[j].second;
                j++;
            }
        }
        return 0.0;
    }
};
