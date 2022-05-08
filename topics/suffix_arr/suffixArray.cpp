#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long ull;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef priority_queue<int> maxPq;
typedef priority_queue<ll, vector<ll>, greater<ll>> minPq;
typedef deque<int> dq;

// returns first pos of an element greater than or equal to me
int upperEqualBound(string &s, vector<int> &pos, string &sbstr)
{
    int n = s.size();
    int lo = 0, hi = n - 1;
    int posAns = -1;
    int sbstrLen = sbstr.size();
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        string currSubstr = s.substr(pos[mid], sbstrLen);
        int cmp = currSubstr.compare(sbstr);
        if (cmp >= 0)
        {
            posAns = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    return posAns;
}

int lowerEqualBound(string &s, vector<int> &pos, string &sbstr)
{
    int n = s.size();
    int lo = 0, hi = n - 1;
    int posAns = -1;
    int sbstrLen = sbstr.size();
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        string currSubstr = s.substr(pos[mid], sbstrLen);
        int cmp = currSubstr.compare(sbstr);
        if (cmp <= 0)
        {
            posAns = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }

    return posAns;
}

bool containsSubstr(string &s, vector<int> &pos, string &sbstr)
{
    int lo = 0;
    int hi = pos.size() - 1;
    //cout << hi << " is hi\n";
    int sbstrLen = sbstr.length();
    //cout << sbstrLen << " is substring length\n";
    while (lo <= hi)
    {
        int mid = (hi + lo) / 2;
        //cout << mid << "is mid\n";
        string currSubstr = s.substr(pos[mid], sbstrLen);

        int cmp = currSubstr.compare(sbstr);
        if (cmp == 0)
            return true;
        if (cmp > 0)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return false;
}

void radixSort(vector<pair<pair<int, int>, int>> &v)
{
    int n = v.size(); // at most, we are going to have n equivalence classes!
    vector<int> cnt(n);

    for (auto x : v)
        cnt[x.first.second]++; // counting sort by second element

    // buckets are a mental construct, implemented by adding elements in right place
    // use auxiliar array pos[0...n-1] to keep track of which position an element of ith bucket has
    // to be added in.
    vector<int> pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; ++i)
        pos[i] = pos[i - 1] + cnt[i - 1];

    vector<pair<pair<int, int>, int>> vNew(n);
    for (auto x : v)
    {
        int i = x.first.second; // second number of tuple.
        vNew[pos[i]++] = x;
    }

    // sorted by second, now we gotta do it by first element in tuple
    v = vNew;
    cnt.assign(n, 0);
    for (auto x : v)
        cnt[x.first.first]++; // counting sort by first element

    pos[0] = 0;
    for (int i = 1; i < n; ++i)
        pos[i] = pos[i - 1] + cnt[i - 1];

    for (auto x : v)
    {
        int i = x.first.first; // second number of tuple.
        vNew[pos[i]++] = x;
    }
    v = vNew;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    string s;
    string s2;
    cin >> s;
    cin >> s2;
    s += "#";
    int cutPosition = s.size();
    cutPosition--;
    s.append(s2);
    s += "$";
    int n = s.size();

    vector<int> pos(n), c(n);

    vector<pair<char, int>> a2(n); // Tuples letter, position on original string
    for (int i = 0; i < n; ++i)
        a2[i] = {s[i], i};
    sort(a2.begin(), a2.end());

    // pos[i] gives index on original string!
    for (int i = 0; i < n; ++i)
        pos[i] = a2[i].second;

    // build equivalence classes of original positions!
    // k = 0
    c[pos[0]] = 0; // c[6] = 0
    for (int i = 1; i < n; ++i)
    {
        if (a2[i].first == a2[i - 1].first)
            c[pos[i]] = c[pos[i - 1]];
        else
            c[pos[i]] = c[pos[i - 1]] + 1;
    }

    int k = 0; // k being 0 makes k to k+1 substring first.
    while ((1 << k) < n)
    {
        vector<pair<pair<int, int>, int>> a(n); // equivClass tuple, original pos
        for (int i = 0; i < n; ++i)
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};

        radixSort(a); // linear
        // update positions
        for (int i = 0; i < n; ++i)
            pos[i] = a[i].second;
        // assign equivalence classes depending on tuples
        c[pos[0]] = 0; // eqc[6] = 0
        for (int i = 1; i < n; ++i)
        {
            if (a[i].first == a[i - 1].first)
                c[pos[i]] = c[pos[i - 1]];
            else
                c[pos[i]] = c[pos[i - 1]] + 1;
        }
        k++;
    }

    vector<int> lcp(n);
    k = 0; // common characters of prefix.
    for (int i = 0; i < n; ++i)
    {
        int posx = c[i];
        if(posx == 0)
        {
            k = 0;
            continue;
        }
        int j = pos[posx - 1];

        while (s[i + k] == s[j + k])
            ++k;
        lcp[posx] = k;
        k = max(k - 1, 0);
    }

    int bestSoFar = -1;
    int bestPos = -1;
    for (int i = 1; i < n; ++i)
    {
        int prevPos = pos[i - 1];
        int currPos = pos[i];
        if (prevPos > currPos)
            swap(prevPos, currPos);
        if (lcp[i] > bestSoFar && cutPosition > prevPos && cutPosition < currPos)
        {
            bestSoFar = lcp[i];
            bestPos = pos[i];
        }
    }
    
    if (bestSoFar == -1)
        cout << '\n';
    else
    {
        string ans = s.substr(bestPos, bestSoFar);
        cout << ans << '\n';
    }
        
    return 0;
}