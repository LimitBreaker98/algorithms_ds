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
    int A = 0, B = 0;
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 1; i < n; i+=2) {
        if (s[i-1] == 'A') {
            A += s[i] - '0';
        }
        else {
            B += s[i] - '0';
        }
    }
    string ans = A > B ? "A\n": "B\n";
    cout << ans;
    return 0;
}