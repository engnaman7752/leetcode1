class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Your code here
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
           adj[prerequisites[i][0]].push_back(prerequisites[i][1]) ;
        }
        vector<int>indegree(adj.size(),false);
        
        for(int i=0;i<adj.size();i++)
        {for(int j=0;j<adj[i].size();j++)
           indegree[adj[i][j]]++;
        }
        int count=0;
        queue<int>q;
       for(int i=0;i<indegree.size();i++)
       {
           if(indegree[i]==0)
           q.push(i);
       }
       while(!q.empty())
       {
           int node=q.front();
           count++;
           q.pop();
           for(auto it:adj[node])
           {
               indegree[it]--;
               if(indegree[it]==0)
               q.push(it);
           }
       }
       cout<<count;
        return count==numCourses; 
    }
};