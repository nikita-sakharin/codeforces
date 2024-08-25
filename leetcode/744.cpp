class Solution final {
public:
    constexpr char nextGreatestLetter(
        const vector<char> &letters,
        const char target
    ) const noexcept {
        const auto first{cbegin(letters)}, last{cend(letters)},
            iter{upper_bound(first, last, target)};
        return iter == last ? *first : *iter;
    }
};
