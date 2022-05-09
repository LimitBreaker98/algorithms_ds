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
#define MAX 210
#define INF 10000000000

vector<vi> graph;
int t, sz, edges;
int color[MAX];
int black, white;
const int UNVISITED = -1;

bool bipartiteComponent(int s)
{
    bool colorable = true;
    black = white = 0;
    color[s] = 0;
    black++;
    stack<int> st; //dfs without relying on recursive stack.
    st.push(s);
    while (colorable && !st.empty())
    {
        int curr = st.top();
        st.pop();
        for (int neighbor : graph[curr])
        {
            if (color[neighbor] == UNVISITED)
            {
                color[neighbor] = 1 - color[curr];
                if (color[neighbor] == 0)
                    black++;
                else
                    white++;
                st.push(neighbor);
            }
            else if (color[neighbor] == color[curr])
                colorable = false;
        }
    }
    return colorable;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--)
    {
        cin >> sz;
        graph.assign(sz + 1, vi());
        memset(color, UNVISITED, sizeof(color));
        for (int i = 1; i <= sz; ++i)
        {
            cin >> edges;
            for (int j = 0; j < edges; ++j)
            {
                int a;
                cin >> a;
                if (a > sz) continue;
                graph[i].push_back(a);
                graph[a].push_back(i);
            }
        }

        /* for (int i = 1; i <= sz; ++i)
        {
            for (int neigh: graph[i])
                cout << "edge " << i << "-" << neigh << endl;
        } */
        int ans = 0;
        for (int i = 1; i <= sz; ++i)
        {
            if (color[i] == UNVISITED)
            {
                if (bipartiteComponent(i))
                    ans += max(black, white);
            }
        }
        cout << ans << endl;
    }
}