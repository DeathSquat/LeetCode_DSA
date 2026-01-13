class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 0.0, high = 1e9;
        
        auto diff = [&](double y) {
            double below = 0.0, above = 0.0;
            
            for (auto& s : squares) {
                double y0 = s[1];
                double l = s[2];
                double y1 = y0 + l;
                double area = l * l;
                
                if (y <= y0) {
                    above += area;
                } else if (y >= y1) {
                    below += area;
                } else {
                    double below_h = y - y0;
                    double above_h = y1 - y;
                    below += below_h * l;
                    above += above_h * l;
                }
            }
            return below - above;
        };
        
        // Binary search for y where diff(y) = 0
        for (int i = 0; i < 80; i++) { // sufficient precision
            double mid = (low + high) / 2.0;
            if (diff(mid) < 0)
                low = mid;
            else
                high = mid;
        }
        
        return low;
    }
};
