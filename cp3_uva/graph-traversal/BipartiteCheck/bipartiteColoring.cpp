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

int n, e;

bool bicoloringBFS(int source, vector<vi> &graph)
{
    queue<int> q;
    q.push(source);
    vi color(n, -1);
    color[source] = 0;
    bool colorable = true;
    while(!q.empty() && colorable)
    {
        int node = q.front();
        q.pop();
        for(int neighbor: graph[node])
        {
            if(color[neighbor] == -1)
            {
                color[neighbor] = 1-color[node];
                q.push(neighbor);
            }
            else if (color[neighbor] == color[node])
            {
                colorable = false;
            }
        }
    }
    return colorable;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (true)
    {
        cin >> n;
        if (n == 0) break;
        vector<vi> graph(n);
        cin >> e;
        for(int i = 0; i < e; ++i)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bool ans = bicoloringBFS(0, graph);
        if (ans) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}