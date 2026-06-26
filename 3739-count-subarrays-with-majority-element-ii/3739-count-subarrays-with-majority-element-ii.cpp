#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        bool found = false;
        for(int x : nums) {
            if(x == target) { found = true; break; }
        }
        if(!found) return 0;

        long long ans = 0;
        ordered_set st;
        int current_pref = 0;
   
        st.insert({0, -1}); 
        
        for(int i = 0; i < n; i++) {
            current_pref += (nums[i] == target) ? 1 : -1;
            
            // order_of_key finds the count of elements strictly smaller than {current_pref, -infinity}
            // This is exactly the lower_bound distance you were trying to calculate!
            int total_smaller = st.order_of_key({current_pref, -1});
            ans += total_smaller;
            
            // Insert the current prefix sum with its index to handle duplicates uniquely
            st.insert({current_pref, i}); 
        }
        
        return ans;
    }
};