#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5 * 10000 + 1
#define INF 10000000000

int n, k, a, b;
bool visited[200010];
vector<vector<int>> tree;
vector<ll> scores;

ll dfsDepth(int source, ll depth)
{
    visited[source] = true;
    ll laterNodesOnPath = 1;
    for (int n: tree[source])
    {
        if (!visited[n])
            laterNodesOnPath += dfsDepth(n, depth + 1);
    }
    scores[source] = depth - laterNodesOnPath;
    return laterNodesOnPath;
}


int main()
{
    cin >> n >> k;
    tree.assign(n+1, vector<int>());
    scores.assign(n+1, 0);
    while(--n)
    {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfsDepth(1LL, 1LL);
    sort(scores.begin(), scores.end(), greater<ll>());
    ll ans = 0;
    int ind = 0;
    while(k--)        
        ans += scores[ind++];
    cout << ans << endl;
    return 0;
}