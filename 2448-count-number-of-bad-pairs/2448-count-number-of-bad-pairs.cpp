class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<long long,long long>m;
        long long n=nums.size();
        long long count=0;
        for(int i=0;i<n;i++)
        {
            count= count+ m[nums[i] - i]; 
            m[nums[i] - i]++;
        }
        long long ans=n*(n-1)/2;
        
        
        return ans-count;
    
    }
};