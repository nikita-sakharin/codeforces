class Solution final {
public:
    constexpr int hammingDistance(const int x, const int y) const noexcept {
        return x ^ y;
    }
};
