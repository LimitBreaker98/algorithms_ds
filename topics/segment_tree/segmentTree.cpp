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


class SegmentTree
{
    private: 
        int n;
        // KEY: segTree stores the minimum index of a certain range!
        vi rmqSegTree, arr, sumSegTree; // arr is the original array, segTree is the binary heap esque segTree.

        int left(int p) { return p << 1; } // bitshifting by 1 to left is the same as multiplying by 2.
        int right(int p) { return left(p) + 1; }

        void build(int p, int L, int R)
        {
            if (L == R)
            {
                rmqSegTree[p] = L; // this is an index
                sumSegTree[p] = arr[L]; // sum of single element is itself. This is a value.
            }
            else // recursively build children
            {
                build(left(p), L, (L+R)/2); // left half
                build(right(p), (L + R)/2 + 1, R); // right half
                int p1 = rmqSegTree[left(p)], p2 = rmqSegTree[right(p)];
                int sum1 = sumSegTree[left(p)], sum2 = sumSegTree[right(p)];
                rmqSegTree[p] = arr[p1] <= arr[p2] ? p1: p2;
                sumSegTree[p] = sum1 + sum2;
            }
        }
        // i is the index of arr that was updated, p is the index of the corresponding node in the
        // segTree
        void update(int p, int L, int R, int i)
        {
            if (L == R && L == i)
            {
                rmqSegTree[p] = L;
                sumSegTree[p] = arr[L];
            }
            else // recursively look for the leaf node in the correct half of the current L,R range
            {
                int midLeft = (L+R)/2;
                int midRight = midLeft + 1;

                if (i > midLeft)
                    update(right(p), midRight, R, i);
                else
                    update(left(p), L, midLeft, i);
                int p1 = left(p), p2 = right(p);
                rmqSegTree[p] = arr[p1] <= arr[p2] ? p1: p2;
                sumSegTree[p] = sumSegTree[p1] + sumSegTree[p2];
            }
        }

        int rmq(int p, int L, int R, int i, int j)
        {
            // check if i, j outside range L, R
            if (i > R || j < L) return -1; // invalid position so we can discard it. 
            // check if L, R completely inside i, j.
            if (L >= i && R <= j) return rmqSegTree[p]; // don't recur further down the tree, we have the ans.

            // recursively check both halves
            int p1 = rmq (left(p), L, (L+R)/2, i, j);
            int p2 = rmq (right(p), (L+R)/2 + 1, R, i, j);

            if (p1 == -1) return p2;
            if (p2 == -1) return p1;
            return arr[p1] <= arr[p2] ? p1 : p2;
        }

        int rsq(int p, int L, int R, int i, int j)
        {
            if (i > R || j < L) return 0; // sum of empty range is 0.
            // check if L, R completely inside i, j.
            if (L >= i && R <= j) return sumSegTree[p];
            
            // recursively add both halves
            int sum1 = rsq(left(p), L, (L + R) / 2, i, j);
            int sum2 = rsq(right(p), (L + R) / 2 + 1, R, i, j);

            return sum1 + sum2;
        }
    public: 
        SegmentTree(const vi & inArr)
        {
            arr = inArr;
            n = arr.size();
            rmqSegTree.assign(4*n, 0); // arbitrary, big enough size for bin heap representation.
            sumSegTree.assign(4*n, 0); // same as above :)
            build(1, 0, n-1); // one based head node is index = 1.
        }
        int rmq(int i, int j) 
        {
            return rmq(1, 0, n-1 , i , j);
        }
        int rsq(int i, int j)
        {
            return rsq(1, 0, n-1, i, j);
        }
        void update(int value, int i)
        {
            arr[i] = value; // update actual array
            update(1, 0, n-1, i); // update segTree bin heap representation.
        }
        void checkCurrArr()
        {
            for (int elem: arr) cout << elem << " ";
            cout << '\n';
        }
};

// main to test segTree structure.
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {18, 17, 13, 19, 15, 11, 20 };
    vi copyArr (arr, arr + sizeof(arr)/sizeof(int));
    SegmentTree st(copyArr);
    cout << "RMQ(1,3) = "  << st.rmq(1,3) << " index " << '\n';
    cout << "RMQ(4,6) = "  << st.rmq(4,6) << " index " << '\n';
    cout << "here\n";
    st.checkCurrArr();
    cout << "\n";
    int arr2[] = {3, 2, 4, -3, 7, 9};
    vi copyArr2 (arr2, arr2 + sizeof(arr2)/sizeof(int));
    SegmentTree st2(copyArr2);
    cout << "RANGE SUM QUERIES!" << '\n';
    cout << "RMQ(0,3) = "  << st2.rsq(0,3) << '\n';
    cout << "RMQ(3,4) = "  << st2.rsq(3,4) << '\n';
    
    cout << "\nbefore updating\n";
    st2.checkCurrArr();
    cout << st2.rmq(0, 5);
    // updating queries
    // now is {3, 30, 4, 100, 7, 9};
    cout << "\nafter updating\n";
    st2.update(100, 3);
    st2.update(30, 1);
    st2.checkCurrArr();
    cout << "RMQ(0,5) = " << st2.rmq(0,5) << '\n'; // should be 1

    return 0;
}