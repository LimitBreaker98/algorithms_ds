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
#define MAX 200
#define INF 0x3f3f3f3f

int sz;
int dfs_low[MAX], dfs_num[MAX], dfs_parent[MAX];
int dfsIteration;
const int UNVISITED = -1;
vector<pii> criticalLinks;
vector<int> graph[MAX];

void bridges(int s, int parent)
{
    dfs_low[s] = dfs_num[s] = dfsIteration++;
    for (int neighbor: graph[s])
    {
        if (dfs_num[neighbor] == UNVISITED)
        {
            dfs_parent[neighbor] = s;
            bridges(neighbor, s);

            // Here all the successors have been returned recursively.

            if (dfs_low[neighbor] > dfs_num[s])
                criticalLinks.push_back(pii(min(neighbor, s), max(neighbor, s)));
            dfs_low[s] = min(dfs_low[s], dfs_low[neighbor]);
        }
        else if (dfs_parent[s] != neighbor)
            dfs_low[s] = min (dfs_low[s], dfs_num[neighbor]);
    }
}


int main()
{
    //freopen("input.txt", "r", stdin);
    while(scanf("%d", &sz) != EOF)
    {
        for (int v = 0; v < sz; v++)
            graph[v].clear();
        
        for (int i = 0; i < sz; ++i)
        {
            int a; scanf("%d", &a);
            int s; scanf(" (%d)", &s);
            while(s--)
            {
                int b;
                scanf(" %d", &b);
                if (b < a) continue;
                graph[a].push_back(b);
                graph[b].push_back(a);
            }
        }
        dfsIteration = 0;
        fill(dfs_low, dfs_low + sz, INF); // init value doesn't matter here.
        fill(dfs_num, dfs_num + sz, UNVISITED);
        fill(dfs_parent, dfs_parent + sz, UNVISITED);
        criticalLinks.clear();
        for (int i = 0; i < sz; ++i)
        {
            if (dfs_num[i] == UNVISITED)
                bridges(i, UNVISITED);
        }
        sort(criticalLinks.begin(), criticalLinks.end());
        printf("%d critical links\n", int(criticalLinks.size()));
        for (pii elem : criticalLinks)
            printf("%d - %d\n", elem.first, elem.second);
        puts("");
    }
    return 0;
}