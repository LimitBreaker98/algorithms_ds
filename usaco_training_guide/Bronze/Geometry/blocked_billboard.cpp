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


struct Rect {
	int x1, y1, x2, y2;
	int area() {
		return (y2 - y1) * (x2 - x1); 
	}
};

int intersect(Rect a, Rect b) {
    int xIntersection = max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
    int yIntersection = max(0, min(a.y2, b.y2) - max(a.y1, b.y1));
    return xIntersection * yIntersection;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Rect a, b, t;
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;

    
    int total = a.area() + b.area() - intersect(a, t) - intersect(b,t);
    cout << total << "\n";
    return 0;
}