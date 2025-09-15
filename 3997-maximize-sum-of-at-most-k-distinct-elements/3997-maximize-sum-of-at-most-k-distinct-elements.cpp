class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
     sort(nums.begin(),nums.end())  ;
        set<int>st;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(st.size()<k)st.insert(nums[i]);
            else break;
        }
        vector<int>ans(st.begin(),st.end());
        reverse(ans.begin(),ans.end());
        return ans;
    }
};