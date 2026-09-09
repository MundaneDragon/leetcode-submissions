class Solution {
public:
    long long countCommas(long long n) {
        auto threshold = static_cast<long long>(1000);
        auto count = static_cast<long long>(0);
        while (n >= threshold) {
            count += n - threshold + 1;
            threshold = threshold * 1000;
        }

        return count;
    }
};