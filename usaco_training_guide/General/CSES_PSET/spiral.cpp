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
    while(t--) {
        ll r, c;
        cin >> r >> c;
        if (r > c) {
            if (r % 2) { // odd r
                ll lo = (r-1) * (r-1);
                cout << lo + c << "\n";
            }
            else { // even r
                ll hi = r*r + 1;
                cout << hi - c  << "\n";
            }
        }
        else {
            if (c % 2) { // odd c
                ll hi = c*c + 1;
                cout << hi - r  << "\n";
            }
            else {
                ll lo = (c-1) * (c-1);
                cout << lo + r << "\n";
            }
        }
    }
    return 0;
}