#include<bits/stdc++.h>
#include<ctype.h>
#include <cwctype>
#include <string.h>

int main()
{
	int n;
	int a[n], b[n], c=0;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i] >> b[i];
	}
	for(int i=0; i<n; i++){
		if(a[i] > b[i]){
			if(a[i] % b[i] == 0){
				c =0;
			}
			else{
				c =1
			}
		}
		if(a[i] < b[i]){
			if(a[i] % b[i] == 0){
				c =0;
			}
			else {
				c =1;
			}
		}
		
	}
	
}
