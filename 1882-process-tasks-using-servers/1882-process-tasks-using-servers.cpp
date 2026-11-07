class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> free;
        priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> busy;
        
        for(int i = 0; i < servers.size(); i++){
            free.push({servers[i], i});
        }
        
        long long time = 0;
        vector<int> ans;
        
        for(int i = 0; i < tasks.size(); i++){
            time = max(time, (long long)i);
            
            while(!busy.empty() && busy.top().first <= time){
                free.push(busy.top().second);
                busy.pop();
            }
            
            if(free.empty()){
                time = busy.top().first;
                while(!busy.empty() && busy.top().first <= time){
                    free.push(busy.top().second);
                    busy.pop();
                }
            }
            
            auto best_server = free.top();
            ans.push_back(best_server.second);
            free.pop();
            
            busy.push({time + tasks[i], best_server});
        }
        
        return ans;
    }
};