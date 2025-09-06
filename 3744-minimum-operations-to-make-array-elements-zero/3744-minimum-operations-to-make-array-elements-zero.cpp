class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        vector<long long> p(17);
        p[0] = 1;
        for (int i = 1; i < 17; i++) p[i] = p[i - 1] * 4;

        vector<long long> diff(17);
        for (int i = 1; i < 17; i++) diff[i] = p[i] - p[i - 1];

        long long ans = 0;
        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            int i = 0; while (i < 17 && p[i] <= l) i++;          
            int j = 16; while (j >= 0 && p[j] > r) j--;           

            long long steps = 0;
            if (i == j + 1) {                                   
                steps = (r - l + 1) * i;
            } else {
                steps += (p[i] - l) * i;                         
                for (int t = i + 1; t <= j; t++) steps += diff[t] * t; 
                steps += (r - p[j] + 1) * (j + 1);                
            }

            ans += (steps + 1) / 2;                              
        }
        return ans;
    }
};
