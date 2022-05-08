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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    ll prev, curr;
    cin >> prev;

    ll ans = 0;
    for(int i = 1; i < n; ++i) {
        cin >> curr;
        ll moves = max(0LL, prev - curr);
        ans += moves;
        prev = curr + moves;
    }
    cout << ans << "\n";
    return 0;
}