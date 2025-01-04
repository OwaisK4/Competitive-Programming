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

int sum_of_digits(int n){
    int total = 0;
    while (n > 0){
        total += (n % 10);
        n /= 10;
    }
    return total;
}

int num_of_digits(int n){
    int count = 0;
    while (n > 0){
        count++;
        n /= 10;
    }
    return count;
}

void solve(){
    int n, s;
    cin >> n >> s;
    
    int total = sum_of_digits(n);
    if (total > s){
        int count = num_of_digits(n);
        // count += 1;
        int next_magnitude = pow(10, count);
        int answer = next_magnitude - n;
        // int answer = next_magnitude - n;
        cout << answer << "\n";
    }
    else{
        cout << 0 << "\n";
    }

}

signed main(){
    fastio;
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}