class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        while(s<e){
            for(int i=0;i<n-1;i++){
                swap(nums[s][i],nums[i][e]);
            }
            swap(nums[s][s],nums[e][e]);
            swap(nums[s][s],nums[e][s]);
            for(int i=1;i<n-1;i++){
                swap(nums[s][i],nums[e][n-i-1]);
            }
             for(int i=1;i<n-1;i++){
                swap(nums[s][i],nums[i][s]);
            }
            s++;
            e--;
        }
    }
};