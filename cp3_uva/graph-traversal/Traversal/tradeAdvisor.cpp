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

int v, e;
ll maxProfit;
bool visited[505];
int dfs(int source, vector<vector<pair<int, ll> > > &graph)
{
    int size = 1;
    visited[source] = true;
    for(pii neighbor: graph[source])
    {
        if (!visited[neighbor.first] && neighbor.second == maxProfit)
        {
            size += dfs(neighbor.first, graph);
        }
    }
    return size;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(true)
    {
        cin >> v >> e;
        if (v == 0 && e == 0) break;
        maxProfit = LLONG_MIN + 10;
        int a, b;
        ll profit;
        memset(visited, false, sizeof(visited));
        vector<vector<pair<int, ll > > > graph(v+1);
        for(int i = 0; i < e; ++i)
        {
            cin >> a >> b >> profit;
            graph[a].push_back(make_pair(b, profit));
            graph[b].push_back(make_pair(a, profit));
            maxProfit = max(maxProfit, profit);
        }
        int ans = -1;
        for(int i = 1; i <= v; ++i)
        {
            if (!visited[i])
                ans = max(ans, dfs(i, graph));
        }
        cout << ans << endl;
    }
    return 0;
}