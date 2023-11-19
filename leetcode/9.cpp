class Solution final {
public:
    constexpr bool isPalindrome(const int x) const noexcept {
        if (x < 0)
            return false;

        array<char, numeric_limits<decltype(x)>::digits10 + 1> str{};
        const auto size{to_chars(str.begin(), str.end(), x).ptr - str.begin()},
            lastIndex{size - 1}, half{size >> 1};
        for (ptrdiff_t i{0}; i < half; ++i)
            if (str[i] != str[lastIndex - i])
                return false;
        return true;
    }
};
