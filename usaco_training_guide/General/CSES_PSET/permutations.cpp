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
    if (n <= 3 && n > 1) {
        cout << "NO SOLUTION";
    }
    else if (n == 4) {
        cout << "3 1 4 2";
    }
    else {
        for (int x = n; x > 0; x-=2)
            cout << x << " ";
        for (int x = n-1; x > 0; x-=2)
            cout << x << " ";
    }
    cout << "\n";
    return 0;
}