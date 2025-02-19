#include<bits/stdc++.h>
#include<ctype.h>
#include <cwctype>
#include <string.h>
using namespace std;

int main(){
	int n, k=0, i, j;
	char input[100];
	char reverse[100];
//	cin >> input;
//	getline(input);
	scanf("%s", input);
	strlwr(input);
	n = strlen(input);
//	strrev(input);
	cout << input;
	return 0;
	while (1){
		if (strcmp(strrev(input), input) == 0){
			k++;
			if (n % 2 == 0){
				strcpy(reverse, input + (n/2));
				cout << reverse;
				cout << "k = " << k;
				break;
			}
		}
	}
}
