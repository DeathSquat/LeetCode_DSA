class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        
        // For maximum: Replace the first digit that is not 9 with 9
        string maxS = s;
        for (char& ch : maxS) {
            if (ch != '9') {
                char target = ch;
                for (char& c : maxS) {
                    if (c == target) c = '9';
                }
                break;
            }
        }

        // For minimum: Replace the first digit that is not 0 with 0
        string minS = s;
        for (char& ch : minS) {
            if (ch != '0') {
                char target = ch;
                for (char& c : minS) {
                    if (c == target) c = '0';
                }
                break;
            }
        }

        int maxVal = stoi(maxS);
        int minVal = stoi(minS);

        return maxVal - minVal;
    }
};
