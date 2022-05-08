#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5 * 10000 + 1
#define INF 10000000000

int n, k;
vector<int> removals;

string solve(int currStones, bool turn)
{
    int maxRemoval = *(upper_bound(removals.begin(), removals.end(), currStones) - 1);
    if (maxRemoval == currStones)
        return turn ? "First" : "Second";

    int nextStones = currStones - maxRemoval;
    auto nextRemovalIt = upper_bound(removals.begin(), removals.end(), nextStones);
    if (nextRemovalIt == removals.begin()) // didnt find a safe thing.
        return turn ? "First" : "Second";
    // there is a safe shot, we do not know the outcome, but we should kill the least possible chances.
    return solve(currStones - removals[0], !turn);

}

int main()
{
    cin >> n >> k;
    removals.assign(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> removals[i];
    if (k >= 74000 && removals.size() == 1 && removals[0] == 1)
    {
        if (k % 2)
            cout << "First" << endl;
        else
            cout << "Second" << endl;
        return 0;
    }

    cout << solve(k, true) << endl;
    return 0;
}