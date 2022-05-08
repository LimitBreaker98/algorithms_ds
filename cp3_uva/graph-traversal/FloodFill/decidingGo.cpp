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

char board[9][9];
int rows[] = {0, 0, 1, -1};
int cols[] = {1,-1, 0, 0 };
int b, w;
int borderB, borderW;
bool used[9][9];


int floodfill(int r, int c)
{
    //cout << "floodfilling " << r << " " << c << endl;
    int ans = 1;
    if (r < 0 || r >= 9 || c < 0 || c >= 9 || used[r][c]) return 0;
    used[r][c] = true;
    if (board[r][c] != '.')
    {
        if (board[r][c] == 'X')
            borderB++;
        else 
            borderW++;
        return 0;
    }
    for (int i = 0; i < 4; ++i)
    {
        ans += floodfill(r + rows[i], c + cols[i]);
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    string l;
    for (int i = 0; i < 9; ++i)
    {
        cin >> l;
        for (int j = 0; j < 9; ++j)
        {
            board[i][j] = l[j];
            cout << board[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] == '.')
            {
                borderB = 0; borderW = 0; 
                int squares = floodfill(i, j);

                if (borderB == 0 && borderW != 0)
                    w += squares;
                else if (borderW == 0 && borderB != 0)
                    b += squares;
            }
            else if (board[i][j] == 'X') b++;
            else w++;
        }
    printf("Black %d White %d\n", b, w);
    return 0;
}