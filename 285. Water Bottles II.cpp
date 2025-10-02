class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int full = numBottles;
        int empty = 0;
        int drunk = 0;
        
        while (full > 0) {
            // Drink all full bottles
            drunk += full;
            empty += full;
            full = 0;
            
            // Try exchanging if possible
            if (empty >= numExchange) {
                empty -= numExchange;
                full += 1;
                numExchange++;  // cost increases after each exchange
            }
        }
        
        return drunk;
    }
};
