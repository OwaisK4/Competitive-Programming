#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define nl cout << "\n"
using namespace std;

int main() {
    int n;
    cin >> n;
    // vector<int> time(n);
    map<int, int> time;
    int h, m;
    for (int i = 0; i < n; i++) {
        cin >> h >> m;
        int value = (h * 100) + m;
        time[value]++;
        // time[i] = (h * 100) + m;
    }
    // for (auto it : time) {
    //     cout << it << " ";
    // }
    // nl;
    int cash = numeric_limits<int>::min();
    for (auto it : time){
        cash = max(cash, it.second);
    }
    cout << cash;
}