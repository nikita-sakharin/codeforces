class Solution final {
public:
    constexpr void reverseString(vector<char> &s) const noexcept {
        for (size_t i{0}, j{s.size() - 1}; i < j; ++i, --j)
            swap(s[i], s[j]);
    }
};
