class DetectSquares {
    map<vector<int>,int>mp;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[point]++;
        
    }
    
    int count(vector<int> point) {
        int ans=0;
        int x1=point[0];
        int y1=point[1];
        for(auto it:mp){
            int x2=it.first[0];
            int y2=it.first[1];
            if (x1 == x2 || y1 == y2 || abs(x1 - x2) != abs(y1 - y2)) continue;
                ans=ans+it.second * mp[{x1,y2}] * mp[{x2,y1}];
            
        }
return ans;
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */