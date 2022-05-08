#define _USE_MATH_DEFINES
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long ull;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef priority_queue<int> maxPq;
typedef priority_queue<ll, vector<ll>, greater<ll> > minPq;
typedef deque<int> dq;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define deb(x) cout << x << endl;
#define MAX 5 * 10000 + 1
#define INF 10000000000

int sz; 
vi wines;
vector<vi> best;
int profit(int l, int r)
{
    if (l > r)
        return 0;
    int yr = sz - (r-l+1) + 1; // starts at 1.

    if (best[l][r] != -1)
        return best[l][r];

    return max(profit(l+1, r) + yr * wines[l] 
              ,profit(l, r-1) + yr * wines[r]);
}

/*
    Given an array of wines where, at each step, you can only take either the leftmost or rightmost, calculate the max
    profit you would acquire by selling all the wines in the optimal way.
    The selling price for a wine is its price, given by the array, times the year, which starts at 0 and increases by one
    in each iteration. Only one wine is sold per year. 
*/

int main()
{
    cin >> sz;
    wines.assign(sz, 0);
    best.assign(sz, vi(sz, -1));
    for (int i = 0; i < sz; ++i)
        cin >> wines[i];
    cout << profit(0, sz-1) << endl;
}