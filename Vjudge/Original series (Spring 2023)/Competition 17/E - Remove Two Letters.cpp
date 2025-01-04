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

    int t;
    cin >> t;

    while (t--){
        int N;
        cin >> N;

        string s;
        cin >> s;

        map<string, int> mp;
        for (int i=0; i<N-1; i++){
            string temp = s;
            temp.erase(i, 2);
            // cout << temp << " ";
            mp[temp]++;
        }
        int count = 0;
        for (auto it : mp){
            count++;
        }
        cout << count << "\n";
    }
    return 0;
}