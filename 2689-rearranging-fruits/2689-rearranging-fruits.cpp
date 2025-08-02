class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int>mp1;
        map<int,int>mp2;
        int n=basket1.size();
        for(int i=0;i<n;i++){
            mp1[basket1[i]]++;
            mp2[basket2[i]]++;
        }
        vector<long long>cost;
        for(auto it:mp1){
            int x=mp2[it.first]+it.second;
           if((x)%2==1)
           return -1;
           int y=it.second;
            while(y>x/2)
           { cost.push_back(it.first);
            y--;}
        }
          for(auto it:mp2){
            int x=mp1[it.first]+it.second;
           if((x)%2==1)
           return -1;
           int y=it.second;
            while(y>x/2)
           { cost.push_back(it.first);
           y--;}
        }
        sort(cost.begin(),cost.end());
        long long ans=0;
        int minn1=*min_element(basket1.begin(),basket1.end());
        int minn2=*min_element(basket2.begin(),basket2.end());
        int minn=min(minn1,minn2);
        for(int i=0;i<cost.size()/2;i++){
            if(cost[i]<=2*minn)
            ans+=cost[i];
            else
            ans+=2*minn;}
       return ans;
        
    }
};