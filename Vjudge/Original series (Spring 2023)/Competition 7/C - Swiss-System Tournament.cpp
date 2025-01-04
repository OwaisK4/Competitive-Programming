#include <iostream>
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
    char A;
    cin >> N >> M;
    vector<vector<char>> record(2*N);
    vector<int> indexes(2*N + 1, 0);
    int asd=0;
    for (auto& it : indexes){
        it += asd;
        asd++;
    }
    // indexes[i] = i;
    vector<int> win_count(2*N + 1);
    vector<int> winners(2*N);
    vector<int> losers(2*N);
    for (int i=0; i<2*N; i++){
        for (int j=0; j<M; j++){
            cin >> A;
            record[i].push_back(A);
        }
    }
    vector<int> temp(indexes);
    for (int i=0; i<M; i++){
        for (int k=1; k<=N; k++){
            int X = 2*k - 1;
            int Y = 2*k;
            if (X_Wins(record[indexes[X]][i], record[indexes[Y]][i])){
                win_count[indexes[X]]++;
                temp[k-1] = indexes[X];
                temp[k+N-1] = indexes[Y];
            }
            else{
                win_count[indexes[Y]]++;
                temp[k-1] = indexes[Y];
                temp[k+N-1] = indexes[X];
            }
            /*
            cout << temp[2*k - 1] << ", " << temp[2*k] << "\n";
            if (record[temp[2*k - 1]][i] == record[temp[2*k]][i]){
                if (temp[2*k - 1] < temp[2*k]){
                    win_count[2*k - 1]++;
                    indexes[2*k-1] = 2*k - 1;
                    indexes[2*k] = 2*k;
                }
                else{
                    win_count[2*k]++;
                    indexes[2*k-1] = 2*k;
                    indexes[2*k] = 2*k - 1;
                }
                // continue;
            }
            else if (X_Wins(record[temp[2*k - 1]][i], record[temp[2*k]][i])){
                win_count[2*k - 1]++;
                indexes[2*k-1] = 2*k - 1;
                indexes[2*k] = 2*k;
            }
            else{
                win_count[2*k]++;
                indexes[2*k-1] = 2*k;
                indexes[2*k] = 2*k - 1;
            }
            // temp = indexes;
            */
        }
        for (auto it : indexes){
            cout << it << " ";
        }
        cout << "\n";
        indexes = temp;
    }
    for (auto it : indexes){
        cout << it << " ";
    }
    cout << "\n";
    for (auto it : win_count){
        cout << it << "\n";
    }
    /*
    for (auto it : record){
        for (auto jt : it){
            cout << jt;
        }
        cout << "\n";
    }
    */
    return 0;
}