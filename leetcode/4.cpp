class Solution final {
private:
    using dbl = double;

    template<class Iter>
    using Difference = iterator_traits<Iter>::difference_type;

    template<class T>
    static constexpr bool isOdd(
        const T x
    ) noexcept {
        return (x & T{1}) == T{1};
    }

    template<class T>
    static constexpr T midpointFloor(
        const T x,
        const T y
    ) noexcept {
        return (x & y) + ((x ^ y) >> 1);
    }

    template<class Iter>
    static constexpr Iter nthElement(
        Iter first1, const Iter last1,
        Iter first2, const Iter last2,
        Difference<Iter> index
    ) noexcept {
        auto size1{distance(first1, last1)}, size2{distance(first2, last2)};
        while (size1 != 0 && size2 != 0) {
            const auto half1{(size1 - 1) >> 1}, half2{(size2 - 1) >> 1};
            const auto iter1{next(first1, half1)}, iter2{next(first2, half2)};
            if (index <= half1 + half2) {
                if (*iter1 > *iter2)
                    size1 = half1;
                else
                    size2 = half2;
            } else {
                if (*iter1 > *iter2) {
                    first2 = next(iter2);
                    size2 -= half2 + 1;
                    index -= half2 + 1;
                } else {
                    first1 = next(iter1);
                    size1 -= half1 + 1;
                    index -= half1 + 1;
                }
            }
        }
        return (size1 == 0 ? first2 : first1) + index;
    }

public:
    constexpr dbl findMedianSortedArrays(
        const vector<int> &nums1,
        const vector<int> &nums2
    ) const noexcept {
        const auto
            first1{cbegin(nums1)}, last1{cend(nums1)},
            first2{cbegin(nums2)}, last2{cend(nums2)};
        const auto size1{ssize(nums1)}, size2{ssize(nums2)},
            median{midpointFloor(size1, size2)};

        if (isOdd(size1 ^ size2))
            return *nthElement(first1, last1, first2, last2, median);

        return midpoint(
            dbl(*nthElement(first1, last1, first2, last2, median - 1)),
            dbl(*nthElement(first1, last1, first2, last2, median))
        );
    }
};
