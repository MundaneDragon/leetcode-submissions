class Solution {
public:
    string intToRoman(int num) {
        constexpr auto valToRoman = std::array{
            std::pair{1000, std::string_view{"M"}},
            std::pair{900,  std::string_view{"CM"}},
            std::pair{500,  std::string_view{"D"}},
            std::pair{400,  std::string_view{"CD"}},
            std::pair{100,  std::string_view{"C"}},
            std::pair{90,   std::string_view{"XC"}},
            std::pair{50,   std::string_view{"L"}},
            std::pair{40,   std::string_view{"XL"}},
            std::pair{10,   std::string_view{"X"}},
            std::pair{9,    std::string_view{"IX"}},
            std::pair{5,    std::string_view{"V"}},
            std::pair{4,    std::string_view{"IV"}},
            std::pair{1,    std::string_view{"I"}},
        };

        auto result = std::string{};

        for (const auto& [value, symbol] : valToRoman) {
            while (num >= value) {
                result.append(symbol);
                num -= value;
            }
        }

        return result;
    }
};