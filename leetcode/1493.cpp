class Solution final {
private:
    template<class InputIt, class T>
    static constexpr pair<InputIt, ptrdiff_t> adjacent_count(
        const InputIt first, const InputIt last,
        const T &value
    ) noexcept {
        const auto iter{find(first, last, value)};
        return {iter, iter - first};
    }

public:
    constexpr int longestSubarray(const vector<int> &nums) const noexcept {
        const auto numsEnd{nums.cend()};
        auto [iter, lastCnt] = adjacent_count(nums.cbegin(), numsEnd, 0);
        auto result{lastCnt - (iter == numsEnd)};
        while (iter != numsEnd) {
            ptrdiff_t zeroCnt, oneCnt;
            tie(iter, zeroCnt) = adjacent_count(iter, numsEnd, 1);
            tie(iter, oneCnt) = adjacent_count(iter, numsEnd, 0);
            result = max(result, zeroCnt == 1 ? lastCnt + oneCnt : oneCnt);
            lastCnt = oneCnt;
        }
        return int(result);
    }
};
