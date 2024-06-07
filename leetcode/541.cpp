class Solution final {
public:
    inline string reverseStr(string &s, const int k) const noexcept {
        const auto last{s.end()};
        auto iter{s.begin()};
        while (iter != last) {
            const auto nextIter{iter + min(last - iter, ptrdiff_t(k))};
            reverse(iter, nextIter);
            iter = nextIter + min(last - nextIter, ptrdiff_t(k));
        }
        return move(s);
    }
};
