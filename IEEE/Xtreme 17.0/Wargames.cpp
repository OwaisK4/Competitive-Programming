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

vector<string> card_values = {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};

signed main() {
    fastio;
    int n;
    cin >> n;
    cin.ignore();
    string s;
    string token;

    map<string, int> cards;
    for (int i = 0; i < card_values.size(); i++) {
        cards[card_values[i]] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        stringstream ss1(s);
        queue<string> player1;
        while (getline(ss1, token, ' ')) {
            player1.push(token);
        }
        getline(cin, s);
        stringstream ss2(s);
        queue<string> player2;
        while (getline(ss2, token, ' ')) {
            player2.push(token);
        }
        int iterations = 0;
        while (!player1.empty() && !player2.empty() && iterations < 2700) {
            string a = player1.front();
            string b = player2.front();

            player1.pop();
            player2.pop();

            if (cards[a] > cards[b]) {
                player1.push(b);
            } else if (cards[a] < cards[b]) {
                player2.push(a);
            } else {
                player1.push(a);
                player2.push(b);
            }
            iterations++;
        }
        if (player1.empty()) {
            cout << "player 2"
                 << "\n";
        } else if (player2.empty()) {
            cout << "player 1"
                 << "\n";
        } else {
            cout << "draw"
                 << "\n";
        }
        // print(player1);
        // print(player2);
    }

    return 0;
}