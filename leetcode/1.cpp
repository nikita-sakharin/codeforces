class Solution final {
public:
    inline vector<int> twoSum(
        const vector<int> &nums,
        const int target
    ) const {
        const auto size{static_cast<int>(nums.size())};
        unordered_map<int, int> numMap;
        for (auto i{0}; i < size; ++i)
            numMap[nums[i]] = i;
        const auto end{numMap.cend()};
        for (auto i{0}; i < size; ++i)
            if (const auto iter{numMap.find(target - nums[i])};
                iter != end && iter->second != i
            )
                return {i, iter->second};
        return {};
    }
};
