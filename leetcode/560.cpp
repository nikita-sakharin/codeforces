class Solution final {
private:
    template<class C>
    using Key = C::key_type;

    template<class C>
    using Mapped = C::mapped_type;

    template<class C>
    static constexpr Mapped<C> getOrDefault(
        const C &container,
        const Key<C> &key,
        const Mapped<C> &mapped
    ) noexcept {
        if (const auto iter{container.find(key)}; iter != container.cend())
            return iter->second;
        return mapped;
    }

    static inline void deleteElement(
        unordered_map<int, size_t> &countMap,
        const int key
    ) noexcept {
        const auto iter{countMap.find(key)};
        --iter->second;
        if (iter->second == 0)
            countMap.erase(iter);
    }

public:
    inline int subarraySum(
        vector<int> &nums,
        const int k
    ) const noexcept {
        const auto length{size(nums)};
        unordered_map<int, size_t> numMap{{nums[0], 1}};
        for (auto i{1UZ}; i < length; ++i) {
            nums[i] += nums[i - 1];
            ++numMap[nums[i]];
        }

        auto result{getOrDefault(numMap, k, 0)};
        for (const auto num : nums) {
            deleteElement(numMap, num);
            result += getOrDefault(numMap, num + k, 0);
        }
        return int(result);
    }
};
