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

/* 
    Stack to get current minimum value of the stack in O(1)
    Problem: Multi queried minimum value
    Query 1: get minimum
    Query 2: remove element from stack
    Query 3: add element to stack
    All in O(1)
    We don't lose any information at any step of the problem with this implementation
*/

void removeLast(stack<pii>& st)
{
    st.pop();
}
int getMin(stack<pii>&st)
{
    return st.empty() ? -1 : st.top().second;
}
void addElement(stack<pii>&st, int element)
{
    int newMin = st.empty() ? element: min(element, st.top().second);
    st.push({element, newMin});
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    stack<pii> st; // pair is (element, minimum in stack from current element downwards)
    addElement(st, 10);
    assert (getMin(st) == 10);
    addElement(st, 30);
    assert (getMin(st) == 10);
    addElement(st, 5);
    assert (getMin(st) == 5);
    st.pop();
    assert (getMin(st) == 10);
    st.pop();
    assert (getMin(st) == 10);
    st.pop();
    assert (getMin(st) == -1);

    return 0;

}