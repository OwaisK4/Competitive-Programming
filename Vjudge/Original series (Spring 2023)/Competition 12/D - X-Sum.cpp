#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


long int calculate_diagonals(int i, int j, int N, int M, long int **table){
    long int sum = table[i][j];

    for (int a=i-1, b=j-1; a>=0, b>=0; a--, b--){
        sum += table[a][b];
    }
    for (int a=i+1, b=j+1; a<N, b<M; a++, b++){
        sum += table[a][b];
    }

/*
    for (int a=i+1, b=j-1; a<N, b>=0; a++, b--){
        sum += table[a][b];
    }
    for (int a=i-1, b=j+1; a>=0, b<M; a--, b++){
        sum += table[a][b];
    }
*/
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T, N, M;
    cin >> T;
    while (T--){
        cin >> N >> M;
        // int table[N][M];
        long int **table = new long int*[N];
        for (int i=0; i<N; i++){
            table[i] = new long int[M];
        }
        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                cin >> table[i][j];
            }
        }

        long int sum[N][M];
        long int maximum = 0;

        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                sum[i][j] = calculate_diagonals(i, j, N, M, table);
                maximum = max(maximum, sum[i][j]);
            }
        }
        cout << maximum;

    }    
    return 0;
}