class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(),queries.end());
        priority_queue<int>available;
        priority_queue<int,vector<int>,greater<int>>used;
        int count=0;
        int x=0;
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=nums[i]-used.size();

            while(x<queries.size()&&queries[x][0]==i)
            {
                available.push(queries[x][1]);
                x++;
            }
            while(!available.empty()&&available.top()>=i&&nums[i]>0)
            {
                used.push(available.top());
                available.pop();
                count++;
                nums[i]=nums[i]-1;
            }
            if(nums[i]>0)
            return -1;
            while(!used.empty()&&used.top()==i)
            used.pop();
        }
        return queries.size()-count;
        
    }
};