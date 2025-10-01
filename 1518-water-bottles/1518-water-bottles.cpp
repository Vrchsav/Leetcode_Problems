class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total=numBottles;
        int empty=numBottles;
        numBottles=0;
        while (empty>=numExchange){
            numBottles=empty/numExchange;
            empty=empty%numExchange;
            total+=numBottles;
            empty+=numBottles;
            numBottles=0;

        }
        return total;
    }
};