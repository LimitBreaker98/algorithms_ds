#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long ull;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef priority_queue<int> maxPq;
typedef priority_queue<ll, vector<ll>, greater<ll>> minPq;
typedef deque<int> dq;
// SR means Same Reasoning

/*
 * Binary search variant to look exactly for an element
 * Returns pos of element inside array v, -1 if not found
 * Pre: v is sorted ascendingly
 * [1, 3, 9, 29, 34, 55]
 */
int exactSearch(vector<int> &v, int target)
{
    int n = v.size();
    int lo = 0, hi = n - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (v[mid] == target)
            return mid;
        else if (v[mid] > target)
            hi = mid - 1; // -1 because value at mid simply doesn't work!
        else
            lo = mid + 1; // SR
    }
    return -1;
}

/*
 * Returns the position of the immediate next element greater than target
 * Returns pos of element inside array v, -1 if not found
 * Pre: v is sorted ascendingly
 * [1, 3, 9, 29, 34, 55]
*/
int upperBound(vector<int> &v, int target)
{
    int n = v.size();
    int lo = 0, hi = n - 1;
    int pos = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

        if (v[mid] > target) // candidate answer, discard right
        {
            pos = mid;
            hi = mid - 1;
        }
        else // less than or equal to target... just update range
            lo = mid + 1;
    }
    return pos;
}
/*
 * Returns the position of the immediate prev element less than target
 * Returns pos of element inside array v, -1 if not found
 * Pre: v is sorted ascendingly
 * [1, 3, 9, 29, 34, 55]
*/
int lowerBound(vector<int> &v, int target)
{
    int n = v.size();
    int lo = 0, hi = n - 1;
    int pos = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (v[mid] < target) // candidate ans, discard left!
        {
            pos = mid;
            lo = mid + 1;
        }
        else // just update range
            hi = mid - 1;
    }
    return pos;
}

/*
 * Returns the greatest position of an element that does not compare greater than target
 * Returns pos of element inside array v, -1 if not found
 * Pre: v is sorted ascendingly
 * [1, 3, 9, 29, 34, 55]
*/
int lowerEqualBound(vector<int> &v, int target)
{
    int n = v.size();
    int lo = 0, hi = n - 1;
    int pos = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (v[mid] <= target) // discard everything to the left
        {
            pos = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return pos;
}

/*
 * Returns the minimum position of an element that does not compare less than target
 * Returns pos of element inside array v, -1 if not found
 * Pre: v is sorted ascendingly
 * [1, 3, 9, 29, 34, 55]
*/
int upperEqualBound(vector<int> &v, int target)
{
    int n = v.size();
    int lo = 0, hi = n - 1;
    int pos = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (v[mid] >= target)
        {
            pos = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return pos;
}

/**
 * Find amount of numbers in range [l, r]
 * Strat: Run 2 binary searches, finding first element greater than or equal to l
 * and last element less than or equal to r
*/

int countInRange(vector<int> &v, int l, int r)
{
    int n = v.size();
    int rPos = lowerEqualBound(v, r);
    int lPos = upperEqualBound(v, l);
    if (lPos == -1 || rPos == -1)
        return 0;
    return rPos - lPos + 1;
}

void printTC(int target, int pos)
{
    cout << target << " at pos " << pos << "\n";
}

void printInRange(int l, int r, int ans)
{
    cout << ans << " elements in range " << l << " " << r << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    //0                                    11
    vector<int> tc1 = {1, 1, 1, 3, 3, 9, 29, 29, 34, 34, 55, 55};
    printInRange(2, 30, countInRange(tc1, 2, 30 )); // 5
    printInRange(0, 56, countInRange(tc1, 0, 56 )); // 12
    printInRange(3, 34, countInRange(tc1, 3, 34 )); // 7
    printInRange(9, 54, countInRange(tc1, 9, 54 )); // 5
    printInRange(3, 29, countInRange(tc1, 3, 29 )); // 5
    printInRange(3, 30, countInRange(tc1, 3, 30 )); // 5
    printInRange(1, 33, countInRange(tc1, 1, 33 )); // 8

    /* printTC(2132, greaterEqualBound(tc1, 2132));
    printTC(29, greaterEqualBound(tc1, 29));
    printTC(55, greaterEqualBound(tc1, 55));
    printTC(3, greaterEqualBound(tc1, 3));
    printTC(5, greaterEqualBound(tc1, 5));
    printTC(2, greaterEqualBound(tc1, 2));
    printTC(34, greaterEqualBound(tc1, 34)); 
    printTC(40, greaterEqualBound(tc1, 40)); */
    return 0;
}