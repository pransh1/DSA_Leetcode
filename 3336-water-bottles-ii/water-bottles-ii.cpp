class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drinking = numBottles;
        int empty = numBottles;
        while(empty >= numExchange) {
            drinking += 1;
            empty++;
            empty -= numExchange;
            numExchange++;
        }
        return drinking;
    }
};