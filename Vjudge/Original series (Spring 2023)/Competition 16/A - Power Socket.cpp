#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int A, B;
    cin >> A >> B;

    int total = 1;
    int count = 0;
    while (total < B){
        total = total - 1 + A;
        count++;
    }
    cout << count;
    return 0;
}