class Solution final {
public:
    inline vector<int> twoSum(
        const vector<int> &nums,
        const int target
    ) const noexcept {
        const auto size{nums.size()};
        unordered_map<int, size_t> numMap{};
        const auto end{numMap.cend()};
        for (auto i{0UZ}; i < size; ++i) {
            if (const auto iter{numMap.find(target - nums[i])}; iter != end)
                return {int(iter->second), int(i)};
            numMap[nums[i]] = i;
        }
        return {};
    }
};
