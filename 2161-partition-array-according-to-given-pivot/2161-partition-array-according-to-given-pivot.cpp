class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>less;
        vector<int>more;
        int cnt=0;
        for(int i :nums){
            if(i==pivot)cnt++;
            else if(i>pivot)more.push_back(i);
            else less.push_back(i);
        }
        int index=0;
        for(int i=0;i<less.size();i++){
            nums[index]=less[i];
            index++;
        }
        while(cnt){
            nums[index]=pivot;
            cnt--;
            index++;
        }
        for(int i=0;i<more.size();i++){
            nums[index]=more[i];
            index++;
        }
        return nums;
    }
};