class Solution {
public:
    int area(vector<int>& nums){
        int n = nums.size();
        vector<int> nse(n, -1), pse(n, -1);
        stack<int> st;
        int maxAr = 0;

        // Next smaller element
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Previous smaller element
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            if(!st.empty()) pse[i] = st.top();
            st.push(i);
        }

        // Max area
        for(int i = 0; i < n; i++){
            int left = pse[i] == -1 ? 0 : pse[i] + 1;
            int right = nse[i] == -1 ? n : nse[i];
            maxAr = max(maxAr, (right - left) * nums[i]);
        }
        return maxAr;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
         int n = mat.size(), m = mat[0].size();
        vector<int> height(m, 0);
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] != '0') height[j] += 1;
                else height[j] = 0;
            }
            ans = max(ans, area(height));
        }

        return ans;
    
    }
};