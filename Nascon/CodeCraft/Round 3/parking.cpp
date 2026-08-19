#include <array>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
using pii = pair<int, int>;

vector<int> dx = {0, 1, -1, 0};
vector<int> dy = {1, 0, 0, -1};
map<pair<int, int>, string> mapping;

class ParkingSolver {
public:
    int rows, cols;
    vector<vector<char>> grid;
    ParkingSolver(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        grid.assign(rows, vector<char>(cols, '0'));
    }
    void inputGrid() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> grid[i][j];
            }
        }
    }
    bool isSafe(int x, int y) {
        if (x < 0 || y < 0 || x >= rows || y >= cols || (grid[x][y] == '#' || grid[x][y] == 'C' || grid[x][y] == 'Y')) {
            return false;
        }
        return true;
    }
    int score(int x, int y) {
        if (grid[x][y] == 'S') {
            return 2;
        } else {
            return 1;
        }
    }
    pair<vector<vector<int>>, vector<vector<string>>> calculateDistances(char startingPoint) {
        int x = -1, y = -1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == startingPoint) {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        vector<vector<string>> paths(rows, vector<string>(cols, ""));
        vector<vector<int>> distances(rows, vector<int>(cols, INT_MAX));
        distances[x][y] = 0;

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        pq.push({0, x, y});
        while (!pq.empty()) {
            auto [dist, x, y] = pq.top();
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int next_x = x + dx[i];
                int next_y = y + dy[i];
                if (!isSafe(next_x, next_y))
                    continue;
                if (distances[next_x][next_y] > distances[x][y] + score(next_x, next_y)) {
                    paths[next_x][next_y] = paths[x][y] + mapping[{dx[i], dy[i]}];
                    distances[next_x][next_y] = distances[x][y] + score(next_x, next_y);
                    pq.push({distances[next_x][next_y], next_x, next_y});
                }
            }
        }
        // for (int i = 0; i < rows; i++) {
        //     for (int j = 0; j < cols; j++) {
        //         cout << distances[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return make_pair(distances, paths);
        // return {distances, paths};
    }
};

int main() {
    mapping[{dx[0], dy[0]}] = 'R';
    mapping[{dx[1], dy[1]}] = 'D';
    mapping[{dx[2], dy[2]}] = 'U';
    mapping[{dx[3], dy[3]}] = 'L';

    // vector<int> dx = {0, 1, -1, 0};
    // vector<int> dy = {1, 0, 0, -1};

    int rows, cols;
    cin >> rows >> cols;
    ParkingSolver solver(rows, cols);
    solver.inputGrid();
    auto Y = solver.calculateDistances('Y');
    vector<vector<int>> distY = Y.first;
    vector<vector<string>> pathsY = Y.second;

    auto C = solver.calculateDistances('C');
    vector<vector<int>> distC = C.first;
    vector<vector<string>> pathsC = C.second;

    int answer = INT_MAX;
    int coord_X = -1, coord_Y = -1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (solver.grid[i][j] == 'P') {
                if (answer > distY[i][j] + distC[i][j]) {
                    answer = distY[i][j] + distC[i][j];
                    coord_X = i;
                    coord_Y = j;
                }
            }
        }
    }
    cout << answer << "\n";
    cout << coord_X << " " << coord_Y << "\n";

    string rev = "";
    for (auto it : pathsC[coord_X][coord_Y]) {
        if (it == 'L') {
            rev += 'R';
        } else if (it == 'R') {
            rev += 'L';
        } else if (it == 'D') {
            rev += 'U';
        } else if (it == 'U') {
            rev += 'D';
        }
    }

    cout << pathsY[coord_X][coord_Y] << "P " << rev;

    // for (int i = 0; i < n; i++) {
    // }
}
