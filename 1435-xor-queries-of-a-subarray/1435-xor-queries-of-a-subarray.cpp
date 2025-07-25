class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>xorr(arr.size()+1);
        int value=0;
        xorr[0]=0;
        for(int i=1;i<arr.size()+1;i++){
            value^=arr[i-1];
            xorr[i]=value;
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(xorr[queries[i][1]+1]^xorr[queries[i][0]]);
        }
        return ans;
    }
};