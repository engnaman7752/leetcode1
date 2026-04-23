class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map<int,vector<long long>>mp;
        int n=nums.size();
        vector<long long>ans(n);
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto [num,vec]:mp){
             int m=vec.size();
            if(m==1){
                ans[vec[0]]=0;
                continue;
            }
            vector<long long>pre(m);
            pre[0]=vec[0];
            for(int i=1;i<m;i++){
                pre[i]=pre[i-1]+vec[i];
            }
            for(int i=0;i<m;i++){
                long long right=(pre[m-1]-pre[i])-(vec[i]*(m-1-i));
                long long left=(i*vec[i])-(i==0?0:pre[i-1]);
                ans[vec[i]]=right+left;
            }
        }
        return ans;
    }
};