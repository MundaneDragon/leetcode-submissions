class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        auto lower = 2;
        auto upper = x / 2;

        while (lower <= upper) {
            auto mid = lower + (upper - lower) / 2;
            
            // Only 1 division per iteration
            if (mid <= x / mid) {
                lower = mid + 1;
            } else {
                upper = mid - 1;
            }
        }

        return upper;
    }
};