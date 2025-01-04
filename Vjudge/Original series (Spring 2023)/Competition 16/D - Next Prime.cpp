#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int X;
    cin >> X;

    while (true){
        int temp = X++;
        bool flag = true;
        for (int i = 2; i <= sqrt(temp); i++){
            if (temp % i == 0){
                flag = false;
                break;
            }
        }
        if (flag){
            cout << temp;
            break;
        }
    }
    return 0;
}