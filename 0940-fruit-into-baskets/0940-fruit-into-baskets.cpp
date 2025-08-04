class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int type1=fruits[0];
        int type2=-1;
        int left=0;
        int right=0;
        int sum=0;
        int ans=0;
        map<int,int>mp;
        while(right<n){
            if(fruits[right]==type1||fruits[right]==type2||type2==-1)
           {
            if(fruits[right]==type1)
           mp[type1]=right;
           else if(fruits[right]==type2)
           mp[type2]=right;
           else if(type2==-1)
           {type2=fruits[right];
           mp[type2]=right;}
           sum=(right-left+1);
           ans=max(ans,sum);
           right++;
           }
           else{
            if(mp[type1]>mp[type2])
            left=mp[type2]+1;
            else
            {left=mp[type1]+1;
            type1=type2;}
            type2=fruits[right];
           }

        }
        return ans;
        
    }
};