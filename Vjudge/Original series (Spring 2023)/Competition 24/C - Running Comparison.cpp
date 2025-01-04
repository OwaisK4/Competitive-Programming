#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        for (int i=0; i<N; i++){
            cin >> A[i];
        }
        for (int i=0; i<N; i++){
            cin >> B[i];
        }
        int count = 0;
        bool a, b;
        for (int i=0; i<N; i++){
            a = false;
            b = false;
            int alice = A[i];
            int bob = B[i];
            if ((2 * alice) >= bob){
                a = true;
            }
            if ((2 * bob) >= alice){
                b = true;
            }
            if (a && b){
                count++;
            }
        }
        cout << count << "\n";
    }    
    return 0;
}