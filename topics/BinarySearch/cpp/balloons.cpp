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
int n, m;
int worstTime = int(1e8);


int numBalloons(int time, int index, vector<int>& inflateTime, vector<int>& saturation, vector<int>& restTime)
{
    int completeCycles = time/(inflateTime[index] * saturation[index] + restTime[index]);
    int cycleTime = inflateTime[index] * saturation[index] + restTime[index];
    int remainderTime = time - (completeCycles * cycleTime);
    int balloons = completeCycles * saturation[index] + min(remainderTime / inflateTime[index], saturation[index]); 
    return balloons;
}

int totalBalloons(int time, vector<int>& inflateTime, vector<int>& saturation, vector<int>& restTime, vector<int>& balloonsPerPerson) // O(n)
{
    ll total = 0;
    for (int i = 0; i < n; ++i)
    {
        balloonsPerPerson[i] = ll(numBalloons(time, i, inflateTime, saturation, restTime));
        total += balloonsPerPerson[i];
    }
    return total;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    vector<int> inflateTime(n), saturation(n), restTime(n), balloonsPerPerson(n);
    for (int i = 0; i < n; ++i)
        cin >> inflateTime[i] >> saturation[i] >> restTime[i];
    int r = worstTime;
    int l = 1;
    int ans = -1;
    if (m == 0)
    {
        cout << "0\n0" << endl;
        return 0;
    }
    while (l <= r)
    {
        int time = (l + r) / 2;
        if (totalBalloons(time, inflateTime, saturation, restTime, balloonsPerPerson) >= m) // I can decrease the finish time, current time is a candidate answer!
        {
            ans = time;
            r = time - 1;
            
        }
        else // I need to increase the finish time, current time did not work so exclude it 
        {
            l = time + 1;
        }
    }

    cout << ans << endl;
    totalBalloons(ans, inflateTime, saturation, restTime, balloonsPerPerson);

    for (int balloons : balloonsPerPerson)
    {
        cout << min(balloons, m) << " ";
        m -= min(balloons, m);
    }
    cout << endl;

    return 0;
}