#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int K;
    cin >> K;

    unsigned long long int a = 7;

    if (K % 2 == 0){
        cout << -1;
        return 0;
    }

    for (int i=1; i<=K; i++){
    // while (true){
        if (a % K == 0){
            cout << i;
            return 0;
        }
        a = (a*10) + 7;
        a %= K;
    }
    
    cout << -1;
    return 0;
}