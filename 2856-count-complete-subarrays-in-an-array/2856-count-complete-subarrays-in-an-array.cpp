class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        set<int>st;
        int count=0;
        for(int i=0;i<n;i++)
        st.insert(nums[i]);
        
        for(int i=0;i<n;i++)
        {
            set<int>s;
           for(int j=i;j<n;j++)
           { s.insert(nums[j]);
            if(s.size()==st.size())
           { count++;}
           }
        }
        return count;
    }
};