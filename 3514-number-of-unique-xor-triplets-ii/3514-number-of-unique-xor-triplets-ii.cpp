class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxx=*max_element(nums.begin(),nums.end());
        int num=1;
        while(num<=maxx){
            num=num<<1;
        }
        vector<int>t(num,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                t[nums[i]^nums[j]]=1;
            }
        }
        vector<int>f(num,0);
        for(int i=0;i<num;i++){
            if(t[i]==1){
                for(auto it:nums){
                    f[it^i]=1;
                }
            }
        }
        return count(f.begin(),f.end(),1);
    }
};