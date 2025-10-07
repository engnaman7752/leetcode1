class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        map<int, int> mp;
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            queue<int> s;
            if (rains[i] == 0) {
                pq.push(i);
            } 
            else {   
                ans[i] = -1; 
                if (mp.find(rains[i]) != mp.end()) {
                    while (!pq.empty() && pq.top() < mp[rains[i]]) {
                        s.push(pq.top());
                        pq.pop();  
                    }
                    if (pq.empty()) return {};  
                    else {
                        ans[pq.top()] = rains[i];  
                        pq.pop();
                        while (!s.empty()) {
                            pq.push(s.front());
                            s.pop();
                        }
                    }
                }
                mp[rains[i]] = i;
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]==0)ans[i]=1;
        }
        return ans;
    }
};
