#include <bits/stdc++.h>
using namespace std;
signed main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<string> a(n);
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        getline(cin, a[i]);
        mp[a[i]]++;
    }
    int maximum = 0;
    for (auto it : mp) {
        maximum = max(maximum, it.second);
    }
    cout << maximum;

    return 0;
}