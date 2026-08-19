#include<bits/stdc++.h>
#include<ctype.h>
using namespace std;

int main(){
	int n, k, a[k], b[k], i, j, counter=0;
	int constant = 10000;
	cin >> n >> k;
	for (i=0; i<k; i++){
		cin >> a[i] >> b[i];
	}
	for (counter = 0; counter < constant; counter++){
		for (i=0; i<k; i++){
		if (b[i] >= 2){
			if (i == 0){
				b[1]++;
				b[2]++;
				b[0]--;
			}
			else if (i == 1){
				b[0]++;
				b[2]++;
				b[1]--;
			}
			else{
				b[0]++;
				b[1]++;
				b[2]--;
			}
		}
		else{
			cout << 1;
			return 0;
		}
		}
	}
	cout << -1;
	return 0;
}
