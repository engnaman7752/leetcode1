class Solution {
public:
    int xsum(unordered_map<int,int> &map, int x){
        priority_queue<pair<int,int>> pq;
        for(auto e : map) pq.push({e.second,e.first});
        int sum = 0;
        while(x-- && !pq.empty()){
            sum += (pq.top().second * pq.top().first);
            pq.pop();
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n-k+1);
        int l = 0, r;
        unordered_map<int,int> map;
        for(r = 0; r < k; r++){
            map[nums[r]]++;
        }
        ans[l] = xsum(map,x);

        for(r = k; r < n; r++){
            map[nums[l]]--;
            if(map[nums[l]] == 0) map.erase(nums[l]);
            map[nums[r]]++;
            ans[++l] = xsum(map,x);
        }

        return ans;
    }
};