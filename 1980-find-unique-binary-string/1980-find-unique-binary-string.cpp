class Solution {
public:

    string decToBinary(int n, int len) {
        string bin = "";
        while (n > 0) {
            int bit = n & 1;
            bin.push_back('0' + bit);
            n = n >> 1;
        }

        while (bin.size() < len) bin.push_back('0');

        reverse(bin.begin(), bin.end());
        return bin;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        int last = 1 << n;
        set<string> st(nums.begin(), nums.end());
        for (int i = 0; i < last; i++) {
            string t = decToBinary(i, n);
            if (st.find(t) == st.end()) return t;
        }
        return "";
    }
};