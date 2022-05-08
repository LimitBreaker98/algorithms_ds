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
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int s, e, t1, t2;
    cin >> s >> e >> t1 >> t2;
    if (s == e)
        cout << "0\n";
    if (t1 > t2)
        swap(t1, t2);
    if (s > e)
        swap(s, e);
    
    int ans = e - s;
    ans = min(ans, abs(e - t2) + abs(t1 - s));
    cout << ans << "\n";
    
    return 0;
}