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
    int n, k;
    cin >> n >> k;

    vector<int> passwords;
    for (int i=0; i<n; i++){
        string temp;
        cin >> temp;
        passwords.push_back(temp.size());
    }
    string real;
    cin >> real;
    int real_size = real.size();

    int l_size = 0;
    int le_size = 0;
    sort(all(passwords));
    for (int i=0; i<n; i++){
        if (passwords[i] < real_size){
            l_size++;
        }
        if (passwords[i] <= real_size){
            le_size++;
        }
    }

    int min_time = l_size + (l_size / k)*5 + 1;
    int max_time = le_size + ((le_size - 1) / k)*5;
    cout << min_time << " " << max_time;

    return 0;
}