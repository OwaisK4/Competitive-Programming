#include <algorithm>
#include <climits>
#include <iomanip>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#define all(a) a.begin(), a.end()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, N;
    cin >> t;

    while (t--) {
        cin >> N;
        vector<vector<int>> P(N, vector<int>(N - 1));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - 1; j++) {
                cin >> P[i][j];
            }
        }

        map<int, int> counter;
        for (int i = 0; i < N; i++) {
            counter[P[i][0]]++;
        }

        int maximum = INT_MIN;
        int number;
        for (auto it : counter) {
            if (it.second > maximum)
                number = it.first;
                maximum = it.second;
        }

        cout << number << " ";

        for (int i = 0; i < N; i++) {
            if (P[i][0] != number) {
                for (int j = 0; j < N - 1; j++) {
                    cout << P[i][j] << " ";
                }
                break;
            }
        }
        cout << "\n";
    }

    return 0;
}