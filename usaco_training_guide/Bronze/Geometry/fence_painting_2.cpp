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

    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int total = d-c + b-a;
    int intersection = max(0, min(b, d) - max(a, c));
    cout << total - intersection << "\n";

    return 0;
}