class Solution final {
public:
    constexpr int longestSubarray(const vector<int> &nums) const noexcept {
        const auto numsBegin{nums.begin()}, numsEnd{nums.cend()};
        auto iter{find(numsBegin, numsEnd, 0)};
        auto lastCnt{iter - numsBegin}, result{lastCnt - (iter == numsEnd)};
        while (iter != numsEnd) {
            const auto zeroCnt{find(iter, numsEnd, 1) - iter};
            iter += zeroCnt;
            const auto oneCnt{find(iter, numsEnd, 0) - iter};
            iter += oneCnt;
            result = max(result, zeroCnt == 1 ? lastCnt + oneCnt : oneCnt);
            lastCnt = oneCnt;
        }
        return int(result);
    }
};
