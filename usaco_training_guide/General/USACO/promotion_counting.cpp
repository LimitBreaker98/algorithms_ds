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

    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    vector<ll> delta(3, 0);

    for (int i = 0; i < 4; ++i) {
        ll prev, curr;
        cin >> prev >> curr;
        for(int j = 0; j < i && j < 3; ++j) {
            ll diff = curr - prev;
            delta[j] += diff;
        }
    }

    for(auto e: delta)
        cout << e << "\n";
    

    return 0;
}