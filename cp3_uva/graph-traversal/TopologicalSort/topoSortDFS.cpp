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

int n, v;
vector<vi> graph;
vi tSort;
bool visited[10];
void dfsTopo(int source)
{
    visited[source] = true;
    for(int n: graph[source])
    {
        if (!visited[n])
            dfsTopo(n);
    }
    tSort.push_back(source);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> v;
    graph.assign(n, vector<int>());
    for(int i = 0; i < v; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for(int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfsTopo(i);
    }

    reverse(tSort.begin(), tSort.end());
    for (int i : tSort) cout << i << " ";
    cout << endl;
    return 0;
}