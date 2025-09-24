class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string result;
        
        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) result += "-";
        
        // Convert to long long to prevent overflow
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);
        
        // Append integer part
        result += to_string(n / d);
        long long remainder = n % d;
        if (remainder == 0) return result; // No fractional part
        
        result += ".";
        
        // Store seen remainders and their positions in result string
        unordered_map<long long, int> seen;
        
        while (remainder) {
            if (seen.find(remainder) != seen.end()) {
                // Insert '(' at the position of first occurrence
                result.insert(seen[remainder], "(");
                result += ")";
                break;
            }
            
            seen[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / d);
            remainder %= d;
        }
        
        return result;
    }
};
