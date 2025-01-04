#include <bits/stdc++.h>
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
    vector<string> names = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
    string s;
    cin >> s;
    int counter = 0;
    int start = 0;
    int end;
    for (int i=0; i<6; i++){
        end = s.find(names[i], 0);
        cout << end << "\n";
    }


    if (counter == 1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}