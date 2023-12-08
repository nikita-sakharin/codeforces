#include <cassert>
#include <cmath>
#include <cstddef>

#include <algorithm>
#include <array>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using schar  = signed char;
using uchar  = unsigned char;
using shrt   = short;
using ushrt  = unsigned short;
using uint   = unsigned;
using ulong  = unsigned long;
using llong  = long long;
using ullong = unsigned long long;
using flt    = float;
using dbl    = double;
using ldbl   = long double;

using namespace std;

static constexpr ullong max_n = 100'000L, mod = 998'244'353L;

template<typename Producer, typename Consumer>
static void mexum(ullong, Producer, Consumer) noexcept;
template<typename Arithmetic>
static vector<Arithmetic> power(Arithmetic, size_t) noexcept;

int main() {
    ios_base::sync_with_stdio(false);
    cerr.tie(nullptr);
    cin.tie(nullptr);

    ullong t;
    cin >> t;
    mexum(
        t,
        [](vector<ullong> &a) noexcept -> void {
            size_t n;
            cin >> n;
            a.resize(n);
            for (ullong &a_i : a)
                cin >> a_i;
        },
        [](const ullong result) noexcept -> void {
            cout << result << '\n';
        }
    );
    return 0;
}

template<typename Producer, typename Consumer>
static void mexum(ullong n, Producer producer, Consumer consumer) noexcept {
    const vector<ullong> two{power(2ULL, max_n + 1)};
    vector<ullong> a(max_n);
    vector<size_t> count(max_n + 2), suffix(max_n + 2);

    for (; n != 0; --n) {
        producer(a);
        const auto size{a.size()}, limit{size + 2};
        count.assign(limit, 0);
        for (size_t i{0}; i < size; ++i)
            ++count[min(a[i], static_cast<ullong>(size) + 1)];

        suffix.resize(limit);
        suffix.back() = 0;
        for (ptrdiff_t i = limit - 2; i >= 0; --i)
            suffix[i] = count[i + 1] + suffix[i + 1];

        ullong result{0}, prefix{1};
        for (size_t i{1}; i < limit; ++i) {
            result = (result + prefix * two[suffix[i]] % mod * i % mod) % mod;
            prefix = prefix * (two[count[i]] - 1) % mod;
        }
        consumer(result);
    }
}

template<typename Arithmetic>
static inline vector<Arithmetic> power(
    const Arithmetic x,
    const size_t n
) noexcept {
    vector<Arithmetic> result(n);
    if (n != 0)
        result[0] = 1;
    for (size_t i{1}; i < n; ++i)
        result[i] = result[i - 1] * x % mod;
    return result;
}
