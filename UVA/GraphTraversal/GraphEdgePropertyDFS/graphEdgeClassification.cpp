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


/*
    Graph edge property algorithm using DFS
    Identifies all edges into 3 categories:

    1. Tree Edge: An edge traversed by DFS. Goes from an explored node
    to an unvisited node.

    2. Back Edge: An edge that is part of a cycle. Goes from explored node
    to another explored node.

    3. Forward/Cross edge: Edges not used in the DFS Tree. 
    Forward would skip ahead to an already visited part of the graph, and
    a Cross edge would just make it seem that its jumping from branch
    to a different branch. 

    KEY: When called, DFS marks the current node as explored. When recursion
    ends, it marks it as visited. 

    This works for undirected and directed graphs.
*/


const int UNVISITED = 0;
const int VISITED = 1;
const int EXPLORED = 2;

vector<vi> graph;
int parent[MAX];
int state[MAX];
int sz, edges;

void graphCheck(int s)
{
    state[s] = EXPLORED;
    
    for(int n : graph[s])
    {
        if (state[n] == UNVISITED)
        {
            parent[n] = s;
            graphCheck(n);
        }

        // If this is an undirected graph we don't consider immediate backedges as cycles.
        else if (state[n] == EXPLORED)
        {
            if (parent[s] == n)
                printf("Immediate parent of %d is %d \n", s, n);
            else
                printf("BackEdge (Cycle) %d, %d \n", s, n);            
        }
        else
            printf ("Forward Edge (Unused) edge (%d, %d) \n", s, n);
    }
    state[s] = VISITED;
}

int main()
{
    freopen("GraphAdjList.txt", "r", stdin);
    cin >> sz;
    graph.resize(sz);
    cin >> edges;
    int numComp = 1;
    for (int i = 0; i < edges; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
   
    for (int i = 0; i < sz; ++i)
        if (state[i] == UNVISITED)
            printf("Component %d: \n", numComp++), graphCheck(i);
    return 0;
}