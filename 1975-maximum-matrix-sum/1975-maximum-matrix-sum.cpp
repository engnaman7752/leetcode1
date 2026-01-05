class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int cnt=0;
        int minimum=INT_MAX;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                minimum=min(abs(matrix[i][j]),minimum);
                if(matrix[i][j]<0)cnt++;
                sum+=abs(matrix[i][j]);
            }
        }
        if(cnt%2){
            return sum-2*minimum;
        }
        else return sum;
    }
};