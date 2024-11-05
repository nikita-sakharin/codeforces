class Solution final {
public:
    constexpr int maxSubArray(const vector<int> &nums) const noexcept {
        auto sum{0}, result{numeric_limits<int>::min()};
        for (const auto num : nums) {
            sum += num;
            result = max(result, sum);
            sum = max(0, sum);
        }

        return result;
    }
};
