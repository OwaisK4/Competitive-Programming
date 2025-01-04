#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> find_substring(string T, string sub){
    size_t index = 0;
    vector<int> indexes;
    while ((index = T.find(sub, index)) != T.npos){
        // cout << index << " ";
        indexes.push_back(index);
        index += 1;
    }
    if (indexes.empty())
        indexes.push_back(-1);
    return indexes;
}

vector<string> tokenize(string T, char token=' '){
    size_t start = 0;
    size_t index = 0;
    vector<string> tokens;
    while ((index = T.find(token, index)) != T.npos){
        string sub = T.substr(start, index - start);
        tokens.push_back(sub);
        start = index - 1;
        index += 1;
        // index += 1;
    }
}

int main(){
    fstream f("file.txt", ios::in);
    string line;
    string T;
    while (getline(f, line)){
        T += line;
        T += " ";
        if (line.substr(0, 7) == "......."){
            break;            
        }
    }
    cout << T << "\n";

    string sub = "book";
    for (auto it : find_substring(T, sub)){
        cout << it << " ";
    }
    cout << "\n";

    for (auto it : tokenize(T)){
        cout << it << " ";
    }
    f.close();
    return 0;
}