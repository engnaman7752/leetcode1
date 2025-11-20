class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        
        int start = -1, last = -1;
        int ans = 0;
        
        for(int i = 0; i < intervals.size(); i++){
            int l = intervals[i][0], r = intervals[i][1];
            bool flag1 = (start >= l && start <= r);
            bool flag2 = (last >= l && last <= r);          
            if(flag1 && flag2) continue;           
            if(!flag1 && !flag2){
                ans += 2;
                last = r;
                start = r - 1;
            } 
            else {
                ans += 1;
                start = last;
                last = r;
            }
        }
        
        return ans;
    }
};
