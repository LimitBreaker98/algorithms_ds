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

/*
    Requisite: Graph is a tree!
    Linear time diameter
    Run BFS from any node, find furthest node, then run BFS from that one and 
    it will always be the diameter of the tree. 
*/

vector<vector<int>> g;
vector<bool> vis, vis2;
vector<int> dist, dist2;
int bfs(int src, vector<bool> &vis, vector<int> &dist)
{
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    int last;
    while(!q.empty())
    {
        int curr = q.front();
        vis[curr] = true;
        q.pop();
        for (int nei: g[curr])
        {
            if (!vis[nei])
            {
                q.push(nei);
                dist[nei] = dist[curr] + 1;
            }
        }
        last = curr;
    }
    return last;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n;
    e = n - 1;
    g.assign(n, vi());
    vector<bool> vis, vis2;
    vector<int> dist, dist2;
    vis.assign(n, false);
    vis2.assign(n, false);
    dist.assign(n, 0);
    dist2.assign(n, 0);
    for (int i = 0; i < e; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    if (e == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    int endPt = bfs(0, vis, dist);
    vis.assign(n, false);
    int end1 = bfs(endPt, vis, dist);
    int end2 = bfs(end1, vis2, dist2);
    for (int i = 0; i < n; ++i)
    {
        if (dist[i] == dist[end1] || dist2[i] == dist2[end2])
        {
            cout << dist[end1] + 1 << endl;
        }
        else   
            cout << dist[end1] << endl; 
    }

    return 0;
}