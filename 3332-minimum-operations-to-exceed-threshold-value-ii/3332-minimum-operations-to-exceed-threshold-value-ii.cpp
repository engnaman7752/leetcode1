class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
       priority_queue <long long, vector<long long>, greater<long long>> pq;
       for(int i=0;i<n;i++)
       {
        pq.push(nums[i]);
       }
       int count=0;
       while(pq.top()<k&&pq.size()>=2)
       {
        long long x=pq.top();
        pq.pop();
        long long y=pq.top();
        pq.pop();
        pq.push(min(x, y) * 2 + max(x, y));
        count++;
       }
       if(pq.top()<k)
       return -1;
       else
       return count;
    }
};