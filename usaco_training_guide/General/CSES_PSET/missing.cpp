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
    int n;
    cin >> n;
    vector<int> nums(n-1);
    for (int &a: nums)
        cin >> a;
    
    sort(nums.begin(), nums.end());

    for (int i = 1; i < n-1; ++i) {
        int curr = nums[i];
        int prev = nums[i-1];
        if (curr - prev != 1) {
            cout << prev + 1 << "\n";
            return 0;
        }

    }
    if (nums[n-2] == n) {
        cout << "1\n";
    }
    else {
        cout << n << "\n";
    }
    return 0;
}