#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int get_max_power_of_two(int num){
    int power = 31;
    int max_power = 0;
    for (int i = power; i >= 0; i--){
        if (num & (1 << i)){
            max_power = i;
            break;
        }
    }
    return max_power;
}

int main(){
    int a = (1 << 31);
    int answer = get_max_power_of_two(a);
    cout << answer << " " << (1 << answer) << "\n";
    return 0;
}