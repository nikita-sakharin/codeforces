class Solution final {
private:
    static constexpr size_t letters_count{26};

    static constexpr size_t ord(const char ch) noexcept {
        return ch >= 'a' ? ch - 'a' + 26 : ch - 'A';
    }

public:
    constexpr int longestPalindrome(const string &s) noexcept {
        array<size_t, letters_count << 1> count{};
        for (const auto ch : s)
            ++count[ord(ch)];

        size_t result{0};
        bool odd{false};
        for (const auto c : count) {
            result += c & ~1UZ;
            odd = odd | (c & 1);
        }

        return int(result) + odd;
    }
};
