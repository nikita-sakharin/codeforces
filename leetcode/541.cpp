class Solution final {
public:
    inline string reverseStr(string &str, const int k) const noexcept {
        const auto last{end(str)};
        auto iter{begin(str)};
        while (iter != last) {
            const auto nextIter{iter + min(last - iter, ptrdiff_t(k))};
            reverse(iter, nextIter);
            iter = nextIter + min(last - nextIter, ptrdiff_t(k));
        }
        return move(str);
    }
};
