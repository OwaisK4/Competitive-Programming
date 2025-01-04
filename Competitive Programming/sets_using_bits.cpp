#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void set_elements_from_bits(int X){
    for (int i = 31; i >= 0; i--){
        if (X & (1 << i))
            cout << i << " ";
        else
            continue;
    }
    return;
}

int main(){
    int X = 0;
    X |= (1 << 1);
    X |= (1 << 3);
    X |= (1 << 4);
    X |= (1 << 8);
    cout << X << "\n";
    set_elements_from_bits(X);
    return 0;
}