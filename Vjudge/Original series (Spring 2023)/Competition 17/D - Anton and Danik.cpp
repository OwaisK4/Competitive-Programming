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

    int A = 0, D = 0;
    char temp;
    for (int i=0; i<N; i++){
        cin >> temp;
        if (temp == 'A')
            A++;
        else if (temp == 'D')
            D++;
    }
    if (A > D)
        cout << "Anton";
    else if (A < D)
        cout << "Danik";
    else
        cout << "Friendship";


    return 0;
}