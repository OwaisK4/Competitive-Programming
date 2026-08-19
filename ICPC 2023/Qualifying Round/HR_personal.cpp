#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

template <typename T>
void print(vector<T> &array, int size = numeric_limits<int>::max()) {
    for (int i = 0; i < min<int>(size, array.size()); i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}
template <typename T>
void print(T X) {
    cout << X << "\n";
}

map<int, vector<int>> person;
map<int, int> visited;

int ways(int index) {
    if (index == person.size()) {
        return 1;
    }
    int answer = 0;
    vector<int> p = person[index];
    for (int i = 0; i < p.size(); i++) {
        if (visited[p[i]] == 0) {
            visited[p[i]] = 1;
            answer += ways(index + 1);
            visited[p[i]] = 0;
        }
    }
    return answer;
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int m, dep;
            cin >> m;
            for (int j = 0; j < m; j++) {
                cin >> dep;
                person[i].push_back(dep);
            }
        }
        // for (auto &[key, value] : person) {
        //     cout << key << ": ";
        //     print(value);
        // }
        int answer = ways(0);
        cout << answer << "\n";
        visited.clear();
        person.clear();
    }

    return 0;
}