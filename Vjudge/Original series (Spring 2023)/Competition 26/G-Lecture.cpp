#include <bits/stdc++.h>
#define int long long int
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;

signed main(){
    int n, m;
    cin >> n >> m;
    unordered_map<string, string> transform;
    string a, b;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        transform[a] = b;
    }
    // for (auto it : transform){
    //     cout << it.first << " " << it.second << "\n";
    // }
    vector<string> record;
    for (int i=0; i<n; i++){
        cin >> a;
        b = transform[a];
        if (a.size() <= b.size()){
            record.push_back(a);
        }
        else{
            record.push_back(b);
        }
    }

    for (auto it : record){
        cout << it << " ";
    }

    return 0;
}