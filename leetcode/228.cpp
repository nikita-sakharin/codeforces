class Solution final {
public:
    inline vector<string> summaryRanges(const vector<int> &nums) const {
        const auto size = nums.size();
        vector<string> result;
        if (size == 0)
            return result;
        auto left = nums.front();
        for (size_t i = 1; i < size; ++i)
            if (const auto prev{nums[i - 1]}; nums[i] != prev + 1) {
                pushBack(result, left, prev);
                left = nums[i];
            }
        pushBack(result, left, nums.back());
        return result;
    }

private:
    static constexpr void pushBack(
        vector<string> &result,
        const int first,
        const int second
    ) {
        result.push_back(to_string(first));
        if (first != second)
            result.back().append("->").append(to_string(second));
    }
};
