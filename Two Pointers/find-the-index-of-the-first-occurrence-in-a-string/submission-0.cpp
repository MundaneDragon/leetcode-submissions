class Solution {
public:
    int strStr(string haystack, string needle) {
        auto first = haystack.find(needle);
        return (first != string::npos) ? static_cast<int>(first) : -1;
    }
};