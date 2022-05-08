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
#define endl "\n"

vector<vector<int>> ST;
vector<int> lg;
int RMQ(int l, int r)
{
    int pwr = lg[r - l + 1];
    return min(ST[l][pwr], ST[r - (1 << pwr) + 1][pwr]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 25; // powers of 2 to be considered
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &a: arr) cin >> a;
    ST.assign(n, vi(k+1));

    // precompute all logarithms to have RMQ in O(1)
    lg.assign(n+1, 0);
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i/2] + 1;
        
    // step 0, base case
    for (int i = 0; i < n; ++i)
        ST[i][0] = arr[i];
    // Step 1, build ST iteratively, recalling the recursive relation of RMQs
    // Build ST for all indices and for all powers of 2 length.
    for (int pwr = 1; pwr <= k; ++pwr)
    {
        for (int i = 0; i + (1 << pwr) <= n; ++i)
        {
            ST[i][pwr] = min(ST[i][pwr-1], ST[i + (1 << (pwr-1))][pwr-1]);
        }
    }

    int q;
    cin >> q;
    while(q--)
    {
        int l, r; cin >> l >> r;
        cout << RMQ(l, r) << endl;
    }
        

    // step 2, answer RMQ's :D

   


    
    return 0;
}