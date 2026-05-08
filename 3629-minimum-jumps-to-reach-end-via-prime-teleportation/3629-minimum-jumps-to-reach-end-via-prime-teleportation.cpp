class Solution {
    vector<bool> isPrime;

    void sieve(int m) {
        isPrime.assign(m + 1, true);
        if (m >= 0) isPrime[0] = false;
        if (m >= 1) isPrime[1] = false;
        for (int i = 2; i * i <= m; ++i) 
            if (isPrime[i]) 
                for (int j = i * i; j <= m; j += i) 
                    isPrime[j] = false;
    }

public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int maxVal = 0;
        for (int v : nums) if (v > maxVal) maxVal = v;
        sieve(maxVal);
        vector<vector<int>> mp(maxVal + 1);
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        
        queue<pair<int,int>> pq;
        pq.push({0, 0});
        
        vector<int> vis(n, 0);
        vis[0] = 1;
        
        while(!pq.empty()){
            auto [i, dist] = pq.front();
            pq.pop();
            
            if(i == n - 1) return dist;
            if(i > 0 && !vis[i - 1]){
                vis[i - 1] = 1;
                pq.push({i - 1, dist + 1});
            }
            
            if(i + 1 < n && !vis[i + 1]){ 
                vis[i + 1] = 1;
                pq.push({i + 1, dist + 1});
            }
            if(isPrime[nums[i]]){
                isPrime[nums[i]] = false; 
                
                for(int j = nums[i]; j <= maxVal; j += nums[i]){
                    for(auto index : mp[j]){
             
                        if(!vis[index]){ 
                            vis[index] = 1;
                            pq.push({index, dist + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};