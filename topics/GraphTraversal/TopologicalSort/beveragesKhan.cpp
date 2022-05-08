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
vector<vi> graph;
vi tSort;
bool visited[105];
int inDegree[105];
void khan(int drinks, unordered_map<int,string> &word)
{
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i = 0; i < drinks; ++i)
    {
        if (inDegree[i] == 0)
            q.push(i);   
    }
    while(!q.empty())
    {
        int curr = q.top();
        tSort.push_back(curr);
        q.pop();
        for(int neighbor: graph[curr])
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    int drinks;
    int caso = 1;
    while(cin >> drinks)
    {
        tSort.clear();
        memset(visited, false, sizeof(visited));
        memset(inDegree, 0, sizeof(inDegree));
        unordered_map<string, int> number;
        unordered_map<int, string> word;
        for(int i = 0; i < drinks; ++i)
        {
            cin >> s;
            number[s] = i;
            word[i] = s;
        }
        graph.assign(drinks, vector<int>());
        int hier;
        cin >> hier;
        for(int i = 0; i < hier; ++i)
        {
            cin >> s;
            int node = number[s];
            cin >> s; 
            int dest = number[s];
            graph[node].push_back(dest);
        }
        for(int i = 0; i < drinks; ++i)
        {
            for(int elem: graph[i])
                inDegree[elem]++;
        }

        khan(drinks, word);

        cout << "Case #" << caso++ << ": Dilbert should drink beverages in this order: ";
        for(int i = 0; i < drinks; ++i)
        {
            cout << word[tSort[i]];
            if (i != drinks - 1) cout << " ";
            else cout << ".";
        }
        cout << endl << endl;
    }
    return 0;
}