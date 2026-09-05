class Solution {
public:
    int lengthOfLastWord(string s) {
        auto len = 0;

        for (auto i = static_cast<int>(s.size()) - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                len++;
            } else if (len > 0) {
                return len;
            }
        }

        return len;
    }
};