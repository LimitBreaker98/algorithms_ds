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

int t;
bool visited[26];
void dfsNumComps(int source, vector<vector<char> > & graph)
{
    visited[source] = true;
    for(int neighbor: graph[source])
    {
        if (!visited[neighbor])
            dfsNumComps(neighbor, graph);
    }
        
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    string li;
    getline(cin, li);
    getline(cin, li);
    while(t--)
    {
        // Maxima letra
        memset(visited, false, sizeof(visited));
        getline(cin, li);
        int letras = li[0] - 'A' + 1;
        //cout << "hay letras: " << letras << endl;
        vector<vector<char> > graph(letras);
        while(true)
        {
            getline(cin, li);
            if (li.empty()) break;
            char a, b;
            a = li[0]; b = li[1];
            graph[int(a-'A')].push_back(int(b-'A'));
            graph[int(b-'A')].push_back(int(a-'A'));
        }
        int CC = 0;
        for(int i = 0; i < letras; ++i)
        {
            if (!visited[i])
            {
                CC++;
                dfsNumComps(i, graph);
            }
        }
        cout << CC << endl;
        if (t != 0) cout << endl;
    }
    return 0;
}