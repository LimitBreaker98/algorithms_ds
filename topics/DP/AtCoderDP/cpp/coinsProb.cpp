#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5 * 10000 + 1
#define INF 10000000000
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(12) << endl;
    cin >> n;
    vector<double> prob(n + 1); // prob[i], i heads so far. 
    prob[0] = 1;
    for (int c = 0; c < n; ++c)
    {
        double currP;
        cin >> currP;
        for (int i = c + 1; i >= 0; --i)
        {
            prob[i] *= (1 - currP);
            if (i > 0)
                prob[i] += prob[i-1] * currP;
        }
    }
    double ans = 0.0;
    for(int i = n/2 + 1; i <= n; ++i)
        ans += prob[i];
    cout << ans << endl;
    return 0;
}