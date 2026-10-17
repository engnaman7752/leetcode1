class Solution {
public:
static int digitSum(int num){
    int sum=0;
    while(num>0){
        sum+=num%10;
        num=num/10;
    }
    return sum;
}
static bool cmp(int a,int b){
    if(digitSum(a)!=digitSum(b))return digitSum(a)<digitSum(b);
    return a<b;
}
    int minSwaps(vector<int>& nums) {
        vector<int>t=nums;
        int n=nums.size();
        sort(t.begin(),t.end(),cmp);
         vector<bool>vis(n,0);
         unordered_map<int,int>mp;
         for(int i=0;i<n;i++){
            mp[t[i]]=i;
         }
         int ans=0;
         for(int i=0;i<n;i++){
            if(vis[i] || mp[nums[i]]==i)continue;
            int j=i;
            int cycle=0;
            while(!vis[j]){
                vis[j]=true;
                j=mp[nums[j]];
                cycle++;
            }
            if(cycle>1)
            ans+=cycle-1;
         }
         return ans;
    }
   
};