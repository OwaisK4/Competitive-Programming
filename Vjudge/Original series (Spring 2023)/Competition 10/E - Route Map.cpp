#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    vector<string> T(M);

    for (int i = 0; i < N; i++){
        cin >> S[i];
    }
    for (int i = 0; i < M; i++){
        cin >> T[i];
    }
    
    // sort(S.begin(), S.end());
    sort(T.begin(), T.end());

    // for (auto it : T){
    //     cout << it << " ";
    // }
    // for (int i = 0; i < N; i++){
    //     cout << S[i] << " ";
    // }

    
    for (int i = 0; i < N; i++){
        string temp = S[i];
        int k = 0;
        for (int b = M/2; b >= 1; b /= 2){
            while (k+b < M && T[k+b] <= temp)
                k += b;
        }
        if (T[k] == temp){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    /*
    for (auto& it : S){
        bool flag = false;
        for (auto& jt : T){
            if (it == jt){
                flag = true;
                break;
            }
        }
        if (flag){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    */
    return 0;
}