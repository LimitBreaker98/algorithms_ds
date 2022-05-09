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