class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int num1,num2;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(count1==0 && num2!=nums[i]){
                num1=nums[i];
            }
            if(count2==0 && num1!=nums[i]){
                num2=nums[i];
            }
            if(num1==nums[i])count1++;
            else if(num2==nums[i])count2++;
            else{
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int i=0;i<n;i++){
            if(num1==nums[i])count1++;
            if(num2==nums[i])count2++;
        }
        if(count1*3<=n && count2*3<=n)return {};
        if(count1*3<=n)return {num2};
        if(count2*3<=n)return {num1};
        return {num1,num2};
    }
};