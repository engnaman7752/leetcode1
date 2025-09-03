class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) 
                return a[1] > b[1];  
            else 
                return a[0] < b[0];  
        });

        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x=points[i][0];
            int y=INT_MIN; int ymax=points[i][1];
            for (int j = i + 1; j < n; j++) {
                int y1=points[j][1];
                if(y1<=ymax&&y1>y){
                    ans++; y=max(y,y1);
                }
                    
                }
            }
        
        return ans;
    }
};