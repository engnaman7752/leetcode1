class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int n=nums.size();
        int start=nums[0];
        for(int i=0;i<n;){
           if(nums[i]==start){
            i++;
           } 
           else{
            ans.push_back(start);
           }
           start++;
        }
        return ans;
    }
};