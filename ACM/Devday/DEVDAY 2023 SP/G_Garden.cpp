#include <bits/stdc++.h>
using namespace std;

int main(){
    int X, Y;
    cin >> X >> Y;

    if (Y < 2*X){
        cout << "No";
        return 0;
    }

    int a = 0;
    int b = X;

    long long int answer = 2*a + 4*b;
    while (answer > Y){
        a++;
        b--;
        answer = 2*a + 4*b;
    }
    if (answer == Y){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

    return 0;
}