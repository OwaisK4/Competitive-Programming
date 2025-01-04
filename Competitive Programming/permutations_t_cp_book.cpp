#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

void permute(string source, string generated, vector<string>& permutations, bool chosen[]){
    if (generated.size() == source.size()){
        permutations.push_back(generated);
        return;
    }
    else{
        for (int i=0; i<source.size(); i++){
            if (chosen[i])
                continue;
            chosen[i] = true;
            generated += source[i];
            permute(source, generated, permutations, chosen);
            // generated.erase(generated.end()-1);
            generated.pop_back();
            chosen[i] = false;
        }
    }
}

int main(){
    fstream file("output.txt", ios::out);
    string source = "ABCDE";
    // string source = "ABCDEFGHIJ";
    size_t size = source.size();
    vector<string> permutations;
    bool chosen[size] = {false};
    memset(chosen, 0, sizeof(bool) * size);
    permute(source, "", permutations, chosen);
    for (auto& it : permutations){
        cout << it << "\n";
        file << it << "\n";
    }
    return 0;
}