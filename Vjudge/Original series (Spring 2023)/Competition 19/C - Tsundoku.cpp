#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(N), B(M);

    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    for (int i=0; i<M; i++){
        cin >> B[i];
    }

    sort(all(A));
    sort(all(B));

    int time = 0;
    int i = 0, j = 0, books = 0;

    while (time <= K && i < N && j < M){
    // for (; i < N, j < M; )
        if (A[i] <= B[j] && (time + A[i] <= K)){
            time += A[i];
            i++;
            books++;
        }
        else if (A[i] > B[j] && (time + B[j] <= K)){
            time += B[j];
            j++;
            books++;
        }
        else{
            break;
        }
    }
    while (i < N){
        if (time + A[i] <= K){
            time += A[i];
            i++;
            books++;
        }
    }
    while (j < M){
        if (time + B[j] <= K){
            time += B[j];
            i++;
            books++;
        }
    }

    cout << books;
    
    return 0;
}