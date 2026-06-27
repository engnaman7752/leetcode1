class Solution {
public: 
    int maximumLength(vector<int>& nums) {
        map<long long, int> mp; 
        sort(nums.begin(), nums.end()); 
        
        for(int i : nums){
            mp[i]++; 
        } 
        
        if(mp[1] % 2 == 0) mp[1]--; 
        int ans = max(1, mp[1]); 
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1 || (i > 0 && nums[i-1] == nums[i])) continue; 
            
            int cnt = 0; 
            long long num = nums[i]; 
            
            while(num <= 1000000000 && mp[num] >= 2){
                num = num * num; 
                cnt += 2; 
            } 
            
            if(mp[num] == 0) cnt--; 
            else cnt++; 
            
            ans = max(ans, cnt); 
        } 
        
        return ans; 
    } 
};