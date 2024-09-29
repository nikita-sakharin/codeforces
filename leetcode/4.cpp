class Solution final {
private:
    template<class Iter>
    using Difference = iterator_traits<Iter>::difference_type;

    template<class Iter>
    static constexpr Iter nthElement(
        Iter first1, const Iter last1,
        Iter first2, const Iter last2,
        Difference<Iter> index
    ) noexcept {
        auto size1{distance(first1, last1)}, size2{distance(first2, last2)};
        while (size1 != 0 && size2 != 0) {
            const auto half1{size1 >> 1}, half2{size2 >> 1};
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
    constexpr double findMedianSortedArrays(
        const vector<int> &nums1,
        const vector<int> &nums2
    ) const noexcept {
        const auto
            first1{nums1.cbegin()}, last1{nums1.cend()},
            first2{nums2.cbegin()}, last2{nums2.cend()};
        const auto size1{ssize(nums1)}, size2{ssize(nums2)},
            median{midpoint(size1, size2)};
        const auto isOdd{((size1 ^ size2) & 1) == 1};

        if (isOdd)
            return *nthElement(first1, last1, first2, last2, median);

        return midpoint(
            double(*nthElement(first1, last1, first2, last2, median - 1)),
            double(*nthElement(first1, last1, first2, last2, median))
        );
    }
};
