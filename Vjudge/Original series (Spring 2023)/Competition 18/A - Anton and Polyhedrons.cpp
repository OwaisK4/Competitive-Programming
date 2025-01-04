#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int faces(string s){
    if (s == "Tetrahedron")
        return 4;
    else if (s == "Cube")
        return 6;
    else if (s == "Octahedron")
        return 8;
    else if (s == "Dodecahedron")
        return 12;
    else if (s == "Icosahedron")
        return 20;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    string s;
    long long int sum = 0;

    for (int i=0; i<N; i++){
        cin >> s;
        sum += faces(s);
    }

    cout << sum;
    
    return 0;
}