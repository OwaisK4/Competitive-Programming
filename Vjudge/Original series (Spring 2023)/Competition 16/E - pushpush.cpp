#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int A[N];
    for (int i=0; i<N; i++){
        cin >> A[i];
    }

    bool odd = N % 2;       // is 0 if N is even
    deque<int> b;

    for (int i=0; i<N-1; i+=2){
        b.push_back(A[i]);
        b.push_front(A[i+1]);
    }
    if (odd){
        b.push_back(A[N-1]);
        reverse(b.begin(), b.end());
    }

    for (auto it : b){
        cout << it << " ";
    }

    return 0;
}