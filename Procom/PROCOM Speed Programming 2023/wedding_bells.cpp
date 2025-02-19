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
	cout << endl;
	while (T--){
		for (i=1; i<=N; i++){
			for (j=1; i!=j, j<=N; j++){
				vector<int> v1;				
				flag = 0;
				for (k=0; k<M; k++){
					if (((i == incompatible[k][0]) && (j == incompatible[k][1]))) //|| ((i == incompatible[k][1]) && (j == incompatible[k][0])))
						flag = 1;
				}
				if (!flag){
//					for (size_t m = 0; m < compatible.size(); m++){
//        				for (size_t n = 0; n < compatible[i].size(); n++)
//	        			    cout << compatible[m][n] << " ";
//						cout << endl;
//    				}
					v1.push_back(i);
					v1.push_back(j);
					compatible.push_back(v1);
					cout << "(" << i << ", " << j << ")\n";
				}
			}
		}
	}
	
	for (size_t m = 0; m < compatible.size(); m++){
	    for (size_t o = 0; o < compatible.size(); o++){
	    	if (!((compatible[m][0] == compatible[o][0]) && (compatible[m][1] == compatible[o][1]))){
	   			if ((compatible[m][0] == compatible[o][1]) && (compatible[m][1] == compatible[o][0])){
//					compatible[m].clear();
//					compatible.erase(compatible.begin() + o);
					cout << "found ";
					cout << compatible[m][0] << " " << compatible[m][1] << "\t" << compatible[o][0] << " " << compatible[o][1] << "\n";
					compatible.erase(compatible.begin() + o);
					break;
				}
			}
		}
	}
	cout << endl;
//	for (auto it = compatible.begin(); it != compatible.end(); it++){
//		for(auto jt = it->begin() ; jt<it->end() ; jt++){
//			cout << *jt << " ";
//			sum += 1;
//		}
//		cout << endl;
//	}
	for (int it = 0; it < compatible.size(); it++){
		for(int jt = 0; jt < compatible[it].size(); jt++){
			cout << compatible[it][jt] << " ";
			sum += 1;
		}
		cout << endl;
	}
	cout << "\n" << sum;
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
