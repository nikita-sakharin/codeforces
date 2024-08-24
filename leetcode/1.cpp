class Solution final {
public:
    inline vector<int> twoSum(
        const vector<int> &nums,
        const int target
    ) const noexcept {
        const auto length{size(nums)};
        unordered_map<int, size_t> index{};
        const auto last{cend(index)};
        for (auto i{0UZ}; i < length; ++i) {
            if (const auto iter{index.find(target - nums[i])}; iter != last)
                return {int(iter->second), int(i)};
            index[nums[i]] = i;
        }
        return {};
    }
};
