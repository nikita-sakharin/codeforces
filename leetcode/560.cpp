class Solution final {
public:
    inline int subarraySum(
        vector<int> &nums,
        const int k
    ) const noexcept {
        const auto size{static_cast<int>(nums.size())};
        unordered_map<int, int> numMap{{nums[0], 1}};
        for (auto i{1}; i < size; ++i) {
            nums[i] += nums[i - 1];
            ++numMap[nums[i]];
        }

        auto result{0};
        const auto end{numMap.cend()};
        for (auto i{0}; i < size; ++i) {
            const auto num{nums[i]};
            if (num == k)
                ++result;

            const auto iter{numMap.find(num)};
            --iter->second;
            if (iter->second <= 0)
                numMap.erase(iter);

            if (const auto iter{numMap.find(k + num)}; iter != end)
                result += iter->second;
        }
        return result;
    }
};
