#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    map<string, int> mp;
    vector<pair<string, string>> arr;
    for (int i = 0; i < n; i++) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        if (!mp.count(s1))
            mp[s1] = 0;
        if (!mp.count(s3))
            mp[s3] = 0;
        if (s2 == "->") {
            mp[s3]++;
        } else {
            arr.push_back({s1, s3});
        }
    }

    for (int i = 0; i < 10; i++) {
        for (auto it : arr) {
            if (mp[it.first] > 0) {
                mp[it.second]++;
                it.first = ".";
                it.second = ".";
            } else if (mp[it.second] > 0) {
                mp[it.first]++;
                it.first = ".";
                it.second = ".";
            }
        }
    }

    vector<string> ans;
    for (auto it : mp) {
        if (it.second == 0) {
            ans.push_back(it.first);
        }
    }
    for (auto it : ans) {
        cout << it << endl;
    }
}