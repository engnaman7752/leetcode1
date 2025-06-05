class Solution {
public:
bool solve(int i,long long mul,long long target,vector<int>& nums)
{
    if(target==mul) return true;
    if(target<mul) return false;
    if(i==nums.size()) return false;
    if(solve(i+1,mul*nums[i],target,nums))return true;
    if(solve(i+1,mul,target,nums))return true;
    return false;


}
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        double mul = 1;
        for(int i = 0; i < nums.size(); i++) {
            mul = mul * nums[i];
        }
        double root = sqrt(mul);
        if(root!=target) return false;
        return solve(0,1,target,nums);
    }
};
