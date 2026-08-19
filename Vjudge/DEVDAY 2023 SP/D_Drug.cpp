#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    
    int W_hours = B / 60;
    int O_hours = D / 60;
    B %= 60;
    D %= 60;
    
    A += W_hours;
    C += O_hours;
    A %= 24;
    C %= 24;

    // cout << A << " " << B << " " << C << " " << D << "\n";

    if (A < C){
        cout << "Waqas";
    }
    else if (C < A){
        cout << "Owais";
    }
    else{
        if (B <= D){
            cout << "Waqas";
        }
        else{
            cout << "Owais";
        }
    }

    return 0;
}