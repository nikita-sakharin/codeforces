class Solution final {
public:
    constexpr int findContentChildren(
        vector<int> &g,
        vector<int> &s
    ) const noexcept {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        const auto gEnd{g.cend()}, sEnd{s.cend()};
        auto gIter{g.cbegin()}, sIter{s.cbegin()};
        while (gIter != gEnd && sIter != sEnd) {
            if (*gIter <= *sIter)
                ++gIter;
            ++sIter;
        }
        return gIter - g.cbegin();
    }
};
