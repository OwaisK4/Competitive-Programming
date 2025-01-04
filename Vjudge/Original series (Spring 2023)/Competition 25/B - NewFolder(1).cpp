#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;
using pii = pair<int, int>;

int main(){
    int N;
    cin >> N;

    map<string, pii> mp;
    vector<string> S(N);

    for (int i=0; i<N; i++){
        cin >> S[i];
        mp[S[i]].first++;
        mp[S[i]].second = 0;
        // mp[S[i]]++;
    }

    for (int i=0; i<N; i++){
        string s = S[i];
        if (mp[S[i]].first > 0){
            if (mp[S[i]].second == 0){
                cout << S[i] << "\n";
                mp[S[i]].second++;
            }
            else{
                cout << S[i] << "(" << mp[S[i]].second << ")" << "\n";
                mp[S[i]].second++;
            }
            mp[S[i]].first--;
        }
    }

    return 0;
}