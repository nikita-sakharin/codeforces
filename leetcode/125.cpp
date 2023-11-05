class Solution final {
private:
    static inline const locale utf8{"C.UTF-8"};

public:
    constexpr bool isPalindrome(const string &s) const noexcept {
        ptrdiff_t i{0}, j{static_cast<ptrdiff_t>(s.size()) - 1};
        while (i < j) {
            const auto left{s[i]}, right{s[j]};
            if (!isalnum(left, utf8))
                ++i;
            else if (!isalnum(right, utf8))
                --j;
            else if (tolower(left, utf8) == tolower(right, utf8)) {
                ++i;
                --j;
            } else
                return false;
        }
        return true;
    }
};
