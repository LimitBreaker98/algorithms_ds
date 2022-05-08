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
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int M, N, K;
    cin >> M >> N >> K;
    for (int i = 0; i < M; ++i) {
        string s; 
        cin >> s;
        string s2 = "";
        for (char c : s) {
            for(int k = 0; k < K; ++k) {
                s2 += c;
            }
        }
        for(int k = 0; k < K; ++k) {
            cout << s2 << "\n";
        }  
        
    }
    return 0;
}