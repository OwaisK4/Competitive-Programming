#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long
using namespace std;

signed main(){
    fstream f("input", ios::in);
    string line, input;
    while (getline(f, line)){
        input += line;
        input += " ";
    }
    cout << input << "\n";
    f.close();

    string word = "love";
    int start = 0;
    int end = input.find(word);
    while (end != input.npos){
        cout << end << " ";
        start = end;
        end = input.find(word, start + 1);
    }

    return 0;
}