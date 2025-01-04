#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;

signed main(){
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        map<string, int> notes;
        for (int i=0; i<n-1; i++){
            string note = s.substr(i, 2);
            notes[note]++;
        }

        cout << notes.size() << "\n";
    }
    return 0;
}