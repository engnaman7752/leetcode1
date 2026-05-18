class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        vector<int>dis(n,INT_MAX);
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        dis[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [d,index]=pq.top();
            pq.pop();
            if(d>dis[index])continue;
            if(index+1<n && dis[index+1]>d+1){
                pq.push({d+1,index+1});
                dis[index+1]=d+1;
            }
            if(index-1>=0 && dis[index-1]>d+1){
                pq.push({d+1,index-1});
                dis[index-1]=d+1;
            }
            for(auto i:mp[arr[index]]){
                if(i!=index && dis[i]>d+1){
                    pq.push({d+1,i});
                    dis[i]=d+1;
                }
            }
            mp.erase(arr[index]);
        }
        return dis[n-1];
    }
};