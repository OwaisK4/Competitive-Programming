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

map<string, int> vertices;

signed main() {
    fastio;
    int n;
    cin >> n;
    string x, y, z;
    vector<vector<string>> edges;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        vector<string> current;
        current.push_back(x);
        current.push_back(y);
        current.push_back(z);
        if (y == "->") {
            if (vertices.count(x) == 0) {
                vertices[x] = 0;
            }
            vertices[z]++;
        } else {
            if (vertices.count(x) == 0)
                vertices[x] = 0;
            if (vertices.count(z) == 0)
                vertices[z] = 0;
            edges.push_back(current);
        }
    }
    // int cnt = 0;
    // while (cnt < edges.size()) {
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < edges.size(); i++) {
            string x = edges[i].front();
            string z = edges[i].back();
            //     continue;
            if (vertices[x] > 0) {
                vertices[z]++;
                // cnt++;
            } else if (vertices[z] > 0) {
                vertices[x]++;
                // cnt++;
            }
        }
    }
    vector<string> answer;
    for (auto &it : vertices) {
        if (it.second == 0)
            answer.push_back(it.first);
    }
    sort(all(answer));
    for (auto &it : answer) {
        cout << it << "\n";
    }

    return 0;
}