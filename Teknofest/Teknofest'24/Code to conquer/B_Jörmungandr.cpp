#include <bits/stdc++.h>
using namespace std;
signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string answer = "";
        int n = s.size();
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < n; i++) {
            if (vowels.find(s[i]) == vowels.end()) {
                answer += s[i];
                char left = '1';
                char right = '1';
                for (char v = s[i] + 1; v <= 'z'; v++) {
                    if (vowels.find(v) != vowels.end()) {
                        right = v;
                        break;
                    }
                }
                for (char v = s[i] - 1; v >= 'a'; v--) {
                    if (vowels.find(v) != vowels.end()) {
                        left = v;
                        break;
                    }
                }
                if (right == '1') {
                    answer += left;
                } else if (left == '1') {
                    answer += right;
                } else if (s[i] - left <= right - s[i]) {
                    answer += left;
                } else {
                    answer += right;
                }
                if (s[i] == 'z') {
                    answer += 'z';
                } else {
                    for (char c = s[i] + 1; c <= 'z'; c++) {
                        if (vowels.find(c) == vowels.end()) {
                            answer += c;
                            break;
                        }
                    }
                }
            } else {
                answer += s[i];
            }
        }
        cout << answer;
    }
    return 0;
}