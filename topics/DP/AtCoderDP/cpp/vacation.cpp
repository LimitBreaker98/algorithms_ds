#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5 * 10000 + 1
#define INF 10000000000

int n;
vector<vector<ll>> dp(100010, vector<ll>(3, -1));  // dp[i][j] is the maximum happiness possible by ending at day i, taking option j in day i.
                                    // j is a number from 0..2, where 0 means we did activity a, 1 activity b, so on...

int main()
{
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i] >> c[i];
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    for(int i = 1; i < n; ++i)
    {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i];
    }
    ll ans = -1;
    for (int j = 0; j <= 2; ++j)
        ans = max(ans, dp[n-1][j]);
    cout << ans << endl;
    return 0;
}