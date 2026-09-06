class Solution {
public:
    int mySqrt(int x) {
        auto num = static_cast<unsigned int>(1);
        while ((num * num <= x)) {
            num++;
        }

        return num-1;
    }
};