#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    // string S[N], T[N];
    string ST[N];
    string S, T;
    // cin.ignore();
    for (int i=0; i<N; i++){
        cin >> S >> T;
        ST[i] = S + " " + T;
        // getline(cin, ST[i]);
    }

    // for (int i=0; i<N; i++){
    //     cout << ST[i] << "\n";
    // }

    sort(ST, ST + N);
    // sort(S, S + N);
    // sort(T, T + N);

    bool flag = false;
    for (int i=0; i<N-1; i++){
        if (ST[i] == ST[i+1]){
            flag = true;
        }
    }
    if (flag)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}