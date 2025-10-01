class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total=numBottles;
        int empty=numBottles;
        while(empty>=numExchange)
        {total=empty/numExchange+total;
        empty=empty/numExchange+empty%numExchange;}
        return total;
    }
};