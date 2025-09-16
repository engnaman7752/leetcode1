class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>st;
        st.push(nums[0]);
        int n=nums.size();
        for(int i=1;i<n;i++){
            int x=nums[i];
            while(!st.empty()&&gcd(x,st.top())>1){
               x=lcm(x,st.top());
               st.pop();
            }
           st.push(x);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};