#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int snap(){
    if ((random() / 141) % 2 == 0)
        return 1;       // Jane
    else
        return -1;      // John
}

int main(){
    int t;
    cin >> t;
    while (t--){
        string jane, john;
        cin.ignore();
        cin >> jane;
        cin >> john;

        string jane_stack, john_stack;
        
    }
    return 0;
}