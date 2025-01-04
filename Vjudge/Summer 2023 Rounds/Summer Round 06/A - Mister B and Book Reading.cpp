#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

template <typename T>
void print(vector<T> array){
    for (auto it : array){
        cout << it << " ";
    }
    cout << "\n";
}

signed main(){
    fastio;
    int c, v0, v1, a, l;
    cin >> c >> v0 >> v1 >> a >> l;
    int count = 0;
    int sum = 0;
    while (sum < c){
        if (count > 0){
            sum -= l;
        }
        int pages = v0 + (a * count);
        sum += min(pages, v1);
        // cout << "Sum = " << sum << "\n";
        count++;
    }
    cout << count;

    return 0;
}