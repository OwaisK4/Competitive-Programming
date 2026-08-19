#include<bits/stdc++.h>
#include<ctype.h>
#include <cwctype>
#include <string.h>
using namespace std;

int main(){
	string input;
	int n, k=0, i, j;
	cin >> input;
//	cout << input;
	n = input.length();
	string reverse(input.rbegin(), input.rend());
	cout << reverse << endl << endl;
	while (1){
		if (input.compare(reverse) == 0){
			k++;
			if (n % 2 == 0){
				reverse.erase(reverse.begin()+ (n/2),reverse.end());
				cout << reverse;
				cout << "\nk = " << k;
				break;
			}
			else{
				reverse.erase(reverse.begin()+((n+1)/2),reverse.end());
				cout << reverse;
				cout << "\nk = " << k;
				break;
			}
		}
//		break;
	}
}
