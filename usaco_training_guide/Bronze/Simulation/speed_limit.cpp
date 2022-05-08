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

struct Road {
    int len, limit;
};

struct Seg {
    int len, spd;
};

int get_min_speed(vector<Road> &roads, int from, int to) {
    int ans = 1e8;
    while(from < to) {
        Road curr = roads.back();
        ans = min(ans, curr.limit);
        from += curr.len;
        roads.pop_back();
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<Road> roads(n);
    for(int i = 0; i < n; ++i) {
        cin >> roads[i].len >> roads[i].limit;
    }
    reverse(roads.begin(), roads.end());
    vector<Seg> segs(m);
    for(int i = 0; i < m; ++i) {
        cin >> segs[i].len >> segs[i].spd;
    }
    int curr_s_idx = 0;
    int from = 0;
    int bst = -1;
    while(curr_s_idx < m) {
        Seg curr_seg = segs[curr_s_idx];
        int to = from + curr_seg.len;
        cout << "to " << to << " \n";
        int min_allowed_spd = get_min_speed(roads, from, to);
        cout << "min allowed spd " << min_allowed_spd << " \n";
        bst = max(bst, curr_seg.spd - min_allowed_spd);
        curr_s_idx++;
        from = to;
        cout << bst << "\n";
    }
    cout << bst << "\n";
    return 0;
}