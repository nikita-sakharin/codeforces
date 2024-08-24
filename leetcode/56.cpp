class Solution final {
public:
    constexpr vector<vector<int>> merge(
        vector<vector<int>> &intervals
    ) const noexcept {
        const auto last{intervals.end()};
        auto slow{intervals.begin()};
        sort(slow, last);

        for (auto fast{next(slow)}; fast != last; ++fast) {
            auto &slowRight{(*slow)[1]};
            const auto &fastValue{*fast};
            if (slowRight >= fastValue[0])
                slowRight = max(slowRight, fastValue[1]);
            else if (++slow != fast)
                iter_swap(slow, fast);
        }
        intervals.resize(size_t(distance(intervals.begin(), slow)) + 1);

        return move(intervals);
    }
};
