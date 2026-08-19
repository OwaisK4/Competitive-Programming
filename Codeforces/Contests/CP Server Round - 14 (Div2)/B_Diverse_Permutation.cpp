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

signed main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> answer;
    int low = 1, high = n;
    string current = "low";

    while (k > 1) {
        if (current == "low") {
            answer.push_back(low);
            low++;
            current = "high";
        } else {
            answer.push_back(high);
            high--;
            current = "low";
        }
        k--;
        n--;
    }
    while (n > 0) {
        if (current == "low") {
            answer.push_back(low);
            low++;
        } else {
            answer.push_back(high);
            high--;
        }
        n--;
    }
    print(answer);

    return 0;
}