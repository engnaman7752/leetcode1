class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;int n=nums.size();
        int start=0;
        for(int i=0;i<n;i++){
            int num=nums[i];
            while(num>0){
                ans.push_back(num%10);
                num=num/10;
            }
            reverse(ans.begin()+start,ans.end());
            start=ans.size();
        }
        return ans;
    }
};