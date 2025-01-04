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
    map<char, int> mp;
    int n;
    cin >> n;

    int size = (n * 2) - 2;
    char temp;
    int count = 0;
    for (int i=0; i<size; i++){
        cin >> temp;
        if (i % 2 == 0){
            mp[temp]++;
        }
        else{
            if (mp[temp + 32] > 0){
                mp[temp + 32]--;
            }
            else{
                count++;
            }
        }
    }
    cout << count;

    return 0;
}