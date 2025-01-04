#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
using namespace std;

template <typename T>
void print(vector<T> array){
    for (auto& it : array){
        cout << it << " ";
    }
    cout << "\n";
}

signed main(){
    int N;
    while (true){
        cin >> N;
        if (N == 0){
            break;
        }
        vector<pair<string, string>> cards(N);
        vector<string> initial(N, "");
        for (int i=0; i<N; i++){
            string card, word;
            cin >> card >> word;
            cards[i] = {card, word};
        }
        // for (auto & [card, word] : cards){
        //     cout << card << " " << word << "\n";
        // }
        int i = -1;
        // int n = cards[0].second.size() - 1;
        // i += n;
        // i %= N;
        // initial[i] = cards[0].first;
        for (int j = 0; j < N; j++){
            int n = cards[j].second.size();
            while (n > 0){
                i++;
                i %= N;
                if (initial[i] == ""){
                    n--;
                }
            }
            initial[i] = cards[j].first;
        }
        for (int i=0; i<N; i++){
            if (i == N-1){
                cout << initial[i] << "\n";
            }
            else{
                cout << initial[i] << " ";
            }
        }
    }
    return 0;
}