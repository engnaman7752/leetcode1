class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++){
                if(j-1!=i && nums[j]==nums[j-1])continue;
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum=1LL*nums[i]+1LL*nums[j]+1LL*nums[k]+1LL*nums[l];
                    int preL=nums[l];
                    int preK=nums[k];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(l>k&&nums[l]==preL)
                        l--;
                        while(l>k&&nums[k]==preK)
                        k++;
                    }
                    if(sum<target){
                        while(l>k&&nums[k]==preK)
                        k++;
                    }
                    if(sum>target){
                        while(l>k && nums[l]==preL)
                        l--;
                    }

                }
            }
        }
        return ans;
    }
};