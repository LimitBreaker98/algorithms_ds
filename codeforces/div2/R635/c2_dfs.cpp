#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5 * 10000 + 1
#define INF 10000000000

int n, k, a, b;
vector<int> depth;
vector<vector<int>> tree;
vector<int> sizeSubtree;
bool visited[200010];

void dfsDepth(int source, int parent)
{
    visited[source] = true;
    sizeSubtree[source] = 1;
    depth[source] = 1 + depth[parent];
    for (int neigh: tree[source])
    {
        if (!visited[neigh])
        {
            dfsDepth(neigh, source);
            sizeSubtree[source] += sizeSubtree[neigh];
        }
    }
}


int main()
{
    cin >> n >> k;
    tree.assign(n+1, vector<int>());
    sizeSubtree.assign(n+1, 0);
    depth.assign(n+1, 0);

    for(int i = 0; i < n-1; ++i)
    {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfsDepth(1, 0);
    vector<int> scores(n);
    for(int i = 0; i < n; ++i)
        scores[i] = depth[i+1] - sizeSubtree[i+1];
    sort(scores.begin(), scores.end(), greater<int>());
    ll ans = 0;
    int ind = 0;
    while(k--)    
        ans += scores[ind++];

    cout << ans << endl;
    return 0;
}