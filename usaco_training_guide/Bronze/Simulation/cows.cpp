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

pii oper(int m1, int m2, int c2) {
    int delt = min(m1, c2 - m2);
    int new_m2 = m2 + delt;
    int new_m1 = m1 - delt;
    return { new_m1, new_m2 };
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    int c1, m1, c2, m2, c3, m3;
    cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;
    int ops = 100;
    for (int i = 0; i < ops; ++i) {
        if (i % 3 == 0) {
            pii res = oper(m1, m2, c2);
            m1 = res.first;
            m2 = res.second;
        }
        else if (i % 3 == 1) {
            pii res = oper(m2, m3, c3);
            m2 = res.first;
            m3 = res.second;
        }
        else {
            pii res = oper(m3, m1, c1);
            m3 = res.first;
            m1 = res.second;
        }
    }
    for (int a : {m1, m2, m3}) {
        cout << a << "\n";
    }

    return 0;
}