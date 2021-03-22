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

int main() {
    static constexpr size_t FOUR = 4U;

    array<uint, FOUR> lengths;
    for (uint &length : lengths)
        cin >> length;
    sort(lengths.begin(), lengths.end());

    string output = "IMPOSSIBLE";
    for (size_t i = 2; i < FOUR; ++i)
        if (lengths[i] < lengths[i - 1] + lengths[i - 2]) {
            output = "TRIANGLE";
            break;
        } else if (lengths[i] == lengths[i - 1] + lengths[i - 2])
            output = "SEGMENT";
    cout << output;

    return 0;
}
