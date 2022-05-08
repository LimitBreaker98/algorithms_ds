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

void print_ln(vector<string>& ln) {
    int last_word_idx = ln.size() - 1;
    for (int i = 0; i <= last_word_idx; ++i) {
        cout << ln[i];
        if (i != last_word_idx) {
            cout << " ";
        }
    }
    cout << "\n";
    ln.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int sz = 0;
    vector<string> ln;

    for (int i = 0; i < n; ++i) {
        string s = "";
        cin >> s;
        int sz_s = s.size();
        if (sz + sz_s <= k) {
            sz += sz_s;
            ln.push_back(s);
        }
        else {
            print_ln(ln);
            ln.push_back(s);
            sz = sz_s;
        }
    }
    print_ln(ln);

    return 0;
}