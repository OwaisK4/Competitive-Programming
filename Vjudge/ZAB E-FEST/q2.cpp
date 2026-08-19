#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;

signed main(){
    //int array[] = { 7, 15, 11, 2};
    int array[] = {31, 2, 5, 11, 7};
    int target = 9;
    int N = sizeof(array);

    //bool flag = false;
    for (int i=0; i<N-1; i++){
        for (int j=i+1; j<N; j++){
            if (array[i] + array[j] == target){
                cout << i << "," << j << "\n";
                return 0;
            }
        }
    }
    cout << "Not found";
    return 0;
}
