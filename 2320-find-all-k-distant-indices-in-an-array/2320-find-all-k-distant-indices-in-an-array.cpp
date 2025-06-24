class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {bool flag=false;
            for(int j=i;j<n&&j<=i+k;j++)
            {
                if(nums[j]==key)
                {ans.push_back(i);
                flag=true;
                break;}
            }
            if(!flag)
             {for(int j=i;j>=0&&j>=i-k;j--)
            {
                if(nums[j]==key)
                {ans.push_back(i);
                break;}
            }}

        }
        return ans;
    }
};