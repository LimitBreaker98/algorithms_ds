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
    ll n;
    cin >> n;
    for(int r = 1; r <= n; ++r) {
        ll k = r*r;
        if (r == 1) {
            cout << "0\n";
        }
        else if (r == 2) {
            cout << "6\n";
        }
        else if (r == 3) {
            cout << "28\n";
        }
        else {
            ll invalid_combs = ((r-2) * ((r-4)*4 + 10)) + 4 + (r-4) * 2;
            ll total_combs = (k-1) * k / 2;
            cout << total_combs-invalid_combs << "\n"; 
        }
    }
    return 0;
}