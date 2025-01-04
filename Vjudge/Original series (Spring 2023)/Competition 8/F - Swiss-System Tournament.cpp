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
    vector<int> temp(2*N, 0);
    for (int i=0; i<2*N; i++){
        temp[i] = players[i];
    }

    for (int i=0; i<M; i++){
        players = temp;
        for (int j=0; j<N && 2*j < 2*N-1; j++){
            int X = players[2*j];
            int Y = players[2*j + 1];
            // cout << "(" << X << ", " << Y << ") ";
            if (matches[X-1][i] == matches[Y-1][i]){
            // if (matches[2*j][i] == matches[2*j + 1][i]){
                if (X < Y){
                    temp[j] = X;
                    temp[N+j] = Y;
                }
                else{
                    temp[j] = Y;
                    temp[N+j] = X;
                }
            }
            else if (X_Wins(matches[X-1][i], matches[Y-1][i])){
            // else if (X_Wins(matches[2*j][i], matches[2*j + 1][i])){
                temp[j] = X;
                temp[N+j] = Y;
            }
            else{
                temp[j] = Y;
                temp[N+j] = X;
            }
            // for (auto it : players){
            //     cout << it << " ";
            // }
            // cout << "\n";
            // for (int i=0; i<2*N; i++){
            //     players[i] = temp[i];
            // }
        }
        // for (int i=0; i<2*N; i++){
        //     players[i] = temp[i];
        // }
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