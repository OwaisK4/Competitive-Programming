#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;
using pii = pair<int, int>;

signed main(){
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        map<int, int> table;
        int counter = 0;
        table[counter]++;
        for (int i=0; i<n; i++){
            if (s[i] == '<'){
                counter++;
            }
            else{
                counter--;
            }
            table[counter]++;
        }
        cout << table.size() << "\n";
    }

    return 0;
}