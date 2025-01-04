#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

string reverse(int L, int R, string original){
    string temp;
    for (int i=L-1; i<R; i++){
        temp += original[i];
    }
    int start = 0, end = temp.size() - 1;
    while (start <= end){
        swap(temp[start], temp[end]);
        start++;
        end--;
    }
    for (int i=L-1, j=0; i<R, j<temp.size(); i++, j++){
        original[i] = temp[j];
    }
    return original;
    // cout << temp << " ";
}

int main(){
    // string a = "abcdefgh";
    // int L = 3, R = 7;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string S;
    int L, R;
    cin >> L >> R;
    cin.ignore();
    getline(cin, S);
    string result = reverse(L, R, S);
    cout << result;
    return 0;
}