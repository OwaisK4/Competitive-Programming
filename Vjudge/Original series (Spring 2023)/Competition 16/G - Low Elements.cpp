#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int P[N];
    for (int i=0; i<N; i++){
        cin >> P[i];
    }

    int last = P[0];
    int count = 1;

    for (int i=1; i<N; i++){
        if (last >= P[i]){
            last = P[i];
            count++;
        }
    }
    cout << count;
    
    return 0;
}