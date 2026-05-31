class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperature){
        int n=temperature.size();
        vector<int>nge(n);
        stack<int>st;
        st.push(n-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperature[i]>=temperature[st.top()]){
                st.pop();
            }
             if(st.empty()){
                nge[i]=i;
                st.push(i);
            }
            else{
                nge[i]=st.top();
                st.push(i);
            }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=nge[i]-i;
        }
        return ans;

    }
};