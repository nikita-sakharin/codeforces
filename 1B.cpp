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
using shrt   = short int;
using ushrt  = unsigned short int;
using uint   = unsigned int;
using ulong  = unsigned long int;
using llong  = long long int;
using ullong = unsigned long long int;
using flt    = float;
using dbl    = double;
using ldbl   = long double;

using namespace std;

static string transform_numeration(const string &input) noexcept;

int main() {
    ios_base::sync_with_stdio(false);
    cerr.tie(nullptr);
    cin.tie(nullptr);

    assert(transform_numeration("A1") == "R1C1");
    assert(transform_numeration("B1") == "R1C2");
    assert(transform_numeration("C1") == "R1C3");
    assert(transform_numeration("Y1") == "R1C25");
    assert(transform_numeration("Z1") == "R1C26");
    assert(transform_numeration("AA1") == "R1C27");
    assert(transform_numeration("AB1") == "R1C28");
    assert(transform_numeration("AC1") == "R1C29");
    assert(transform_numeration("AY1") == "R1C51");
    assert(transform_numeration("AZ1") == "R1C52");
    assert(transform_numeration("BA1") == "R1C53");
    assert(transform_numeration("BB1") == "R1C54");
    assert(transform_numeration("BC1") == "R1C55");
    assert(transform_numeration("BY1") == "R1C77");
    assert(transform_numeration("BZ1") == "R1C78");
    assert(transform_numeration("CA1") == "R1C79");
    assert(transform_numeration("CB1") == "R1C80");
    assert(transform_numeration("CZ1") == "R1C104");

    assert(transform_numeration("R1C1") == "A1");
    assert(transform_numeration("R1C2") == "B1");
    assert(transform_numeration("R1C3") == "C1");
    assert(transform_numeration("R1C25") == "Y1");
    assert(transform_numeration("R1C26") == "Z1");
    assert(transform_numeration("R1C27") == "AA1");
    assert(transform_numeration("R1C28") == "AB1");
    assert(transform_numeration("R1C29") == "AC1");
    assert(transform_numeration("R1C51") == "AY1");
    assert(transform_numeration("R1C52") == "AZ1");
    assert(transform_numeration("R1C53") == "BA1");
    assert(transform_numeration("R1C54") == "BB1");
    assert(transform_numeration("R1C55") == "BC1");
    assert(transform_numeration("R1C77") == "BY1");
    assert(transform_numeration("R1C78") == "BZ1");
    assert(transform_numeration("R1C79") == "CA1");
    assert(transform_numeration("R1C80") == "CB1");
    assert(transform_numeration("R1C104") == "CZ1");

    ullong n;
    cin >> n;

    string input;
    for (ullong i = 0; i < n; ++i) {
        cin >> input;
        cout << transform_numeration(input) << '\n';
    }

    return 0;
}

static string transform_numeration(const string &input) noexcept {
    static constexpr size_t letters_count = 26;
    static const regex first("([A-Z]+)(\\d+)", regex_constants::optimize),
        second("R(\\d+)C(\\d+)", regex_constants::optimize);

    string returns;
    if (smatch m; regex_match(input, m, second)) {
        ullong col = stoull(m[2]);
        assert(col > 0);
        while (col != 0) {
            --col;
            returns += col % letters_count + 'A';
            col /= letters_count;
        }
        reverse(returns.begin(), returns.end());
        returns += m[1];
    } else if (regex_match(input, m, first)) {
        ullong col = 0;
        for (const char &c : m[1].str()) {
            assert(c >= 'A' && c <= 'Z');
            col *= letters_count;
            col += c - 'A' + 1;
        }
        returns = 'R';
        returns += to_string(stoull(m[2]));
        returns += 'C';
        returns += to_string(col);
    } else assert(false);
    return returns;
}
