class Solution final {
public:
    constexpr void reverseString(vector<char> &str) const noexcept {
        auto first{begin(str)}, last{--end(str)};
        while (first < last)
            iter_swap(first++, last--);
    }
};
