class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> mp;
        for (int i = 0; i < answers.size(); i++) {
            mp[answers[i]]++;  // ✅ Use answers[i], not i
        }

        int ans = 0;
        for (auto it : mp) {
            int groupSize = it.first + 1;
            int count = it.second;
            if (count % groupSize == 0) {
                ans += groupSize * (count / groupSize);
            } else {
                ans += groupSize * ((count / groupSize) + 1);
            }
        }

        return ans;
    }
};
