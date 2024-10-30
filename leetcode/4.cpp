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
    static constexpr tuple<Iter, Iter> nthElement(
        Iter first1, const Iter last1,
        const Iter first2, const Iter last2,
        Difference<Iter> n
    ) noexcept {
        auto size1{distance(first1, last1)};
        const auto size2{distance(first2, last2)};

        if (n <= 0)
            return {first1, first2};

        if (n >= size1 + size2)
            return {last1, last2};

        if (size1 > size2) {
            const auto [iter1, iter2]{
                nthElement(first2, last2, first1, last1, n)
            };
            return {iter2, iter1};
        }

        while (size1 > 0) {
            const auto lower{max(Difference<Iter>{0}, n - size2)}, upper{min(size1, n)};
            const auto index1{midpoint(lower, upper - 1)}, index2{n - index1 - 1};
            const auto iter1{next(first1, index1)}, iter2{next(first2, index2)};
            if (*iter2 < *iter1)
                size1 = index1;
            else {
                first1 = next(iter1);
                size1 -= index1 + 1;
                n -= index1 + 1;
            }
        }

        return {first1, next(first2, n)};
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

        const auto [iter1, iter2]{
            nthElement(first1, last1, first2, last2, median)
        };

        const auto right{
            iter1 == last1 || (iter2 != last2 && *iter2 < *iter1)
                ? *iter2
                : *iter1
        };

        if (isOdd(size1 ^ size2))
            return right;

        const auto left{
            iter2 == first2 || (iter1 != first1 && *prev(iter2) < *prev(iter1))
                ? *prev(iter1)
                : *prev(iter2)
        };

        return midpoint(dbl(left), dbl(right));
    }
};
