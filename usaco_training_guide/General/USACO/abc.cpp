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
    int n = 7;

    vector<ll> nums(n);
    for (ll &a: nums)
        cin >> a;
    sort(nums.begin(), nums.end());

    int i = 2;
    while(nums[0] + nums[1] + nums[i] != nums[n-1]) {
        i++;
    }
    cout << nums[0] << " " << nums[1] << " " << nums[i] << "\n";
    return 0;
}