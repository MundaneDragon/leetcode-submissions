class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto longestPrefix = std::string{};

        for (auto i = 0; i < strs[0].size(); i++) {
            for (auto const& text : strs) {
                if (i <= text.size() && text[i] != strs[0][i]) {
                    return longestPrefix;
                }
            }
            longestPrefix.push_back(strs[0][i]); 
        }
        
        return longestPrefix;
    }
};