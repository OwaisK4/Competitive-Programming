#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int,int>
#define int long long int
#define nl cout<<endl;
#define PB push_back
#define MP make_pair
#define f(a,b) for(int i = a; i < b; i++)
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int q=1 , t , v;
    cin>>q;
    vector<double> heroes , artifacts;
    while(q--){
        cin >> t >> v;
        if(t == 1) heroes.PB(v);
        else artifacts.PB(v);

        int rounds = 0;
        

        if(heroes.size()){
            sort(heroes.begin() , heroes.end());
            sort(artifacts.begin() , artifacts.end());

            int i = 0 , j = 0 , n = heroes.size() , m = artifacts.size();
            double total_damage = 0.0;
            int r1 , r2 ;
            double damage ;
            int in1 , in2;
            while(i < n ){
                r2 = 1e9;
                damage = 1 / (double(n - i) + double(m - j)) ;
                r1 = (heroes[i] - total_damage) / damage ; 
                if(j<m) r2 = (artifacts[j] - total_damage) / damage ;
                // cout<<heroes[i] << " " ;
                // cout << r1 << " " << r2 << endl;

                int mini = min(r1,r2);
                
                rounds += mini;

                total_damage += (double)mini * damage;
                in1 = upper_bound(heroes.begin() + i, heroes.end() , total_damage) - heroes.begin();
                in2 = upper_bound(artifacts.begin() + j, artifacts.end() , total_damage) - artifacts.begin();

                i = in1;
                j = in2;
                // cout << i << " " << j << " " << rounds << " " << mini << endl;
                
            }
            cout<<rounds;
        }
        else cout << 0 ;
        
        nl
    }	
    return 0;
}