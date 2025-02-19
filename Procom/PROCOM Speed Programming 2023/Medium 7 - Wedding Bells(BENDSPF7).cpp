#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	int i, j, k;
	int T, M, N;
	int sum=0, flag;
	cin >> T;
	cin >> N >> M;
	int incompatible[M][2];
	vector<vector<int>> compatible;  //[(int)pow(2,N) - M][2];
	memset(incompatible, 0, sizeof(incompatible));
	for (i=0; i<M; i++){
		cin >> incompatible[i][0] >> incompatible[i][1];
	}
	while (T--){
		for (i=1; i<=N; i++){
			for (j=1; i!=j, j<=N; j++){
				flag = 0;
				for (k=0; k<M; k++){
					if (((i == incompatible[k][0]) && (j == incompatible[k][1]))) //|| ((i == incompatible[k][1]) && (j == incompatible[k][0])))
						flag = 1;
				}
				if (!flag){
					compatible[i].push_back(i);
					compatible[i].push_back(j);

					cout << "(" << i << ", " << j << ")\n";
				}
			}
			compatible.push_back(vector<int>());
		}
	}
	cout << "\n" << sum;
	for (i=0; i<M; i++){
		cout << "\n" << incompatible[i][0] << " " << incompatible[i][1];
	}
	for (auto it = compatible.begin(); it != compatible.end(); it++){
		for(auto jt = it->begin() ; jt<it->end() ; jt++){
			cout << *jt;
		}
//		cout << "\n"
	}
	return 0;
}

/*
//					sum++;
//					for(vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
//    					it->doSomething();
// 					}
					
//					for (auto it = compatible.begin(); it != compatible.end(); it++)
//    					cout << *it << " ";
*/
