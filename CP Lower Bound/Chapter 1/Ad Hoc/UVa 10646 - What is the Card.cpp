#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int card_hash(string card){
    int value = 0;
    int multiplier = 13;
    if (card[0] == 'D'){
        value += (0 * multiplier);
        value += (card[1] - 48 - 2);
    }
    else if (card[0] == 'C'){
        value += (1 * multiplier);
        value += (card[1] - 48 - 2);
    }
    else if (card[0] == 'H'){
        value += (2 * multiplier);
        value += (card[1] - 48 - 2);
    }
    else{
        value += (3 * multiplier);
        value += (card[1] - 48 - 2);
    }
    return value;
}

int main(){
    string card = "SA";
    int value = card_hash(card);
    cout << value;
    return 0;
}