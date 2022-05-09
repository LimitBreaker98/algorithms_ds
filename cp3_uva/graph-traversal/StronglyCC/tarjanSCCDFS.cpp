#include <bits/stdc++.h>
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


vector<vi> graph;
// visited array is just temporary for each SCC.
vi visited, dfs_num, dfs_low;
stack<int> SCCs;
int dfsIteration, ccs;
const int UNVISITED = -1;
void tarjanSCC(int s)
{
    visited[s] = true;
    SCCs.push(s);
    dfs_low[s] = dfs_num[s] = dfsIteration++;
    for (int neighbor : graph[s])
    {
        if (dfs_num[neighbor] == UNVISITED)
            tarjanSCC(neighbor);
        if (visited[neighbor])
            dfs_low[u] = min(dfs_low[neighbor], dfs_low[u]);
    }

    if (dfs_num[s] == dfs_low[s]) // It's the start of a cycle
    {
        printf("Connected Component # %d", ccs);
        while(!SCCs.empty())
        {
            int node = SCCs.top(); SCCs.pop();
            visited[node] = false;
            printf(" %d", node);
        }
        printf("/n");
    }

}

int main()
{
    freopen("GraphAdjList.txt", "r", stdin);
    cin >> sz;
    graph.resize(sz);
    dfs_low.assign(sz, 0); // Doesn't matter, this will be recalculated each time we call dfs on a specific node.
    dfs_num.assign(sz, UNVISITED);
    cin >> edges;
    
    for (int i = 0; i < edges; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 0; i < sz; ++i)
        if (dfs_num[i] == UNVISITED)
            tarjanSCC(i);


    return 0;
}