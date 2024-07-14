class Solution final {
private:
    static constexpr size_t lettersCount{26};

    static constexpr size_t order(const char ch) noexcept {
        return ch >= 'a' ? ch - 'a' + lettersCount : ch - 'A';
    }

public:
    constexpr int longestPalindrome(const string &s) const noexcept {
        array<size_t, lettersCount << 1> count{};
        for (const auto ch : s)
            ++count[order(ch)];

        auto result{0UZ};
        auto odd{false};
        for (const auto c : count) {
            result += c & ~1UZ;
            odd = odd | (c & 1);
        }

        return int(result) + odd;
    }
};
