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
    string s;
    cin >> s;
    int cnt = 1;
    int bst = 1;
    int n = s.size();
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) {
            cnt++;
        }
        else {
            cnt = 1;
        }
        bst = max(cnt, bst);
    }
    cout << bst << "\n";
    return 0;
}