class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int t = (n / 2) + 1;

        map<int, int> m;
        int no = -1;

        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }

        for (auto it : m) {
            if (it.second * 2 > n) { 
                no = it.first;
                break;
            }
        }

        if (no == -1) return -1; 

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == no)
                count++;

            if (count * 2 > (i + 1) && (m[no] - count) * 2 > (n - i - 1))
                return i;
        }

        return -1; 
    }
};
