#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

void check(long long int product, long long int generated, vector<int> values[], int index, int& count, int N){
    if (index >= N){
        if (product == generated){
            count++;
        }
        return;
    }
    if (product < generated)
        return;
    for (int i = 0; i<values[index].size(); i++){
        check(product, generated * values[index][i], values, index + 1, count, N);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, L, temp;
    long long int X;
    cin >> N >> X;
    vector<int> values[N];
    for (int i=0; i<N; i++){
        cin >> L;
        for (int j=0; j<L; j++){
            cin >> temp;
            values[i].push_back(temp);
        }
    }

    int count = 0;
    check(X, 1, values, 0, count, N);
    cout << count;
    /*
    for (int i=0; i<N; i++){
        for (auto& it : values[i]){
            cout << it << " ";
        }
        cout << "\n";
    }
    */
    return 0;
}