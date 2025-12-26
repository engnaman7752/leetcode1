class Solution {
public:
    int bestClosingTime(string customers) {
        int totalYES=count(customers.begin(),customers.end(),'Y');
        int totalNO=count(customers.begin(),customers.end(),'N');
        int y=0;
        int n=0;
        int index=-1;int ans=totalYES;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y')y++;
            else n++;
            if(totalYES-y+n<ans){
                ans=totalYES-y+n;
                index=i;
            }
        }
        return index+1;
    }
};