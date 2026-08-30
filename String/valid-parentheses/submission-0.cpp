#include <stack>

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }

  auto pile = std::stack<char>{};
        auto charMap = std::unordered_map<char, char>{{'(', ')'}, {'[', ']'}, {'{', '}'}};

        for (auto i = 0; i < s.size(); i++) {
            // Check if s[i] is an opening bracket (exists as a key in charMap)
            if (charMap.count(s[i])) {
                pile.push(s[i]);
            } else {
                // It's a closing bracket: check for empty stack or mismatch
                if (pile.empty() || charMap[pile.top()] != s[i]) {
                    return false;
                }
                pile.pop();
            }
        }

        return pile.empty();
    }
};