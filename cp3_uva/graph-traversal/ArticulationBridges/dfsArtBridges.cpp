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

const int UNVISITED = -1;
int sz, edges;
vi dfs_low, dfs_num, dfs_parent;
vector<vi> graph;
vi articulation_vertex;
int dfsIteration, dfsRoot, rootCounter;

void artsAndBridges(int s)
{
    dfs_low[s] = dfs_num[s] = dfsIteration++;
    for (int neighbor : graph[s])
    {
        if (dfs_num[neighbor] == UNVISITED)
        {
            dfs_parent[neighbor] = s;
            if (dfsRoot == s) // if the parent is a root of DFS Call. Edge Case.
                rootCounter++;
            artsAndBridges(neighbor);

            // Here all the tree has already been explored recursively.
            
            if (dfs_low[neighbor] >= dfs_num[s])
                articulation_vertex[s] = true;
            if (dfs_low[neighbor] > dfs_num[s])
                printf("Edge (%d, %d) is a bridge \n", s, neighbor);

            // we update source low with the best low found in its successors.
            // If there is a better low, it must be because there was a backedge further down the recursion tree. 
            dfs_low[s] = min(dfs_low[s], dfs_low[neighbor]);
        }
        else if (dfs_parent[s] != neighbor) // We have a backedge! Update lowest reachable for s with this neighbor's num.
            dfs_low[s] = min(dfs_low[s], dfs_num[neighbor]);
    }
}

int main()
{
    freopen("UndirectedGraph.txt", "r", stdin);
    cin >> sz;
    graph.resize(sz);
    dfs_low.assign(sz, 0); // Doesn't matter, this will be recalculated each time we call dfs on a specific node.
    dfs_num.assign(sz, UNVISITED); // Matters, since we need to know what vertices are unvisited to explore them recursively.
    articulation_vertex.assign(sz, 0);
    dfs_parent.assign(sz, 0);
    cin >> edges;
    for (int i = 0; i < edges; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfsIteration = 0;
    for (int i = 0; i < sz; ++i) // in the case that this graph is a forest.
    {
        if (dfs_num[i] == UNVISITED)
        {
            dfsRoot = i;
            rootCounter = 0;
            artsAndBridges(i);
            articulation_vertex[i] = rootCounter > 1;
        }
    }
    for (int i = 0; i < sz; ++i)
    {
        if (articulation_vertex[i])
            printf("Articulation Vertex %d \n", i);
    }

    return 0;
}