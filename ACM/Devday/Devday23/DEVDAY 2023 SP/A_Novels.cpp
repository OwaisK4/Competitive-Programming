#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long
using namespace std;

signed main(){
    int N;
    cin >> N;

    vector<int> books(N);
    int temp;

    for (int i=0; i<N; i++){
        cin >> temp;
        books[i] = temp;
    }
    sort(all(books));
    
    int duplicates = 0;
    for (int i=0; i<N-1; i++){
        if (books[i] == books[i+1])
            duplicates++;
    }

    set<int> book(all(books));
    int count = 0;


    return 0;
}