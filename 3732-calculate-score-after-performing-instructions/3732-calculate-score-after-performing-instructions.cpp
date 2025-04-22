class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long score = 0;
        int i = 0;
        vector<bool> vis(instructions.size(), false);

        while(i >= 0 && i < instructions.size() && !vis[i]) {
            vis[i] = true;

            if(instructions[i] == "add") {
                score += values[i];
                i++;
            } else {
                i += values[i];
            }
        }

        return score;
    }
};
