class Solution final {
public:
    constexpr string addBinary(string &a, string &b) const noexcept {
        if (size(a) < size(b))
            return addBinary(b, a);

        auto carry{false};
        const auto lastA{crend(a)}, lastB{crend(b)};
        for (auto iterA{rbegin(a)}, iterB{rbegin(b)}; iterA != lastA; ++iterA) {
            const auto
                left{*iterA - '0'},
                right{iterB != lastB ? *iterB++ - '0' : 0},
                sum{carry + left + right};
            *iterA = '0' + (sum & 1);
            carry = sum >> 1;
        }
        if (carry)
            a.insert(cbegin(a), '1');

        return move(a);
    }
};
