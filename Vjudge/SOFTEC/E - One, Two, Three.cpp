#include <bits/stdc++.h>
#define int long long int
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;

signed main(){
    int t;
    cin >> t;

    vector<string> words = {"twone", "two", "one"};
    while (t--){
        string s;
        cin >> s;
        
        int count = 0;
        vector<int> positions;
        for (auto word : words){
            for (int pos = 0; (pos = s.find(word, pos)) != s.npos; ){
                count++;
                s[pos + (word.size() / 2)] = 'x';
                positions.push_back(pos + (word.size() / 2) + 1);
            }
        }
        cout << count << "\n";
        for (auto it : positions){
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}