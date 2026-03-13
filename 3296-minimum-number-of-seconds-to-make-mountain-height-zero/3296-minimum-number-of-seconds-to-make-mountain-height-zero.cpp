class Solution {
public:
    long long minNumberOfSeconds(int x, vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        vector<int>count(n,1);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(x>0){
            auto [num,index]=pq.top();
            pq.pop();
            x--;
            ans=num;
            count[index]++;
            pq.push({num+1LL*nums[index]*count[index],index});
        }
        return ans;
    }
};