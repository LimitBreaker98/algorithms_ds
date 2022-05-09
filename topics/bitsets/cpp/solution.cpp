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
#define MAX 5 * 10000 + 1
#define INF 10000000000
const long Max = 1LL << 31;
vector<bool> res(Max);
int main()
{
  cin.sync_with_stdio(false);
  long long ans = 0;
  int n;
  long long s, a, b;
  int S;
  cin >> n >> s >> a >> b;
  for (int i = 1; i <= n; ++i)
  {
    if (s & 1)
    {
      S = s / 2;
      if (!res[S])
      {
        ans += S;
        res[S] = 1;
      }
    }
    else
    {
      S = s / 2;
      if (res[S])
      {
        ans -= S;
        res[S] = 0;
      }
    }
    s = (s * a + b) % Max;
  }
  cout << ans;
}