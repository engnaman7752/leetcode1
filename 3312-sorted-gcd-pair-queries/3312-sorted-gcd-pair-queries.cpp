class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n=nums.size();
        int m=*max_element(nums.begin(),nums.end());
        vector<long long>cnt(m+1,0);
        for(int i=0;i<n;i++){
            cnt[nums[i]]++;
        }
        for(int i=1;i<=m;i++){
            for(int j=2*i;j<=m;j+=i){
                cnt[i]+=cnt[j];
            }
        }
        for(int i=1;i<=m;i++){
            cnt[i]=(cnt[i]*(cnt[i]-1))/2;
        }
        for(int i=m;i>=1;i--){
            for(int j=2*i;j<=m;j+=i){
                cnt[i]-=cnt[j];
            }
        }
        for(int i=1;i<=m;i++){
            cnt[i]+=cnt[i-1];
        }
        vector<int>a;
        for(auto q:queries){
            q++;
            int ans=lower_bound(cnt.begin(),cnt.end(),q)-cnt.begin();
            a.push_back(ans);

        }
        return a;
    }
};