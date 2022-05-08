#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5 * 10000 + 1
#define INF 10000000000

int h, w;
const int MOD = int(1e9)+7;

int wall(char c)
{
    return c == '#' ? 1:0;
}

int main()
{
    cout << setprecision(10) << endl;
    cin >> h >> w;
    char mat[h][w];
    ll dp[h][w];
    memset(dp, 0LL, sizeof(dp));

    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> mat[i][j];
    
    dp[1][0] = !wall(mat[1][0]);
    dp[0][1] = !wall(mat[0][1]);


    
    for (int r = 0; r < h; ++r)
    {
        for (int c = 0; c < w; ++c)
        {
            if (wall(mat[r][c]))
                continue;
            if (r - 1 >= 0)
                dp[r][c] += dp[r-1][c];
            if (c - 1 >= 0)
                dp[r][c] += dp[r][c-1];
            dp[r][c] %= MOD;
        }
    }

   /*  for (int r = 0; r < h; ++r)
    {    
        for (int c = 0; c < w; ++c)
            cout << dp[r][c] << " ";
        cout << endl;
    } */
    cout << dp[h-1][w-1] << endl;
    return 0;
}