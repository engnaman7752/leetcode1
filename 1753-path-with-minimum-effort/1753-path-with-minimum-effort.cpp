class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>diff(n,vector<int>(m,INT_MAX));
        diff[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<int>row{0,-1,0,1};
        vector<int>col{-1,0,1,0};
        while(!pq.empty())
        {
            int node_diff=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            for(int l=0;l<4;l++)
            {   
                int new_row=i+row[l];
                int new_col=j+col[l];
                if(new_row>=0&&new_row<n&&new_col>=0&&new_col<m)
                {int differ=abs(heights[i][j]-heights[new_row][new_col]);
                    if(diff[new_row][new_col]>max(differ,node_diff))
                    {diff[new_row][new_col]=max(differ,node_diff);
                    pq.push({max(differ,node_diff),{new_row,new_col}});}
                }

            }
        }
        return diff[n-1][m-1];
    }
};