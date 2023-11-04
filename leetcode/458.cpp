class Solution final {
public:
    inline int poorPigs(
        const int buckets,
        const int minutesToDie,
        const int minutesToTest
    ) const noexcept {
        const auto radix{minutesToTest / minutesToDie + 1};
        return static_cast<int>(ceil(log2(buckets) / log2(radix)));
    }
};
