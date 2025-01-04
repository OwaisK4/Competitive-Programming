#include <bits/stdc++.h>
using namespace std;
signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int inside = 0;
        int outside = 0;
        int answer;
        for (int i = 0; i < n; i++) {
            if (s[i] == '+') {
                inside++;
                if (outside)
                    outside--;
            } else {
                outside++;
                if (inside)
                    inside--;
            }
        }
        answer = inside + outside;
        cout << answer;
    }
    return 0;
}