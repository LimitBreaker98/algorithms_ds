#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5 * 10000 + 1
#define INF 1000000000
const int MAX_VALUE = int(1e5+10);
int n, w;
vector<ll> dp(MAX_VALUE, INF+1); // dp[i] is the minimum weight required to pack elements such that the total value sum is i. 
vector<pair<ll, ll> > elems;  // weight, value
ll a, b;
int main()
{
    cin >> n >> w;
    while(n--)
    {
        cin >> a >> b; // weight, value
        elems.push_back({a, b});
    }
    dp[0] = 0; // base case, we need a knapsack with capacity dp[0] = 0 to add up elements with total value i = 0.
    for (pair<ll, ll> elem: elems)
    {
        for (int i = MAX_VALUE; i - elem.second >= 0; --i)
        {
            dp[i] = min(dp[i], dp[i - elem.second] + elem.first);
        }
    }
    int ans = -1;
    for (int i = MAX_VALUE-1; i >= 0 && ans == -1; --i)
    {
        if (dp[i] <= w)
        {
            //printf("dp[%d] is %d\n", i, dp[i]);
            ans = i;
        }
    }
    cout << ans << endl;
}