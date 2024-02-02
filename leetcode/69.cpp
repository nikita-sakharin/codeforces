class Solution final {
public:
    constexpr int mySqrt(const int x) const noexcept {
        if (x <= 1)
            return x;
        auto xCurrent{0}, xNext{x >> 1};
        do {
            xCurrent = xNext;
            xNext = (xCurrent + x / xCurrent) >> 1;
        } while (xNext < xCurrent);
        return xCurrent;
    }
};
