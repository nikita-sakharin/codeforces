class Solution final {
public:
    constexpr int maxSubArray(const vector<int> &nums) const noexcept {
        auto sum{0}, result{numeric_limits<int>::min()};
        for (const auto num : nums) {
            sum = max(num, sum + num);
            result = max(result, sum);
        }

        return result;
    }
};
