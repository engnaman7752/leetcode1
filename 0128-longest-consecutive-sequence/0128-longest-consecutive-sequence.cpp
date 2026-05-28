class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        int cur=0;
        int pre=-5;
        set<int>st(nums.begin(),nums.end());
        for(int i:st){
            if(i-1 == pre){
                cur++;
            }
            else{
                cur=1;
            }
            pre=i;
            ans=max(ans,cur);
        }
        return ans;
    }
};