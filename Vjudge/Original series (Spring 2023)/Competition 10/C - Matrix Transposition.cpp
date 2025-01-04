#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int H, W;
    cin >> H >> W;
    long int array[H][W];
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cin >> array[i][j];
        }
    }

    for (int i = 0; i < W; i++){
        for (int j = 0; j < H; j++){
            cout << array[j][i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}