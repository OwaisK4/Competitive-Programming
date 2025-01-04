#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int sum_of_digits(int num){
    int sum = 0;
    while (num){
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, A, B;
    long long int total = 0;

    cin >> N >> A >> B;

    for (int i = 1; i <= N; i++){
        int s = sum_of_digits(i);
        if (s >= A && s <= B){
            // cout << i << " ";
            total += i;
        }
    }
    // cout << "\n";
    cout << total;

    return 0;
}