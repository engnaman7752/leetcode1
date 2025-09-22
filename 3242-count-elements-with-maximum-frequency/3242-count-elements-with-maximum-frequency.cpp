class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq=0;
        int n=nums.size();
        map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>maxFreq)maxFreq=freq[nums[i]];
        }
        int count=0;
        for(auto [num,fre]:freq){
            if(fre==maxFreq)count+=fre;
        }
        return count;
    }
};