class Solution final {
private:
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
    constexpr int findMaxConsecutiveOnes(
        const vector<int> &nums
    ) const noexcept {
        const auto numsEnd{nums.cend()};
        auto iter{nums.cbegin()};
        ptrdiff_t result{0}, lastCnt{0};
        while (iter != numsEnd) {
            ptrdiff_t zeroCnt{0}, oneCnt{0};
            tie(iter, zeroCnt) = adjacentCount(iter, numsEnd, 1);
            tie(iter, oneCnt) = adjacentCount(iter, numsEnd, 0);
            result = max(result, oneCnt + 1 + (zeroCnt == 1 ? lastCnt : 0));
            lastCnt = oneCnt;
        }
        return int(result);
    }
};
