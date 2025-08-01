class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int start=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int count=0;
        while(!pq.empty()){
            count++;
            while(!pq.empty()&&pq.top()<=start)pq.pop();
           start= pq.top();
        }
return count-1;
    }
};