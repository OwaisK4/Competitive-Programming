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
    int N, S;
    cin >> N >> S;
    int A[N], B[N];
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    for (int i=0; i<N; i++){
        cin >> B[i];
    }
    if (A[0] == 0){
        cout << "NO";
        return 0;    
    }
    
    if (A[S-1] == 1){
        cout << "YES";
        return 0;
    }

    for (int i=0; i<N; i++){
        if (i >= S-1 && A[i] == 1 && B[i] == 1){
            if (B[S-1] == 1){
                cout << "YES";
                return 0;
            }

        }
    }
    cout << "NO";
    return 0;
}