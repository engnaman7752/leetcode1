class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>s;
        int sum=0;
        int negative=-110;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i])==s.end()&&nums[i]>0){
                sum=sum+nums[i];
            }
             if(s.find(nums[i])==s.end()&&nums[i]<=0){
                negative=max(negative,nums[i]);
            }
             s.insert(nums[i]);
        }
        if(sum==0)return negative;
        return sum;
        
    }
};