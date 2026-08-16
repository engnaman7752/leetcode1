class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
        vector<int>mod(3,0);
        for(int i=0;i<n;i++){
            mod[stones[i]%3]++;
        }
        if(mod[0]%2==0){
            return mod[1]>=1 && mod[2]>=1;
        }
        else 
        return abs(mod[1]-mod[2])>2;

    }
};