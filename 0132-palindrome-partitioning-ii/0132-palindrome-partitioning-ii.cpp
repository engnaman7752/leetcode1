class Solution {
public:
bool ispal(int i,int j,string &s){
   while(i<j){
    if(s[i]!=s[j])return false;
        i++;
        j--;
   }
   return true;
}
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return solve(0,s,dp)-1;
    }
    int solve(int index,string & s,vector<int>& dp){
        int n=s.size();
        if(index==n)return 0;
        if(dp[index]!=-1)return dp[index];
        int minCost=INT_MAX;
        for(int i=index;i<n;i++){
            int cost;
            if(ispal(index,i,s)){
                cost=1+solve(i+1,s,dp);}
                minCost=min(cost,minCost);

            

        }
        return dp[index]=minCost;
    }
};