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

    long long n;
    cin >> n;
    long long y = log2(pow(n, 2));

    if (n > y){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}