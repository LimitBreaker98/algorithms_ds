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
    vector<int> ans;
    if (n <= 2 || ((n % 4) != 0 && (n % 4) != 3)) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if (n % 2 == 0) {
        cout << n/2 << "\n";
        for (int i = 4; i <= n; i+=4) {
            cout << i-3 << " " << i << " ";
        }
        cout << "\n";
        cout << n/2 << "\n";
        for (int i = 4; i <= n; i+=4) {
            cout << i-1 << " " << i-2 << " ";
        }
        cout << "\n";
    }
    else {
        cout << (n-3)/2 + 2 << "\n";
        for (int i = 7; i <= n; i+=4) {
            cout << i-3 << " " << i << " ";
        }
        cout << "1 2\n";
        cout << (n-3)/2 + 1 << "\n"; 
        for (int i = 7; i <= n; i+=4) {
            cout << i-1 << " " << i-2 << " ";
        }
        cout << "3\n";
    }
    return 0;
}