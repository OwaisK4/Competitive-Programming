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

int value(string card){
    char rank = card[1];
    if (rank >= '2' && rank <= '9'){
        return rank + 48;
    }
    else{
        return 10;
    }
}

signed main(){
    int t;
    cin >> t;

    for (int i=1; i<=t; i++){
        int n = 52;
        vector<string> cards(n);
        for (int i=0; i<n; i++){
            cin >> cards[i];
        }

        int X, Y = 0;
        vector<string> hand(cards.end() - 25, cards.end());
        cards.erase(cards.end() - 25, cards.end());
        // cout << "Hand size = " << hand.size() << "\n";
        // return 0;

        for (int i=0; i<3; i++){
            X = value(cards.back());
            Y += X;
            cards.pop_back();
            for (int i=0; i<10-X; i++)
                cards.pop_back();
        }

        cards.insert(cards.end(), all(hand));
        int size = cards.size();

        string answer = cards[Y - 1];
        // cout << "Y = " << Y << ", ";
        cout << "Case " << i << ": " << answer << "\n";

        // for (auto it : cards){
        //     cout << it << " ";
        // }
        // cout << "\n";
    }
    return 0;
}