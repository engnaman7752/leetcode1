class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int initial_zeros = 0;
        for (char c : s) if (c == '0') initial_zeros++;
        if (initial_zeros == 0) return 0;
        vector<int> dist(n + 1, -1);
        queue<int> q;
        dist[initial_zeros] = 0;
        q.push(initial_zeros);
        set<int> unvisited[2]; 
        for (int i = 0; i <= n; i++) {
            unvisited[i % 2].insert(i);
        }
        unvisited[initial_zeros % 2].erase(initial_zeros);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            int min_i = max(0, k - (n - curr));
            int max_i = min(curr, k);        
            int L = curr + k - 2 * max_i;
            int R = curr + k - 2 * min_i;
            int parity = L % 2;
            auto it = unvisited[parity].lower_bound(L);
            while (it != unvisited[parity].end() && *it <= R) {
                int next_zeros = *it;
                if (next_zeros == 0) return dist[curr] + 1;
                
                dist[next_zeros] = dist[curr] + 1;
                q.push(next_zeros);
                it = unvisited[parity].erase(it); 
            }
        }

        return -1;
    }
};