#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long
using namespace std;

signed main(){
    int N;
    cin >> N;

    if (N <= 1){
        cout << 0;
        return 0;
    }

    vector<int> books(N);
    int temp;

    for (int i=0; i<N; i++){
        cin >> temp;
        books[i] = temp;
    }
    sort(all(books));
    
    int i=0, j=N-1;
    int duplicates = 0;
    int current;
    current = books[i];

    while (i < j){
        // cout << "Current = " << current << "\n";
        if (books[i+1] == current + 1){
            i++;
            current++;
        }
        else if (books[i+1] == current){
            i++;
            duplicates++;
        }
        else{
            if (duplicates >= 2){
                duplicates -= 2;
                current++;
            }
            else if (duplicates == 1 && i < j){
                duplicates--;
                current++;
                j--;
            }
            else if (duplicates == 0 && i < j-1){
                j -= 2;
                current++;
            }
            else{
                break;
            }
        }
    }
    if (duplicates){
        current += (duplicates / 2);
    }

    cout << current;
    // for (int i=0; i<N; i++){
    //     cout << books[i] << " ";
    // }


    return 0;
}