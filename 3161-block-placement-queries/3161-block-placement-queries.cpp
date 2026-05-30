class Solution {
    vector<int> tree;
    
    // Segment Tree function to update the gap ending at index 'idx'
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
    
    // Segment Tree function to get the max gap in the range [L, R]
    int query(int node, int start, int end, int L, int R) {
        if (R < start || L > end || L > R) return 0; // Out of bounds
        if (L <= start && end <= R) return tree[node]; // Completely inside bounds
        
        int mid = start + (end - start) / 2;
        return max(query(2 * node, start, mid, L, R), 
                   query(2 * node + 1, mid + 1, end, L, R));
    }
    
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        // Find the maximum possible coordinate to size our segment tree correctly
        int max_x = 0;
        for (const auto& q : queries) max_x = max(max_x, q[1]);
        max_x++; 
        
        // Initialize Segment tree with 0s (size needs to be 4 * N)
        tree.assign(4 * max_x, 0);
        
        set<int> obs;
        obs.insert(0); // Origin boundary
        vector<bool> ans;
        
        for (const auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                if (obs.count(x)) continue; // Skip if obstacle already exists
                
                // Find the obstacle right before x
                auto it = obs.upper_bound(x);
                int left_bound = *prev(it);
                
                // The new gap ending at x is (x - left_bound)
                update(1, 0, max_x - 1, x, x - left_bound);
                
                // If there's an obstacle AFTER x, its gap shrinks
                if (it != obs.end()) {
                    int right_bound = *it;
                    update(1, 0, max_x - 1, right_bound, right_bound - x);
                }
                
                obs.insert(x); // Finally, add x to the set
                
            } else {
                int x = q[1];
                int sz = q[2];
                
                // Find the largest obstacle P that is <= x
                int P = *prev(obs.upper_bound(x));
                
                // Get the largest historical gap up to obstacle P
                int max_gap = query(1, 0, max_x - 1, 0, P);
                
                // We also have to check the final gap between P and our query limit x
                max_gap = max(max_gap, x - P);
                
                // If our biggest gap is at least the size needed, it fits!
                ans.push_back(max_gap >= sz);
            }
        }
        return ans;
    }
};