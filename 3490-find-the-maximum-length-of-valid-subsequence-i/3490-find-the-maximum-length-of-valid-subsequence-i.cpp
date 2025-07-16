class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int even=0;
        int odd=0;
        int both=0;
        int parity=-1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even++;
                if(parity==-1||parity==1)both++;
            }
            else
            {
                odd++;
                if(parity==-1||parity==0)both++;
            }
            parity=nums[i]%2;
        }
        return max(max(odd,even),both);
    }
    
};