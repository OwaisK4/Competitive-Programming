#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

string dec_to_binary(int number){
    string bin;
    for (int i=31; i>=0; i--){
        if (number & (1 << i))
            bin += "1";
        else
            bin += "0"; 
    }
    return bin;
}

int main(){
    // int X = INT_MAX;
    // string Y = dec_to_binary(X);
    // cout << Y << "\n";
    cout << dec_to_binary(INT_MAX) << "\n";
    cout << dec_to_binary(INT_MIN) << "\n";
    return 0;
}