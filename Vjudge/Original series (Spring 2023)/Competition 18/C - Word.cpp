#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s, uppercase, lowercase;
    cin >> s;

    int lower = 0;
    int upper = 0;

    for (auto it : s){
        if (islower(it)){
            lower++;
            
        }
        else if (isupper(it)){
            upper++;
        }
        lowercase += tolower(it);
        uppercase += toupper(it);
    }
    // cout << lower << " " << upper;
    if (upper < lower){
        cout << lowercase;
    }
    else if (upper > lower){
        cout << uppercase;
    }
    else{
        cout << lowercase;
    }
    
    return 0;
}