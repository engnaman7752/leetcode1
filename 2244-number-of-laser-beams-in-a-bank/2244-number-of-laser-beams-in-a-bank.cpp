class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int ans=0;
        int pre=-1;
        for(int i=0;i<n;i++){
            int laser=count(bank[i].begin(),bank[i].end(),'1');
            if(laser>0)
          {  if(pre==-1){
                pre=laser;
            }
            else{
                ans+=pre*laser;
                pre=laser;
            }
            }
        }
        return ans;
    }
};