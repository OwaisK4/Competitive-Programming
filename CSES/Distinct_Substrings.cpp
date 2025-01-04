#include <bits/stdc++.h>
#include <ext/numeric>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;
using namespace __gnu_cxx;

template <typename T>
void print(vector<T> &array) {
    for (auto &it : array) {
        cout << it << " ";
    }
    cout << "\n";
}

signed main() {
    fastio;
    string s;
    cin >> s;
    map<int, int> mp;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }
    int dups = s.size() - mp.size();
    int answer = (s.size() * (s.size() + 1)) / 2;
    answer -= dups;
    cout << answer;

    return 0;
}