#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5 * 10000 + 1
#define INF 10000000000

int n, m;
vector<int> st; // not visited, active, visited.
vector<unordered_map<int, int>> g; 
vector<pair<int,int>> inp;
vector<pair<int, int>> es;
int colors = 1;
const int ACTIVE = 1, VISITED = 2, UNVISITED = 0;
void dfs(int u)
{
    st[u] = ACTIVE;
    for (auto &v: g[u])
    {
        //cout << "checking " << v.first << " from " << u << endl;
        if (st[v.first] == UNVISITED)
        {
            // color edge (u,v) with 1.
            v.second = 1;
            dfs(v.first);
        }
        else if (st[v.first] == ACTIVE)
        {
            //color edge (u,v) with 2.
            v.second = 2;
            colors = 2;
        }
        else v.second = 1;
    }
    st[u] = VISITED;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    g.assign(n+1, unordered_map<int, int>());
    st.assign(n+1, UNVISITED);
    es.assign(m, {});
    //cout << "G" << endl;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u][v] = -1;
        es[i] = {u,v};
    }
    //cout << "G2" << endl;
    for (int i = 1; i <= n; ++i)
    {
        //cout << "G " << i << endl;
        if (st[i] == UNVISITED)
        {
            dfs(i);
        }
    }
    cout << colors << endl;
    for (pair<int,int> e : es)
        cout << g[e.first][e.second] << " ";
    cout << endl;
    return 0;
}