#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'knightlOnAChessboard' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts INTEGER n as parameter.
 */

vector<vector<int>> dp;

int dfs(int x, int y, int a, int b, int n) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return INT_MAX / 2;
    } else if (x == n - 1 && y == n - 1) {
        // } else if (x > 1 && y > 1) {
        return 0;
    }
    // if (dp[x][y] != -1){
    //     return dp[x][y];
    // }

    vector<int> dx = {a, b, -a, -b, a, b, -a, -b};
    vector<int> dy = {b, a, -b, -a, -b, -a, b, a};
    int minimum = INT_MAX / 2;
    for (int i = 0; i < (int)dx.size(); i++) {
        minimum = min(minimum, 1 + dfs(x + dx[i], y + dy[i], a, b, n));
    }
    return minimum;
}

vector<vector<int>> knightlOnAChessboard(int n) {
    vector<vector<int>> answer;
    // return answer;
    for (int a = 1; a < n; a++) {
        vector<int> current;
        for (int b = 1; b < n; b++) {
            dp.assign(n + 1, vector<int>(n + 1, -1));
            int received = dfs(0, 0, a, b, n);
            if (received == INT_MAX >> 1) {
                current.push_back(-1);
            } else {
                current.push_back(received);
            }
        }
        answer.push_back(current);
    }
    return answer;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}