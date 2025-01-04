#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    string s = "I hate it";
    int counter = 0;

    while (N-- > 1){
        s.erase(s.size() - 2);
        if (counter){
            s += "that I hate it";
            counter = 0;
        }
        else{
            s += "that I love it";
            counter = 1;
        }
    }

    cout << s;
    
    return 0;
}