#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <climits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    map<int, int> n1, n2;
    cin >> N;

    int V[N];
    for (int i = 0; i < N; i++){
        cin >> V[i];
    }

    int errors = 0;
    for (int i = 0; i < N-3; i+=2){
        if (V[i] != V[i+2]){
            n1[V[i]]++;
            errors++;
        }
        if (V[i+1] != V[i+3]){
            n2[V[i+1]]++;
            errors++;
        }

        if (V[i] == V[i+1]){
            n1[V[i]]++;
            errors++;
        }
        if (V[i+1] == V[i+2]){
            n2[V[i+1]]++;
            errors++;
        }
            
    }
    // cout << errors << "\n";

    int n1_min = INT_MAX;
    int n2_min = INT_MAX;
    for (auto it : n1){
        n1_min = min(n1_min, it.second);
        // cout << it.first << " " << it.second << "\n";
    }
    // cout << "\n";
    for (auto it : n2){
        n2_min = min(n2_min, it.second);
        // cout << it.first << " " << it.second << "\n";
    }
    if (n1_min == INT_MAX)
        n1_min = 0;
    if (n2_min == INT_MAX)
        n2_min = 0;
    errors = n1_min + n2_min;
    cout << errors;

    return 0;
}