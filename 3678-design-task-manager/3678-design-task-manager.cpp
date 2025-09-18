class TaskManager {
public:
map<int,pair<int,int>>mp;
priority_queue<tuple<int,int,int>>p;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto t:tasks){
            int userId=t[0];
            int taskId=t[1];
            int priority=t[2];
            mp[taskId]={priority,userId};
            p.push({priority,taskId,userId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
         mp[taskId]={priority,userId};
         p.push({priority,taskId,userId});
    }
    
    void edit(int taskId, int newPriority) {
         auto [b,c]=mp[taskId];
          mp[taskId]={newPriority,c};
          p.push({newPriority,taskId,c});
    }
    
    void rmv(int taskId) {
        mp.erase(taskId);
    }
    
    int execTop() {
        while(!p.empty()){
            auto [a,b,c]=p.top();
            p.pop();
            auto it=mp.find(b);
            if(it==mp.end()) continue;
            auto [s,r]=it->second;
            if(s==a&&r==c){
                mp.erase(it);
                return r;
            }
        }
        return -1;
    }
};
