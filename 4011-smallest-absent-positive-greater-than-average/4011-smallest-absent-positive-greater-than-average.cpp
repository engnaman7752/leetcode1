class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        double avg = (double)sum / nums.size();
        vector<bool>pos(200,false);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
            pos[nums[i]-1]=true;
        }
        for(int i=0;i<pos.size();i++){
            if(pos[i]==false&&(i+1)>avg)return i+1;
        }
        
        return -1;
    }
};