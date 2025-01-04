#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int X;
    cin >> X;
    
    string temp;
    int counter = 0;
    for (int i=0; i<X; i++){
        cin >> temp;
        if (temp.find("++", 0) != temp.npos){
            counter++;
        }
        else if (temp.find("--", 0) != temp.npos){
            counter--;
        }
    }
    cout << counter;

    return 0;
}