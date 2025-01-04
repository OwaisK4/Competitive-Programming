#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
//LLONG_MAX,LLONG_MIN
using namespace std;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

signed main(){
    int N, M;
    cin >> N >> M;
    vector<int> players(M);

    vector<pii> shots;
    vector<tii> fields;

    int a, b;
    for (int i=0; i<N; i++){
        cin >> a >> b;
        shots.push_back({a, 1LL});
        shots.push_back({b, -1LL});
    }
    sort(all(shots));
    for (int i=0; i<shots.size(); i++){
        if (i < shots.size()-1 && shots[i].first == shots[i+1].first){
            shots.erase(shots.begin() + i);
        }
    }

    int c, d;
    for (int i=0; i<M; i++){
        cin >> c >> d;
        fields.push_back({c, i, 1LL});
        fields.push_back({d, i, -1LL});
    }
    sort(all(fields));

    int i=0, j=0;
    int shot_counter = 0;
    int counter = 0;
    vector<int> current_shots(N);
    vector<int> current_fielders(M);
    while (i < shots.size() && j < fields.size()){
        cout << "Count = " << counter << "\n";
        if (shots[i].first < get<0>(fields[j])){
            counter += shots[i].second;
            current_shots[shot_counter] += shots[i].second;
            i++;
        }
        else if (shots[i].first > get<0>(fields[j])){
            int fielder = get<1>(fields[j]);
            current_fielders[fielder] += get<2>(fields[j]);
            j++;
        }
        else{
            counter = counter + shots[i].second;
            current_shots[i] = shots[i].second;
            int fielder = get<1>(fields[j]);
            current_fielders[fielder] += get<2>(fields[j]);
            i++;
            j++;
        }
        for (int k=0; k<M; k++){
            if (current_fielders[k] != 0){
                players[k] = max(players[k], (long long) count(all(current_shots), 1));
            }
        }
    }

    i=1;
    for (auto it : players){
        cout << "Player " << i++ << " strength: " << it << "\n";
    }

}