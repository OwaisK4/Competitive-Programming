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
    string s;
    cin >> s;
    if (s.size() % 2 != 0){
        cout << "-1";
    }
    else{
        int vertical = 0;
        int horizontal = 0;
        for (int i=0; i<s.size(); i++){
            if (s[i] == 'U'){
                vertical++;
            }
            if (s[i] == 'D'){
                vertical--;
            }
            if (s[i] == 'R'){
                horizontal++;
            }
            if (s[i] == 'L'){
                horizontal--;
            }
        }
        vertical = abs(vertical);
        horizontal = abs(horizontal);
        // cout << horizontal << " " <<  vertical << "\n";

        int answer = vertical + horizontal;
        cout << (answer / 2);
    }

    return 0;
}