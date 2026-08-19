#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void solve(int N, int Q) {
    vector<vector<int>> grid(N, vector<int>(N, 0));

    for (int i = 0; i < Q; i++) {
        int choice;
        cin >> choice;
        if (choice == 1) {
            int x, y, v;
            cin >> x >> y >> v;
            x--;
            y--;
            grid[x][y] += v;

        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--;
            y1--;
            x2--;
            y2--;
            int maximum = INT_MIN;
            for (int i = x1; i <= x2; i++) {
                for (int j = y1; j <= y2; j++) {
                    maximum = max(maximum, grid[i][j]);
                }
            }
            cout << maximum << endl;
        }
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    solve(N, Q);

    return 0;
}