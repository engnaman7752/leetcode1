class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count=0;
        long long sum=0;
       int j=0;
            for(int i=0;i<nums.size();i++)
            { sum=sum+nums[i];
               while(j<=i&&sum*(i-j+1)>=k)
              { sum=sum-nums[j];
               j++;}
                count=count+(i-j+1);

            }

        return count;
    }
};