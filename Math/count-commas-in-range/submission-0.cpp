class Solution {
public:
    int countCommas(int n) {
        auto numComma = 0;
        auto threshold = 1000;

        while (n >= threshold) {
            numComma += n - threshold + 1;
            threshold = threshold * 1000;
        }
        
        return numComma;
    }
};