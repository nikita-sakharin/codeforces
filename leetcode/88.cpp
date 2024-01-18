class Solution final {
public:
    constexpr void merge(
        vector<int> &nums1, int m,
        vector<int> &nums2, int n
    ) const noexcept {
        --m, --n;
        for (ptrdiff_t i{m + n - 1}; i >= 0; --i)
            if (m < 0 || (n >= 0 && nums1[m] < nums2[n]))
                nums1[size_t(i)] = nums2[size_t(n--)];
            else
                nums1[size_t(i)] = nums1[size_t(m--)];
    }
};
