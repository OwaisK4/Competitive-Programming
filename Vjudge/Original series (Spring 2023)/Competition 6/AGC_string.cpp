#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

int main(){
    int N;
    stringstream ss;
    cin >> N;
    if (N > 41)
        N++;
    // N = 41;
    ss << "AGC";
    ss << setw(3) << setfill('0') << N;
    cout << ss.str();
    return 0;
}