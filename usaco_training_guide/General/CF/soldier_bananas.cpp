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

ll sum_to_n(ll n) {
    return n * (n+1) / 2;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k, n, w;
    cin >> k >> n >> w;
    cout << max(sum_to_n(w) * k - n, 0LL) << "\n";
    return 0;
}