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
#define forVar(type, var, init, till, increment) for (type var = init; var < till; var += increment)
#define deb(x) cout << x << endl;
#define MAX 5 * 10000 + 1
#define INF 10000000000

int rows[] = {0, 0, 1, 1, 1, -1, -1, -1};
int cols[] = {1,-1, -1, 0, 1, -1, 0, 1};
int t;



/**
 * Finds size of connected component in a grid
 */
int floodfill(int r, int c, char color, vector<string> &grid)
{
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].length()) return 0;
    if (grid[r][c] != color) return 0;
    int ans = 1; // we start with r,c marked as its own color.
    // Change this color to a different one not to repeat count. This is like marking visited.

    grid[r][c] = 'L';
    // There are 8 adjacent squares that we get from arrays rows and columns by accessing same index.
    for(int i = 0; i < 8; ++i)
    {
        ans += floodfill(r+rows[i], c+cols[i], color, grid);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    string row;
    getline(cin, row);
    getline(cin, row);
    while (t--)
    {
        
        vector<string> grid;
        while (true)
        {
            getline(cin, row);
            if (!isalpha(row[0])) break;
            grid.push_back(row);
        }
        int r, c;
        vector<string> copiedMap = grid;
        istringstream inputStream(row);
        inputStream >> r >> c;
        r--; c--;
        cout << floodfill(r,c,'W', copiedMap) << endl;
        while(true)
        {
            getline(cin, row);
            if (row.empty()) break;
            istringstream inputStream2(row);
            inputStream2 >> r >> c;
            r--; c--;
            copiedMap = grid;
            cout << floodfill(r,c,'W', copiedMap) << endl;
        }
        if (t != 0) cout << endl;
        // Solve the case with floodfill.
    }
    return 0;
}