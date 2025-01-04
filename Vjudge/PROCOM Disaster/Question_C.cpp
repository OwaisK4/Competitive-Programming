#include<bits/stdc++.h>
#include<ctype.h>
#include <cwctype>
#include <string.h>

int play(int n, int a[3], int b[3], int flag){
	int min=n, max=0;
	int i, j, k;
	if (a[0] && b[2]){
		for (j=a[0], k=b[2]; j>0 || k>0; j--, k--){
			max++;
		}
		for(j=a[0], k=b[1]; j>0 || k>0; j--, k--){
			min++;
		}
	}
	if (a[1] && b[2]){
		for (j=a[1], k=b[2]; j>0 || k>0; j--, k--){
			max++;
		}
		for(j=0; j<b[2]; j++){
			min++;
		}
	}
	if (a[2] && b[0]){
		for (j=a[2], k=b[0]; j>0 || k>0; j--, k--){
			max++;
		}
		for(j=0; j<b[0]; j++){
			min++;
		}
	}
//	}
	if (flag == 0)
		return min;
	else
		return max;
}

using namespace std;
int main(void){
	int n, a[3], b[3];
	int i, j;
	cin >> n;
	cin >> a[0] >> a[1] >> a[2];
	cin >> b[0] >> b[1] >> b[2];
	cout << play(n, a, b, 1);
	cout << play(n, a, b, 0);
}

