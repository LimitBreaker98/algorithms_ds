#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long ull;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef priority_queue<int> maxPq;
typedef priority_queue<ll, vector<ll>, greater<ll> > minPq;
typedef deque<int> dq;

int sz = int(1e3);

//vector<vector<bool>> reach(sz, vector<bool>(sz, false));
vector<ll> dp (sz + 1, 0);


bool reachable (ll from, ll to) {
    for (ll x = 1; x <= from; ++x) {
        if ((from + from / x) == to)
            return true;
    }
    return false;
}


void solve() {
    for (ll i = 1; i <= sz; ++i) {
        for (ll j = 1; j < i; ++j) {
            if (reachable (j, i)) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (ll i = 1; i <= sz; ++i) {
        dp[i] = i-1;
    }

    solve();
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        vector<ll> best(min(k+1, 12*n+1), 0);

        vector<ll> b(n);
        for (auto &a: b) cin >> a;

        vector<ll> c(n);
        for (auto &a: c) cin >> a;

        vector<ll> dist(n);
        for (ll i = 0; i < n; ++i) {
            dist[i] = dp[b[i]];
        }

        // knapsack
        // best[d] holds the best score with a total dist.
        ll tp = 0;
        for (int i = 0; i < c.size(); ++i) {
            ll value = c[i];
            ll weight = dist[i];

            for (ll j = min(k, 12*n) - weight; j >= 0; --j) {
                best[j + weight] = max(best[j + weight], best[j] + value);
                tp = max(tp, best[j + weight] );
            }
        }

        cout << tp << "\n";

        

    }
    return 0;
}