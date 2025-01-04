#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool X_Wins(char X, char Y){
    if (X == 'G' && Y == 'C')
        return true;
    else if (X == 'C' && Y == 'P')
        return true;
    else if (X == 'P' && Y == 'G')
        return true;
    else
        return false;
}

int main(){
    int N, M;
    char hand;
    cin >> N >> M;
    vector<vector<char>> matches(2*N + 2);
    for (int i=0; i<2*N; i++){
        for (int j=0; j<M; j++){
            cin >> hand;
            matches[i].push_back(hand);
        }
    }
    vector<int> players(2*N, 0);
    for (int i=0; i<2*N; i++){
        players[i] = i+1;
    }
    vector<int> temp;

    for (int i=0; i<M; i++){
        for (int j=0; j<N && 2*j < 2*N-1; j++){
            int X = players[2*j];
            int Y = players[2*j + 1];
            // cout << "(" << X << ", " << Y << ") ";
            if (matches[X-1][i] == matches[Y-1][i]){
                if (X < Y){
                    if (temp.size() == 0){
                        temp.push_back(X);
                        temp.push_back(Y);
                    }
                    else{
                        auto iterator = temp.begin();
                        while (*iterator == X)
                            iterator++;
                        temp.insert(iterator, X);
                        iterator = temp.end();
                        while (*iterator == Y)
                            iterator--;
                        temp.insert(iterator, X);
                    }

                }
                else{
                    if (temp.size() == 0){
                        temp.push_back(X);
                        temp.push_back(Y);
                    }
                    else{
                        auto iterator = temp.begin();
                        while (*iterator < Y)
                            iterator++;
                        temp.insert(iterator, Y);
                    }
                }
            }
            else if (X_Wins(matches[X-1][i], matches[Y-1][i])){

            }
            else{

            }
        }
    }
    for (auto it : players){
        cout << it << "\n";
    }
    /*
    for (auto it : matches){
        for (auto jt : it){
            cout << jt;
        }
        cout << "\n";
    }
    */
    return 0;
}