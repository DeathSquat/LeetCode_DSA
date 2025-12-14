class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD = 1e9 + 7;
        long long ways = 1;
        int seats = 0;
        int plants = 0;
        bool countingPlants = false;

        for (char c : corridor) {
            if (c == 'S') {
                seats++;
                if (seats % 2 == 0) {
                    countingPlants = true;
                } else if (seats > 2) {
                    ways = (ways * (plants + 1)) % MOD;
                    plants = 0;
                    countingPlants = false;
                }
            } else if (countingPlants) {
                plants++;
            }
        }

        return (seats > 0 && seats % 2 == 0) ? ways : 0;
    }
};
