class Solution {
public:
    int lengthOfLastWord(string s) {
        
        auto len = 0;
        auto last_word_len = 0;
        for (auto letter : s) {

            if (std::isalpha(letter)) {
                len++;
            } else {
                if (len != 0) {
                    last_word_len = len;
                }
                len = 0;
            }
        }

        if (len > 0) {
            return len;
        }
        
        return last_word_len;
    }
};