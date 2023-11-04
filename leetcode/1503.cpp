class Solution final {
public:
    constexpr int getLastMoment(
        const int n,
        const vector<int> &left,
        const vector<int> &right
    ) const noexcept {
        auto result(0);
        if (!left.empty())
            result = *max_element(left.cbegin(), left.cend());
        if (!right.empty())
            result = max(result, n - *min_element(right.cbegin(), right.cend()));
        return result;
    }
};
