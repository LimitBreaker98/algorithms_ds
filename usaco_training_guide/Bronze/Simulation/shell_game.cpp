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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n;
    cin >> n;
    int max_score = 0;

    vector<int> as(n), bs(n), gs(n);

    for(int i = 0; i < n; ++i) {
        cin >> as[i] >> bs[i] >> gs[i];
    }

    for (int rock_pos = 1; rock_pos <= 3; ++rock_pos) {
        int round_score = 0;
        vector<int> here(3, 0);
        here[rock_pos-1] = 1;
        for (int i = 0; i < n; ++i) {
            int p1 = as[i], p2 = bs[i];
            swap(here[p1-1], here[p2-1]);
            int g = gs[i];
            round_score += here[g-1];
        }
        max_score = max(round_score, max_score);
    }
    cout << max_score << "\n";
    return 0;
}