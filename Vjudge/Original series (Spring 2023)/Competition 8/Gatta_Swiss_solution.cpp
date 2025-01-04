#include <bits/stdc++.h>

using namespace std;


int main (){
   int n,m;
   cin>>n>>m;
   vector<pair<int,int>> v;
   for (int i=1;i<=2*n;i++)
   {
        v.push_back(make_pair(i,0));
   }
   char arr[2*n][m];
   for (int i=0;i<2*n;i++)
   {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];         
        } 
   }
   for (int i=0;i<m;i++)
   {
        for (int j=1;j<=n;j++)
        {
            if (arr[(v[2*j-1].first)-1][i]=='G' && arr[(v[2*j-1-1].first)-1][i]=='P')
            {
                v[2*j-1-1].second++;
            }
            else if (arr[(v[2*j-1].first)-1][i]=='G' && arr[(v[2*j-1-1].first)-1][i]=='C')
            {
                v[2*j-1].second++;
            }
            else if (arr[(v[2*j-1].first)-1][i]=='C' && arr[(v[2*j-1-1].first)-1][i]=='P')
            {
                v[2*j-1].second++;
            }
            else if (arr[(v[2*j-1].first)-1][i]=='C' && arr[(v[2*j-1-1].first)-1][i]=='G')
            {
                v[2*j-1-1].second++;
            }
            else if (arr[(v[2*j-1].first)-1][i]=='P' && arr[(v[2*j-1-1].first)-1][i]=='G')
            {
                v[2*j-1].second++;
            }
            else if (arr[(v[2*j-1].first)-1][i]=='P' && arr[(v[2*j-1-1].first)-1][i]=='C')
            {
                v[2*j-1-1].second++;
            }
        }
        for (int k=0;k<2*n;k++)
        {
            pair<int,int> p1;
            pair<int,int> p2;
            for (int j=0;j<2*n-1;j++)
            {
                pair <int,int> temp;
                if (v[j].second<v[j+1].second)
                {
                    temp=v[j];
                    v[j]=v[j+1];
                    v[j+1]=temp;
                }
                else if (v[j].second==v[j+1].second && v[j].first>v[j+1].first)
                {
                    temp=v[j];
                    v[j]=v[j+1];
                    v[j+1]=temp;
                }
            }
        }
   }
   for (int i=0;i<2*n;i++)
   {
        cout<<v[i].first<<endl;
   }   
}