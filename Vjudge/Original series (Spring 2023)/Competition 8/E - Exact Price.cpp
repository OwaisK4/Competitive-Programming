#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    int X;
    cin >> X;
    if (X != 0 && X % 100 == 0){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}