class Solution final {
private:
    using uint = unsigned;

public:
    inline bool isPalindrome(const int x) const noexcept {
        if (x < 0)
            return false;

        const auto str = to_string(x);
        const auto lastIndex{str.size() - 1}, half{str.size() >> 1};
        for (size_t i{0}; i < half; ++i)
            if (str[i] != str[lastIndex - i])
                return false;
        return true;
    }
};
