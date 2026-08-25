class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>st(nums.begin(),nums.end());
        int t=k;
        while(true){
            if(st.find(k)==st.end())return k;
            k+=t;
        }
        return 0;
    }
};