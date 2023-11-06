class Solution final {
public:
    inline int subarraySum(
        vector<int> &nums,
        const int k
    ) const noexcept {
        const auto size{static_cast<int>(nums.size())};
        unordered_map<int, vector<int>> numMap;
        for (auto i{1}; i < size; ++i) {
            nums[i] += nums[i - 1];
            numMap[nums[i]].push_back(i);
        }
        auto result{0};
        const auto end{numMap.cend()};
        for (auto i{0}; i < size; ++i) {
            const auto num{nums[i]};
            if (num == k)
                ++result;
            if (const auto iter{numMap.find(k + num)}; iter != end) {
                const auto &pos{iter->second};
                result += pos.cend() - upper_bound(pos.cbegin(), pos.cend(), i);
            }
        }
        return result;
    }
};
