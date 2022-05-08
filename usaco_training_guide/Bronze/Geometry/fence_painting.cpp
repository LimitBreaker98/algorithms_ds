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
    
    if (a > c) {
        swap(a, c);
        swap(b, d);
    }
    if (c >= b) {
        cout << b - a + d - c << "\n";
    }
    else if (d <= b) {
        cout << b-a << "\n";
    }
    else {
        cout << d-a << "\n";
    }

    return 0;
}