#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> array(N);
    int counter = 1;
    for (int i=1; i<N; i+=2){
        array[i] = counter++;
    }
    for (int i=0; i<N; i+=2){
        array[i] = counter++;
    }
    
    for (int i=0; i<N-1; i++){
        if (abs(array[i] - array[i+1]) <= 1){
            cout << "NO SOLUTION";
            return 0;
        }
    }
    for (auto it : array){
        cout << it << " ";
    }
    return 0;
}