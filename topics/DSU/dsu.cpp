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

vi parent;
int curr;
vi sz;
vi mn, mx;
int get(int v)
{
    if (parent[v] == v)
        return v;
    /*
        Super slow!
        -> return findSet(parent[v]); 
        This does not update the parent of a long chain of nodes to point directly to the leader of the group
    */
    return parent[v] = get(parent[v]); // stack unwinding! Makes O(log n) time complexity.
}

void unionSet(int a, int b)
{
    a = get(a);
    b = get(b);
    /* 
        We should always merge trees in a smart way.
        This means, attach the smallest tree to the biggest tree. 
        if (a != b)
        parent[b] = a; 
     */
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        mn[a] = min(mn[a], mn[b]);
        mx[a] = max(mx[a], mx[b]);
    }
}

int n, m;
int main()
{
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    parent.assign(n+1, 0);
    sz.assign(n+1, 1); // initially all sets are disjoint, so every size is 1.
    mn.assign(n+1, 0);
    mx.assign(n+1, 0);

    for (int i = 1; i <= n; ++i)
        parent[i] = mn[i] = mx[i] = i; // parent, min and max of a set of element i is just i.

    string op;
    int a, b;
    while(m--)
    {
        cin >> op;
        if (op[0] == 'u')
        {
            cin >> a >> b;
            unionSet(a, b);
        }   
        else
        {
            cin >> a;
            cout << mn[get(a)] << " " << mx[get(a)] << " " << sz[get(a)] << "\n";
        }
    }
    return 0;
}