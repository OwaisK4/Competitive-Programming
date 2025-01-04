#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long
using namespace std;
using pii = pair<int, int>;

int parse(string card){
    map<char, int> suits;
    suits['D'] = 0;
    suits['C'] = 1;
    suits['H'] = 2;
    suits['S'] = 3;

    map<char, int> ranks;
    for (int i=2; i<=10; i++){
        ranks[i + 48] = i - 2;
    }
    ranks['J'] = 9;
    ranks['Q'] = 10;
    ranks['K'] = 11;
    ranks['A'] = 12;

    int answer = suits[card[0]]*13 + ranks[card[1]];
    return answer;
}

signed main(){
    int n;
    string card = "SA";
    
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> card;
        cout << parse(card) << "\n";
    }
    return 0;
}