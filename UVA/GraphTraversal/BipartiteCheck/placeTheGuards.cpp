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
#define MAX 210
#define INF 10000000000

vector<vi> graph;
int t, sz, edges;
int color[MAX];
int black, white;

const int UNVISITED = -1;
// returns [-1,-1] if component is not bipartite, else returns [black, white], the amount of nodes colored black/white.
bool bipartiteComponent(int s)
{
    bool colorable = true;
    black = white = 0;
    color[s] = 0;
    black++;
    stack<int> st; //dfs without relying on recursive stack.
    st.push(s);
    while (colorable && !st.empty())
    {
        int curr = st.top();
        st.pop();
        for (int neighbor : graph[curr])
        {
            if (color[neighbor] == UNVISITED)
            {
                color[neighbor] = 1 - color[curr];
                if (color[neighbor] == 0)
                    black++;
                else
                    white++;
                st.push(neighbor);
            }
            else if (color[neighbor] == color[curr])
            {
                colorable = false;
            }
        }
    }
    return colorable;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--)
    {
        cin >> sz >> edges;
        graph.assign(sz, vi());
        for (int i = 0; i < edges; ++i)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        memset(color, UNVISITED, sizeof(color)); // alternatively use vectorName.assign(V, UNVISITED);
        int ans = 0;
        for (int i = 0; i < sz; ++i)
            if (color[i] == UNVISITED)
            {
                if (!bipartiteComponent(i))
                {
                    ans = -1;
                    break;
                }
                int total = black+white;
                if (total == 1)
                    ans += 1;
                else
                    ans += min (black, white);
            } 
        cout << ans << endl;
    }
    return 0;
}