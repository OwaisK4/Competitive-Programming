#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    cout << setfill('0') << setw(4) << N;
    return 0;
}