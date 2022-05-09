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

const ll MAX_W = 1LL << 32;
bitset<MAX_W> nums;
ll a,b,s;
int n, q;
long long sum;

void updateNum()
{
    s = (a*s+b) % MAX_W;
}

int main()
{
    cin >> q >> s >> a >> b;
    while(q--)
    {
        int si = s >> 1;
        if (s % 2 == 0)
        {
            if (nums[si])
            {
                sum -= si;
                nums[si] = false;
            }
        }
        else
        {
            if (!nums[si])
            {
                sum += si;
                nums[si] = true;
            }
        }
        //cout << "sum is: " << sum << endl;
        updateNum();
    }

    cout << sum << endl;
    return 0;
}