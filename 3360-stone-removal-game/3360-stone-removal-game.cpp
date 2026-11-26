class Solution {
public:
    bool canAliceWin(int n) {
        int curr=10;
        bool flag=false;
        while(n>=curr){
            n-=curr;
            curr--;
            flag=!flag;
        }
        return flag;
    }
};