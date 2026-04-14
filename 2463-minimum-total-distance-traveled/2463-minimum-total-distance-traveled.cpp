class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // 2. Flatten the factory into individual slots for easier indexing
        vector<int> factorySlots;
        for (auto& f : factory) {
            int position = f[0];
            int limit = f[1];
            for (int i = 0; i < limit; ++i) {
                factorySlots.push_back(position);
            }
        }

        int n = robot.size();
        int m = factorySlots.size();
        
        vector<vector<long long>> memo(n, vector<long long>(m, -1));

        return solve(0, 0, robot, factorySlots, memo);
    }

private:
    long long solve(int rIdx, int sIdx, vector<int>& robot, vector<int>& slots, vector<vector<long long>>& memo) {
       
        if (rIdx == robot.size()) return 0;
        if (sIdx == slots.size()) return 1e15; 

        if (memo[rIdx][sIdx] != -1) return memo[rIdx][sIdx];
        long long skip = solve(rIdx, sIdx + 1, robot, slots, memo);
        long long take = abs(robot[rIdx] - slots[sIdx]) + solve(rIdx + 1, sIdx + 1, robot, slots, memo);

        return memo[rIdx][sIdx] = min(skip, take);
    }
};