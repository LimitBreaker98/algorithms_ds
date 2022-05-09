#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long ull;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef priority_queue<int> maxPq;
typedef priority_queue<ll, vector<ll>, greater<ll> > minPq;
typedef deque<int> dq;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define deb(x) cout << x << endl;
#define MAX int(10e5 + 1)
#define INF 10000000000

const int MOD = 10e9 + 7;
ll fact[MAX];
int t;
ll curr;

int main()
{
    fact[0] = 1; 
    for (int i = 1; i < MAX; ++i)
        fact[i] = (fact[i-1] * i) % MOD;

    cin >> t;
    while (t--)
    {
        cin >> curr;
        cout << fact[curr] << "\n";
    }
    return 0;
}