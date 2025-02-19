#include<bits/stdc++.h>
#include <cwctype>
#include <cstring>
#include <string.h>

using namespace std;
int main(){
	string input;
	int n, k=0, i, j;
	cin >> input;
	for (i=0; i< input.length(); i++){
		if (input[i] >= 'A' && input[i] <= 'Z'){
			input[i] = char(input[i]+32);
		}
	}
//	cout << input;
	n = input.length();
	string reverse(input.rbegin(), input.rend());
//	cout << reverse << endl;
	while (1){
		reverse = string(input.rbegin(), input.rend());
		if (n==1){
			break;
		}
		if (input.compare(reverse) == 0){
			k++;
			if (n % 2 == 0){
				input.erase(input.begin()+ (n/2),input.end());
//				cout << input;
//				cout << "\nk = " << k << endl;
				n /= 2;
			}
			else if (n % 2 != 0){
				input.erase(input.begin()+((n+1)/2),input.end());
//				cout << input;
//				cout << "\nk = " << k;
				n /= 2;
			}
		}
		else{
			break;
		}
	}
	cout << k;
	return 0;
}
