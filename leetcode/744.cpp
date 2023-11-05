class Solution final {
public:
    constexpr char nextGreatestLetter(
        const vector<char> &letters,
        const char target
    ) const noexcept {
        const auto begin{letters.cbegin()}, end{letters.cend()},
            iter{upper_bound(begin, end, target)};
        return iter == end ? *begin : *iter;
    }
};
