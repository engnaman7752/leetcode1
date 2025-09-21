class Solution {
public:
    bool lemonadeChange(vector<int>& bill) {
        int five=0;
        int ten=0;
        int twenty=0;
        for(int i=0;i<bill.size();i++){
           if(bill[i]==5){
            five++;
           }
           if(bill[i]==10){
            if(five>0)five--;
            else return false;
            ten++;
           }
           if(bill[i]==20){
            if(ten>0&&five>0){
                ten--;
               five--;
            }
            else if(five>2){
                five-=3;
            }
            else{
                return false;
            }
            twenty++;
           }
        }
        return true;
    }
};