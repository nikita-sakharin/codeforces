class Solution final {
public:
    constexpr vector<vector<int>> merge(
        vector<vector<int>> &intervals
    ) const noexcept {
        const auto last{intervals.end()};
        auto left{intervals.begin()};
        sort(left, last);

        for (auto right{next(left)}; right != last; ++right) {
            auto &leftValue{*left};
            const auto &rightValue{*right};
            if (leftValue[1] >= rightValue[0])
                leftValue[1] = max(leftValue[1], rightValue[1]);
            else if (++left != right)
                iter_swap(left, right);
        }
        intervals.resize(size_t(distance(intervals.begin(), left)) + 1);

        return move(intervals);
    }
};
