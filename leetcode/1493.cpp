class Solution final {
public:
    constexpr int longestSubarray(const vector<int> &nums) const noexcept {
        const auto numsEnd{nums.cend()};
        size_t result{0}, lastCnt{0};
        for (auto iter{nums.cbegin()}; iter != numsEnd; ) {
            const auto zeroCnt{find(iter, numsEnd, 1) - iter};
            iter += zeroCnt;
            const auto oneCnt{find(iter, numsEnd, 0) - iter};
            iter += oneCnt;
            if (zeroCnt == 0)
                result = oneCnt - 1;
            else if (zeroCnt == 1)
                result = max(result, lastCnt + oneCnt);
            lastCnt = oneCnt;
        }
        return static_cast<int>(result);
    }
};
