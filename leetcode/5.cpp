class Solution final {
public:
    inline string longestPalindrome(const string &s) const noexcept {
        const auto size{s.size()};
        string_view result{};
        vector<vector<bool>> matrix{size, vector<bool>(size)};
        for (auto diagonal{0UZ}; diagonal < size; ++diagonal)
            for (auto j{diagonal}; j < size; ++j) {
                const auto i{j - diagonal};
                if (diagonal == 0)
                    matrix[i][j] = true;
                else
                    matrix[i][j] = s[i] == s[j] && matrix[i + 1][j - 1];
                if (matrix[i][j] && diagonal + 1 > result.size())
                    result = string_view(s).substr(i, diagonal + 1);
            }
        return string(result);
    }
};
