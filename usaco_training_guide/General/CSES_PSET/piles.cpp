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
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        bool ok = !((a + b) % 3LL);
        //cout << ok << "\n";
        if (a < b) {
            swap(a, b);
        }
        ok &= (b * 2) >= a;
        //cout << ok << "\n";
        string ans = ok ? "YES\n" : "NO\n";
        cout << ans;
    }

    return 0;
}