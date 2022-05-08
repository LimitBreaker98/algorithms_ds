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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;

    map<char, int> cnt;
    for(char c : s) {
        cnt[c]++;
    }

    char odd_char = 'a';
    for (auto char_count : cnt) {
        if (char_count.second % 2) {
            if (odd_char != 'a') {
                cout << "NO SOLUTION\n";
                return 0;
            }
            odd_char = char_count.first;
        }
    }

    deque<char> palindrome;
    if (odd_char != 'a') {
        palindrome.push_back(odd_char);
        cnt[odd_char]--;
    }
    for (auto char_count : cnt) {
        int letter_amount = char_count.second;
        char c = char_count.first;
        for (int i = 0; i < letter_amount/2; ++i){
            palindrome.push_back(c);
            palindrome.push_front(c);
        }
    }

    for (char c: palindrome) {
        cout << c;
    }
    cout << "\n";

    return 0;
}