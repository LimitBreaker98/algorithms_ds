#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5 * 10000 + 1
#define INF 10000000000
 
int n,h,l,r,a;
vector<int> times;
vector<vector<int>> dp(3000, vector<int>(3000, -1));
 
bool inRange(int x)
{
    return x <= r && x >= l;
}
 
int countTimes(int index, int currTime)
{
    if (index == n)
        return 0;
    if (dp[index][currTime] != -1)
        return dp[index][currTime];
    int ans = 0;
    for (int nextT = times[index] - 1; nextT <= times[index]; ++nextT)
    {
        int t = (currTime + nextT) % h;
        int val = inRange(t) + countTimes(index + 1, t);
        ans = max(ans, val);
    }
    return dp[index][currTime] = ans;
}
 
 
 
int main()
{
    cin >> n >> h >> l >> r;
    times.assign(n, 0);
    int prev = 0;
    for (int i = 0; i < n; ++i)
        cin >> times[i];
    cout << countTimes(0, 0) << endl;
    return 0;
}