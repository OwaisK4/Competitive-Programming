#include <bits/stdc++.h>
#define int long long int
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;

signed main(){
    vector<pair<int, bool>> array(5, {0, false});
    for (auto it : array){
        cout << it.second << " ";
    }
    return 0;
}