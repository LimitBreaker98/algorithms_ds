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
const int mxm = 2e5 + 10;
vi parent(mxm), sz(mxm, 1), expPts(mxm), prevParent(mxm);


int get(int a)
{
    if (a == parent[a]) return parent[a];
    return parent[a] = get(parent[a]);
}


void unionSet(int a, int b)
{
    a = get(a), b = get(b);
    if (a != b)
    {
        if (a < b) swap(a, b);
        prevParent[b] = parent[b];
        parent[b] = a;
        sz[a] += sz[b];
        expPts[parent[b]] -= expPts[a];
    }
}

int n, m;
int main()
{
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        prevParent[i] = parent[i] = i;
    string op;
    int x, y, v;
    queue<pii> joins;
    while(m--)
    {
        cin >> op;
        if (op[0] == 'a')
        {
            while(!joins.empty())
            {
                unionSet(joins.front().first, joins.front().second);
                joins.pop();
            }
            cin >> x >> v;
            expPts[get(x)] += v; 
        }
        else if (op[0] == 'j')
        {
            cin >> x >> y;
            joins.push({x, y});
        }
        else
        {
            cin >> x;
            
            if (get(x) == x) cout << expPts[x] << "\n";
            else cout << expPts[x] + expPts[prevParent[x]] << "\n";
        } 
    }
    return 0;
}