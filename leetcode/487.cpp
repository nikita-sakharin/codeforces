class Solution final {
private:
    template<class InputIter, class T>
    static constexpr pair<InputIter, ptrdiff_t> adjacent_count(
        const InputIter first, const InputIter last,
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
        auto iter = nums.cbegin();
        ptrdiff_t result{}, lastCnt{};
        while (iter != numsEnd) {
            ptrdiff_t zeroCnt{}, oneCnt{};
            tie(iter, zeroCnt) = adjacent_count(iter, numsEnd, 1);
            tie(iter, oneCnt) = adjacent_count(iter, numsEnd, 0);
            result = max(result, oneCnt + 1 + (zeroCnt == 1 ? lastCnt : 0));
            lastCnt = oneCnt;
        }
        return int(result);
    }
};
