class Solution final {
private:
    template<class Iter>
    using Difference = iterator_traits<Iter>::difference_type;

    template<class Iter, class T>
    static constexpr pair<Iter, Difference<Iter>> adjacentCount(
        const Iter first,
        const Iter last,
        const T &value
    ) noexcept {
        const auto iter{find(first, last, value)};
        return {iter, distance(first, iter)};
    }

public:
    constexpr int longestSubarray(const vector<int> &nums) const noexcept {
        const auto numsEnd{cend(nums)};
        auto [iter, lastCnt] = adjacentCount(cbegin(nums), numsEnd, 0);
        auto result{lastCnt - (iter == numsEnd)};
        while (iter != numsEnd) {
            ptrdiff_t zeroCnt{0}, oneCnt{0};
            tie(iter, zeroCnt) = adjacentCount(iter, numsEnd, 1);
            tie(iter, oneCnt) = adjacentCount(iter, numsEnd, 0);
            result = max(result, (zeroCnt == 1 ? lastCnt : 0) + oneCnt);
            lastCnt = oneCnt;
        }
        return int(result);
    }
};
