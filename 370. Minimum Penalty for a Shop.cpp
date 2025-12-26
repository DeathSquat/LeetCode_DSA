class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        
        // Initial penalty: shop closes at hour 0 (all 'Y' are missed)
        int penalty = 0;
        for (char c : customers) {
            if (c == 'Y') penalty++;
        }
        
        int minPenalty = penalty;
        int bestHour = 0;
        
        // Try closing at each hour from 1 to n
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y') {
                penalty--;  // served a customer
            } else {
                penalty++;  // open but no customer
            }
            
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i + 1;
            }
        }
        
        return bestHour;
    }
};
