#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
//LLONG_MAX,LLONG_MIN

using namespace std;

signed main(){
    map<string, int> scores;
    int N;
    cin >> N;
    string temp;
    for (int i=0; i<N; i++){
        cin >> temp;
        scores[temp]++;
    }
    int max_score = 0;
    string winning_team;
    for (auto it : scores){
        if (it.second > max_score){
            max_score = it.second;
            winning_team = it.first;
        }
    }
    cout << winning_team;
    return 0;
}