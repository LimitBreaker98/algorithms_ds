#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5 * 10000 + 1
#define INF 10000000000
int n, w;
vector<ll> dp(100010, 0);
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
        
    
    for (pair<ll, ll> elem: elems)
    {
        //for (int i = 0; i + elem.first <= w; ++i) (Knapsack with repetitions)
        for (int i = w - elem.first; i >= 0; --i)
        {
            dp[i+elem.first] = max(dp[i+elem.first], dp[i] + elem.second);
        }
    }
    cout << dp[w] << endl;
    return 0;
}