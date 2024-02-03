#include <cstddef>

#include <exception>
#include <limits>
#include <vector>

using namespace std;

template<typename T>
static inline vector<vector<ptrdiff_t>> floyd_warshall(vector<vector<T>> &d) {
    static constexpr T infinity = numeric_limits<T>::infinity();

    const auto n{d.size()};
    vector<vector<ptrdiff_t>> pi(n);
    for (size_t i{0}; i < n; ++i) {
        pi[i].resize(n);
        for (size_t j = 0; j < n; ++j)
            pi[i][j] = i == j || d[i][j] == infinity ? -1 : i;
    }
    auto flag{true};
    for (size_t k{0}; flag && k < n; ++k) {
        flag = false;
        for (size_t i{0}; i < n; ++i)
            for (size_t j{0}; j < n; ++j)
                if (d[i][k] != infinity && d[k][j] != infinity &&
                    d[i][k] + d[k][j] < d[i][j]
                ) {
                    d[i][j] = d[i][k] + d[k][j];
                    pi[i][j] = pi[k][j];
                    flag = true;
                }
    }
    if constexpr (numeric_limits<T>::is_signed)
        for (size_t i{0}; i < n; ++i)
            if (d[i][i] < 0)
                throw exception();
    return pi;
}
