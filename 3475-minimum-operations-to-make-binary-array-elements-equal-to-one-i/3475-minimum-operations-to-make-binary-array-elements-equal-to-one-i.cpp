class Solution {
   void swap(vector<int>& nums,int start,int end)
    {
        for(int i=start;i<=end;i++)
        {
            if(nums[i]==0)
            nums[i]=1;
            else
            nums[i]=0;
        }
       
    }
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0&&i+2<n)
            {swap(nums,i,i+2);
            ans++;}
            if(nums[i]==0&&i+2>=n)
            return -1;

            
        }
        return ans;
    }
};