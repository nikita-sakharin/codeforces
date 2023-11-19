class Solution final {
private:
    static constexpr int area(
        const int x1, const int y1,
        const int x2, const int y2
    ) noexcept {
        return (x2 - x1) * (y2 - y1);
    }

    static constexpr int intersection(
        const int ax1, const int ay1,
        const int ax2, const int ay2,
        const int bx1, const int by1,
        const int bx2, const int by2
    ) noexcept {
        if (ax1 >= bx2 || ax2 <= bx1 || ay1 >= by2 || ay2 <= by1)
            return 0;
        return ;
    }

public:
    constexpr int computeArea(
        const int ax1, const int ay1,
        const int ax2, const int ay2,
        const int bx1, const int by1,
        const int bx2, const int by2
    ) const noexcept {
        return area(ax1, ay1, ax2, ay2) + area(bx1, by1, bx2, by2)
            - intersection(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    }
};
