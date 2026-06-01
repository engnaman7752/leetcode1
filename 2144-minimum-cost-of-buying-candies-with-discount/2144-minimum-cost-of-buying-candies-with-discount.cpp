class Solution {
public:
    int minimumCost(vector<int>& cost) {
       sort(cost.begin(),cost.end());
       int n=cost.size();
       if(n==1)return cost[0];
       if(n==2)return cost[0]+cost[1];
       int ans=0;
       for(int i=n-1;i>=0;){
        ans+=cost[i];
        i--;
        if(i>=0){ans+=cost[i];i-=2;}
       }
       return ans; 
    }
};