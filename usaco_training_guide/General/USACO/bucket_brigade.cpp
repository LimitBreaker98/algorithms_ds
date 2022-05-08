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

bool is_between(int l, int mid, int r) {
    if (l > r)
        swap(l, r);
    return l < mid && mid < r;
}

void print_point(pii& x) {
    cout << x.first << " " << x.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    const int rows = 10;
    const int cols = 10;
    pii pos_R = {-1, -1};
    pii pos_L = {-1, -1};
    pii pos_B = {-1, -1};
    for (int r_idx = 0; r_idx < rows; ++r_idx) {
        string row; cin >> row;
        for (int c_idx = 0; c_idx < cols; ++c_idx) {
            if (row[c_idx] == 'R') {
                pos_R = {r_idx, c_idx};
            }
            if (row[c_idx] == 'L') {
                pos_L = {r_idx, c_idx};
            }
            if (row[c_idx] == 'B') {
                pos_B = {r_idx, c_idx};
            }
        }
    }

    // print_point(pos_L);
    // print_point(pos_B);
    // //print_point(pos_R);
    bool shared_row = pos_L.first == pos_B.first && pos_L.first == pos_R.first;
    bool shared_col = pos_L.second == pos_B.second && pos_L.second == pos_R.second;
    bool rock_intercepts_route = false;
    if (shared_row) {
        rock_intercepts_route = is_between(pos_L.second, pos_R.second, pos_B.second);
        //cout << "rock interrupts, same row\n";
    }
    else if (shared_col) {
        rock_intercepts_route = is_between(pos_L.first, pos_R.first, pos_B.first);
        //cout << "rock interrupts, same col\n";
    }


    int diff = abs(pos_L.first - pos_B.first) + abs(pos_L.second - pos_B.second) - 1;
    if (rock_intercepts_route) {
        diff += 2;
    }
    cout << diff << "\n";
    return 0;
}