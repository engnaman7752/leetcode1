class Solution {
    vector<int>bfs(vector<int>& edges, int node1)
    {
        vector<int>dis(edges.size(),INT_MAX);
        vector<bool>vis(edges.size(),false);
        queue<int>q;
        q.push(node1);
        dis[node1]=0;
        while(!q.empty())
        {
            int node=q.front();
            vis[node]=true;
            q.pop();
            if(edges[node]!=-1&&!vis[edges[node]])
           { dis[edges[node]]=dis[node]+1;
            q.push(edges[node]);}
        }
        return dis;

    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int>dis1=bfs(edges,node1);
        vector<int>dis2=bfs(edges,node2);
        int ans=-1;
        int dis=INT_MAX;
        for(int i=0;i<edges.size();i++)
        {
            if (dis1[i] != INT_MAX && dis2[i] != INT_MAX) {
        int maxDis = max(dis1[i], dis2[i]);
        if (maxDis < dis) {
        dis = maxDis;
        ans = i;}}

        }
return ans;
        }
};