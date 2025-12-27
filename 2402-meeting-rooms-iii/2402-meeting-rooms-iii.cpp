class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        map<int, int> mp;
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> p;
        for (int i = 0; i < n; i++) p.push(i);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        for (int i = 0; i < meetings.size(); i++) {
            long long start = meetings[i][0];
            long long end = meetings[i][1];

            while (!pq.empty() && pq.top().first <= start) {
                p.push(pq.top().second);
                pq.pop();
            }

            if (p.empty()) {
                auto [available, room] = pq.top(); pq.pop();
                long long duration = end - start;
                pq.push({available + duration, room});
                mp[room]++;
            } else {
                int room = p.top(); p.pop();
                pq.push({end, room});
                mp[room]++;
            }
        }

        int ans = 0;
        int room = -1;
        for (auto it : mp) {
            if (ans < it.second) {
                room = it.first;
                ans = it.second;
            }
        }

        return room;
    }
};
