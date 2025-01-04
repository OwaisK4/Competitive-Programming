#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <functional>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, temp;
    cin >> N;

    vector<int> array(4);
    long long int cars = 0;

    for (int i=0; i<N; i++){
        cin >> temp;
        array[temp - 1]++;
    }
    int one = array[0];
    int two = array[1];
    int three = array[2];
    int four = array[3];

    cars += four;

    cars += three;
    if (one < three){
        one = 0;
    }
    else{
        one -= three;
    }

    cars += (two / 2);
    if (two % 2 != 0){
        if (one < 2)
            one = 0;
        else
            one -= 2;
        cars++;
    }

    cars += ceil(one / 4.0);

    cout << cars;

    return 0;
}