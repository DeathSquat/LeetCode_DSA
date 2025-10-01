class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrank = numBottles;   // Initially drink all bottles
        int empty = numBottles;        // Empty bottles after drinking

        // Keep exchanging while possible
        while (empty >= numExchange) {
            int newFull = empty / numExchange;      // Number of full bottles we get
            totalDrank += newFull;                  // Drink them
            empty = empty % numExchange + newFull;  // Update remaining empty bottles
        }

        return totalDrank;
    }
};
