#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        string s;
        cin >> s;
        int moves = 0;
        stack<char> brackets;
        for (auto it : s) {
            if (brackets.empty()) {
                if (it == ')')
                    moves++;
                brackets.push(it);
            }
            else {
                if (it == ')') {
                    if (brackets.top() == '(') {
                        brackets.pop();
                    } else {
                        moves++;
                        brackets.push(it);
                    }
                }
                else {
                    brackets.push(it);
                }
            }
        }
        cout << moves << "\n";
        // // int max_length = brackets.size();
        // cout << max_length << "\n";
    }
    return 0;
}