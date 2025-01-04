#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    string s;
    cin >> s;

    stack<char> brackets;
    for (auto it : s){
        if (brackets.empty()){
            brackets.push(it);
        }
        else{
            if (it == ')'){
                if (brackets.top() == '('){
                    brackets.pop();
                }
                else{
                    brackets.push(it);
                }
            }
            else{
                brackets.push(it);
            }
        }
    }

    int max_length = s.size() - brackets.size();
    cout << max_length;
    return 0;
}