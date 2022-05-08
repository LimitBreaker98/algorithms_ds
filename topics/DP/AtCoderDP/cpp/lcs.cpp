#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define MAX 5 * 10000 + 1
#define INF 10000000000
const int MAX_LEN = 3001;
string s, t;
vector<vector<int>> dp(MAX_LEN, vector<int>(MAX_LEN, 0));

vector<char> ans;

void reconstruct(int r, int c)
{
    //cout << r << " " << c << endl;
    if (r == 0 || c == 0) return;
    if (s[r-1] == t[c-1])
    {
        reconstruct(r-1, c-1);
        ans.push_back(s[r-1]);
    }
    else if (dp[r][c] == dp[r-1][c]) // JUEPUTA VIDA JAJAJAJA
        reconstruct(r-1, c);
    else
        reconstruct(r, c-1);
}


int main()
{ 
    cin >> s >> t;
    int len_s = s.length();
    int len_t = t.length();
    
    for (int i = 1; i <= len_s; ++i)
        for (int j = 1; j <= len_t; ++j)
            if (s[i-1] == t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    
    /* for(int r = 1; r <= len_s; ++r)
        for (int c = 1; c <= len_t; ++c)
            cout << dp[r][c] << " ";
        cout << endl; */
    //cout << dp[len_s][len_t] << endl;
    reconstruct(len_s, len_t);
    for (char elem: ans)
        cout << elem;
    cout << endl;
    return 0;

}