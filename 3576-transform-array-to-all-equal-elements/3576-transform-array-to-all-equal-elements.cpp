class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        vector<int>temp=nums;
        int neg=0;int pos=0; 
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==1){
                neg++;
                nums[i+1]=-nums[i+1];
            }
        }
        for(int i=0;i<n-1;i++){
            if(temp[i]==-1){
                pos++;
                temp[i+1]=-temp[i+1];
            }
        }
        if(nums[n-1]==1)neg=k+1;
        if(temp[n-1]==-1)pos=k+1;
        return pos<=k||neg<=k;
    }
};