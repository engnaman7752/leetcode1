class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty=0;
        int full=numBottles;
        int total=0;
        while(full+empty>=numExchange){
            while(empty>=numExchange){
                full+=1;
                empty-=numExchange;
                numExchange++;
            }
            total+=full;
            empty+=full;
            full=0;
        }
        total+=full;
        return total;
    }
};