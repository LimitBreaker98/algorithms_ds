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

int N,M,Q, a, b, l1, r1, l2, r2;
const int MAX_N = 4001;
const int MAX_DAYS = 100001;
bitset<MAX_N> ar[MAX_DAYS], br[MAX_DAYS], temp, ans;


int main()
{
    cin >> N >> M >> Q;

    // O(MAX_N ** 2) getting all bitsets ready.
    for(int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        if (i >= 1) // copy updates of all previous numbers to new bitset.
            ar[i] = ar[i-1];
        ar[i][x] = !ar[i][x];        
    }

    for(int i = 0; i < M; ++i)
    {
        int x;
        cin >> x;
        if (i >= 1) // copy updates of all previous numbers to new bitset.
            br[i] = br[i-1];
        br[i][x] = !br[i][x];        
    }

    while (Q--)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        l1--; r1--; l2--; r2--;

        if (l1 > 0)
            temp = ar[l1-1] ^ ar[r1];
        else 
            temp = ar[r1];
        if (l2 > 0)
            ans = br[l2-1] ^ br[r2];
        else 
            ans = br[r2];

        ans ^= temp;
        cout << ans.count() << endl;
    }
    return 0;
}