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


int n, m, dfs_iter;
vi dfs_low, dfs_num, visited;
const int UNVISITED = -1;
vector<vi> g;
vector<int> st; // to keep track of components.
vector<vi> SCCs;

void dfsSCC(int node)
{
    st.push_back(node);
    dfs_num[node] = dfs_low[node] = dfs_iter++;
    visited[node] = 1;
    for (int neighbor: g[node])
    {
        if (dfs_num[neighbor] == UNVISITED)
            dfsSCC(neighbor);
        if (visited[neighbor])
            dfs_low[node] = min(dfs_low[node], dfs_low[neighbor]);
    }
    if (dfs_num[node] == dfs_low[node]) // start of SCC
    {
        vi comp;
        while (true)
        {
            int curr = st.back();
            st.pop_back();
            visited[curr] = 0;
            comp.push_back(curr);
            if (curr == node) break;
        }
        SCCs.push_back(comp);
    }
}

int main()
{   
    //freopen("calls.txt", "r", stdin);
    int dataset = 1;
    while (true)
    {
        cin >> n >> m;
        if (n == m && m == 0) return 0;
        dfs_iter = 0;
        int num = 0;
        SCCs.clear(); st.clear();
        visited.assign(n, 0); dfs_low.assign(n, 0); dfs_num.assign(n, UNVISITED);
        g.assign(n, vi());
        unordered_map<string, int> ns;
        unordered_map<int, string> word;
        for (int i = 0; i < m; ++i)
        {
            string n1, n2;
            cin >> n1 >> n2;
            if (ns.find(n1) == ns.end())
            {
                ns[n1] = num;
                word[num++] = n1;
            }  
            if (ns.find(n2) == ns.end())
            {
                ns[n2] = num;
                word[num++] = n2;
            }
            bool seen = false;
            for (int neighbor : g[ns[n1]])
                if (neighbor == ns[n2]) seen = true;
            if (!seen)
                g[ns[n1]].push_back(ns[n2]);
        }

        for (int i = 0; i < n; ++i)
            if (dfs_num[i] == UNVISITED)
                dfsSCC(i);
        
        printf("Calling circles for data set %d:\n", dataset++);
        for (int comp = 0; comp < SCCs.size(); ++comp)
        {
            vi thisComp = SCCs[comp];
            for (int i = 0; i < thisComp.size(); ++i)
            {
                cout << word[thisComp[i]];
                if (i != thisComp.size()-1)
                    cout << ", ";
            }
            cout << "\n";
        }
    }
    return 0;
}