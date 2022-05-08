#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5 * 10000 + 1
#define INF 10000000000


int n;
vector<ll> stones;
vector<ll> dp(int(1e5 + 10), LLONG_MAX); // dp[i] is the minimum cost to reach stone i. Answer is at dp[n-1].
int main()
{
    cin >> n;
    stones.assign(n, 0LL);
    dp[0] = 0;
    for (int i = 0; i < n; ++i)
        cin >> stones[i];

    for (int i = 1; i < n; ++i)
        for (int j : {1,2})
            if (i - j >= 0)
                dp[i] = min(abs(stones[i-j] - stones[i]) + dp[i - j], dp[i]);
    
    cout << dp[n-1] << endl;
    return 0;
}