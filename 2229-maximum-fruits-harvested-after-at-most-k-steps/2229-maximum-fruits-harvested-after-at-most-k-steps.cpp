class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& nums, int startPos, int k) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i][0]]=nums[i][1];
        }
        int left=startPos-k;
        if(left<0)
        left=0;
        int end=startPos+k;
        int right=left;
        int ans=0;
        int sum=0;
       while (right <= end) {
        int step=0;
            if(left<startPos&&right>startPos){
                if(right-startPos<startPos-left)
                step=2*(right-startPos)+(startPos-left);
                else
                step=(right-startPos)+2*(startPos-left);
            }
             else if(left<startPos){
                step=startPos-left;
             }
             else if(right>=startPos){
                step=startPos-right;
             }
            if(step<=k){
                 sum = sum + mp[right]; 
                right++;
                ans = max(ans, sum);
            }
            else{
                sum = sum - mp[left];  
                left++;
            }



        }
        return ans;
        
    }
};