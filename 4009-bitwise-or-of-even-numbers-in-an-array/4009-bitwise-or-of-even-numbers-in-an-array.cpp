class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int val=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                val|=nums[i];
            }
        }
        return val;
    }
};