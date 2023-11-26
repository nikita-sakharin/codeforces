class Solution final {
public:
    constexpr int largestSubmatrix(
        vector<vector<int>> &matrix
    ) const noexcept {
        const auto m{matrix.size()}, n{matrix.front().size()};
        for (size_t i{1}; i < m; ++i)
            for (size_t j{0}; j < n; ++j)
                if (matrix[i][j] != 0)
                    matrix[i][j] = matrix[i - 1][j] + 1;
        int result{0};
        for (size_t i{0}; i < m; ++i) {
            sort(matrix[i].begin(), matrix[i].end());
            for (size_t j{0}; j < n; ++j)
                result = max(result, matrix[i][n - j - 1] * int(j + 1));
        }
        return result;
    }
};
