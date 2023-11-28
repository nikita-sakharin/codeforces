class Solution final {
private:
    static constexpr int countSubarray(
        const unordered_map<int, int> &numMap,
        const int num,
        const int k
    ) noexcept {
        auto result{0};
        if (num == k)
            ++result;
        if (const auto iter{numMap.find(num + k)}; iter != numMap.cend())
            result += iter->second;
        return result;
    }

    static inline void deleteNum(
        unordered_map<int, int> &numMap,
        const int num
    ) noexcept {
        const auto iter{numMap.find(num)};
        --iter->second;
        if (iter->second <= 0)
            numMap.erase(iter);
    }

public:
    inline int subarraySum(
        vector<int> &nums,
        const int k
    ) const noexcept {
        const auto size{nums.size()};
        unordered_map<int, int> numMap{{nums[0], 1}};
        for (size_t i{1}; i < size; ++i) {
            nums[i] += nums[i - 1];
            ++numMap[nums[i]];
        }

        auto result{0};
        for (const auto &num : nums) {
            deleteNum(numMap, num);
            result += countSubarray(numMap, num, k);
        }
        return result;
    }
};
