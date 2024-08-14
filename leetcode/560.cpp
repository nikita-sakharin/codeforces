class Solution final {
private:
    static constexpr size_t countSubarray(
        const unordered_map<int, size_t> &numMap,
        const int num,
        const int k
    ) noexcept {
        auto result{0UZ};
        if (num == k)
            ++result;
        if (const auto iter{numMap.find(num + k)}; iter != numMap.cend())
            result += iter->second;
        return result;
    }

    static inline void deleteNum(
        unordered_map<int, size_t> &numMap,
        const int num
    ) noexcept {
        const auto iter{numMap.find(num)};
        --iter->second;
        if (iter->second == 0)
            numMap.erase(iter);
    }

public:
    inline int subarraySum(
        vector<int> &nums,
        const int k
    ) const noexcept {
        const auto size{nums.size()};
        unordered_map<int, size_t> numMap{{nums[0], 1}};
        for (auto i{1UZ}; i < size; ++i) {
            nums[i] += nums[i - 1];
            ++numMap[nums[i]];
        }

        auto result{0UZ};
        for (const auto num : nums) {
            deleteNum(numMap, num);
            result += countSubarray(numMap, num, k);
        }
        return int(result);
    }
};
