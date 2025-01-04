#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--){
        string s, t;
        map<string, int> mp;
        cin >> s;
        cin >> t;

        /*
        int count = 0;
        int N = s.size();

        for (int i=0; i<N; i++){
            mp[s] = 1;
            if (s.size() > 50){
                cout << -1 << "\n";
                break;
            }
            if (s[i] == 'a'){
                s.replace(i, 1, t);
                if (t.size() > 1)
                    i = s.find('a', 0) - 1;
            }
        }

        for (auto it : mp){
            count += 1;
        }
        cout << count << "\n";
        */
    }
    return 0;
}