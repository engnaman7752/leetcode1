class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
           adj[prerequisites[i][1]].push_back(prerequisites[i][0]) ;
        }
        vector<int>indegree(adj.size(),false);
        
        for(int i=0;i<adj.size();i++)
        {for(int j=0;j<adj[i].size();j++)
           indegree[adj[i][j]]++;
        }
        vector<int>ans;
        queue<int>q;
       for(int i=0;i<indegree.size();i++)
       {
           if(indegree[i]==0)
           q.push(i);
       }
       while(!q.empty())
       {
           int node=q.front();
           ans.push_back(node);
           q.pop();
           for(auto it:adj[node])
           {
               indegree[it]--;
               if(indegree[it]==0)
               q.push(it);
           }
       }
       if(numCourses==ans.size())
       return ans;
       else
       {
        ans.clear();
        return ans;
       }
        
    }
};