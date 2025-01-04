#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    int t;
    long long int n;
    cin >> t;

    while (t--){
        cin >> n;
        long long int temp = n;
        unsigned long long int divisor = 10;
        map<int, int> freq;
        while (true){
            bool flag = true;
            temp = n;
            while (temp){
                int a = temp % divisor;
                if (a != 0 && n % a != 0){
                    flag = false;
                    break;
                }
                temp /= divisor;
            }
            if (!flag){
                n++;
            }
            else{
                cout << n << "\n";
                break;
            }
        }


        // // unsigned long long int divid = freq.begin()->first;
        // auto divid = freq.begin()->first;

        // for (auto it : freq){
        //     divid = (divid * it.first) / gcd(divid, it.first);
        // }
        // cout << divid << " ";

        // while (n % divid != 0){
        //     n++;
        // }
        // cout << n << "\n";

        // unsigned long long int divid = ;
        // for (int i=1; i<10; i++){
        //     if (freq[i] != 0)
        //         divid *= i;
        // }
        // // cout << divid << " ";
        // while (n % divid != 0){
        //     n++;
        // }
        // cout << n << "\n";

        // for (int i=1; i<10; i++){
        //     if (freq[i] != 0){
        //         // if (n % i != 0)
        //         //     flag = false;
        //         while (n % i != 0){
        //             n++;
        //         }
        //     }
        // }

        // for (auto it : freq){
        //     cout << it.first << " ";
        // }
        // cout << "\n";
    }

    return 0;
}