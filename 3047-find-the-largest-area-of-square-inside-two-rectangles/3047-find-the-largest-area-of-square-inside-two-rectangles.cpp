class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& arr, vector<vector<int>>& brr) {
        int n = arr.size();
        long long ans = 0;
        for(int i = 0; i < n; i++){
            int x = arr[i][0], y = arr[i][1];
            int a = brr[i][0], b = brr[i][1];
            for(int j = i + 1; j < n; j++){
                int xl = arr[j][0], yl = arr[j][1];
                int al = brr[j][0], bl = brr[j][1];
                if(min(a, al) > max(x, xl) && min(b, bl) > max(y, yl)){
                    long long side = min(
                        min(a, al) - max(x, xl),
                        min(b, bl) - max(y, yl)
                    );
                    ans = max(ans, side * side);
                }
            }
        }
        return ans;
    }
};
