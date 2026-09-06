class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        auto lower = static_cast<unsigned int>(2);
        auto upper = static_cast<unsigned int>(x / 2);
        while (lower <= upper) {
            auto mid = static_cast<unsigned int>( lower + ((upper - lower)/ 2));

            if (mid > (x / mid)) {
                upper = mid -1;
            } else if (mid == (x / mid)) {
                return mid;
            } else {
                lower = mid + 1;
            }
        }

        return upper;
    }
};