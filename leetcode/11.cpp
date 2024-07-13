class Solution final {
public:
    constexpr int maxArea(const vector<int> &height) const noexcept {
        auto result{0};
        auto i{0UZ}, j{height.size() - 1};
        while (i < j) {
            const auto width{int(j - i)},
                minHeight{height[i] < height[j] ? height[i++] : height[j--]};
            result = max(result, width * minHeight);
        }
        return result;
    }
};
