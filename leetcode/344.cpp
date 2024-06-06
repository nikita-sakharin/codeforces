class Solution final {
public:
    constexpr void reverseString(vector<char> &s) const noexcept {
        const auto size{s.size()}, half{size >> 1};
        for (size_t i{0}; i < half; ++i)
            swap(s[i], s[size - i - 1]);
    }
};
