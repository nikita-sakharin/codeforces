class Solution final {
private:
    static inline const locale &classic{locale::classic()};

public:
    constexpr bool isPalindrome(const string &s) const noexcept {
        ptrdiff_t i{0}, j{ptrdiff_t(s.size()) - 1};
        while (i < j) {
            const auto left{s[size_t(i)]}, right{s[size_t(j)]};
            if (!isalnum(left, classic))
                ++i;
            else if (!isalnum(right, classic))
                --j;
            else if (tolower(left, classic) == tolower(right, classic)) {
                ++i;
                --j;
            } else
                return false;
        }
        return true;
    }
};
