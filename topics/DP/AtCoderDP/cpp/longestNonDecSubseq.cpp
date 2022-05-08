#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5 * 10000 + 1
#define INF 10000000000

vector<int> dp(1000, 1); // dp[i] = the maximum length non decreasing subsequence ending with number nums[i].
vector<int> nums;
int szLongestNonDecrSubsq()
{
    int sz = nums.size();
    dp[0] = 1;
    for (int r = 1; r < sz; ++r)
    {
        for (int l = 0; l < r; ++l)
        {
            if (nums[l] <= nums[r])
                dp[r] = max(dp[r], dp[l] + 1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}



int main()
{
    int n;
    cin >> n;
    nums.assign(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    
    for (int elem: nums) cout << elem << " ";
    cout << endl;
    cout << szLongestNonDecrSubsq() << endl;

    return 0;
}