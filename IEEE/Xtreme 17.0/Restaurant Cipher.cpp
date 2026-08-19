#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

template <typename T>
void print(vector<T> &array) {
    for (auto &it : array) {
        cout << it << " ";
    }
    cout << "\n";
}

signed main() {
    fastio;
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        map<char, int> mp;
        string s;
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'g') {
                mp[s[i]]++;
            }
        }
        char key;
        int maximum = -1;
        for (auto it : mp) {
            if (maximum < it.second) {
                key = it.first;
                maximum = it.second;
            }
        }
        cout << (char)toupper(key) << "\n";
    }

    return 0;
}