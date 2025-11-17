class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>a;
        for(int i=0;i<n;i++){
            if(nums[i])a.push_back(i);
        }
        for(int i=1;i<a.size();i++){
                if(a[i]-a[i-1]+1<k+2)return 0;
        }
        return 1;
    }
};