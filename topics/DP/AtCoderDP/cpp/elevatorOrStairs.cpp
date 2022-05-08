#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5 * 10000 + 1
#define INF 1000000000

int n, c;
vector<int> a, b;

// fix by passing if the elevator was already taken previously.
int leastCost(int floor, bool taken)
{
    if (floor == 0)
        if (taken)
            return c;
        else
            return 0;
    

    if (taken)
        return min(a[floor-1], b[floor-1]) + leastCost(floor-1, taken);
    return min(a[floor-1], b[floor-1] + c) + leastCost(floor-1, taken);
}


int main()
{
    cin >> n >> c;
    a.assign(n, 0);
    b.assign(n, 0);
    for(int i = 0; i < n-1; ++i)
        cin >> a[i];
    for(int i = 0; i < n-1; ++i)
        cin >> b[i];

    for(int i = 0; i < n; ++i)
        cout << min(leastCost(i, true), leastCost(i, false)) << " ";
    cout << endl;
    return 0;
}