class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        int sum=0;int maxx=0;
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       for(auto e:events){
         while (pq.size() && pq.top().first < e[0]) {
                maxx = max(maxx, pq.top().second);
                pq.pop();
            }

            sum = max(sum, maxx + e[2]);
            pq.push({e[1], e[2]});
        }

        return sum;
       }
};