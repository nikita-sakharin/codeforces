class Solution final {
public:
    constexpr int mySqrt(const int x) const noexcept {
        if (x <= 1)
            return x;
        auto xCurrent{0}, xNext{x / 2};
        do {
            xCurrent = xNext;
            xNext = (xCurrent + x / xCurrent) / 2;
        } while (xNext < xCurrent);
        return xCurrent;
    }
};
