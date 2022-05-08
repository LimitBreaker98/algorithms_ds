#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5 * 10000 + 1
#define INF 10000000000

int n, m;
vector<vector<int>> g;
vector<int> dp(int(1e5 + 10), 1);
int longestPath(int x)
{
    if (dp[x] != 1)
        return dp[x];
    
    for (int s: g[x])
        dp[x] = max(1+longestPath(s), dp[x]);
    return dp[x];
}


int main()
{
    cin >> n >> m;
    g.assign(n, vector<int>());
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }
    int ans = -3;
    for (int i = 0; i < n; ++i)
    {
        ans = max(longestPath(i) - 1, ans);
    }
    cout << ans << endl;
    
    return 0;
}