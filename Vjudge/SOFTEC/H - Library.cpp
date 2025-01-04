#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define ll long long int
using namespace std;

int main(){
    int n;
    cin >> n;
    string st;
    getline(cin,st);
    vector<string>s;
    while (cin >> st){
        s.push_back(st);
    }
    for (int i=0;i<n;i++)
        cin>>s[i];
    if (s[0]=="int" && n==1)
    {    cout<<"int";
        return 0;
    }
    else if (s[0]=="int" && n>1)
    {
        cout<<"Error occurred";
        return 0;
    }
    int c=0;
    string ans="";
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=="pair")
        {
            if (ans[ans.length()-1]==',')
            {
                ans+="pair<";    
            }
            else
            {
                ans+="pair<";
            }
            c++;
        }
        else if (s[i]=="int" && ans[ans.length()-1]=='<')
        {
            ans+="int,";
        }
        else if (s[i]=="int" && ans[ans.length()-1]==',')
        {
            ans+="int>";
            c--;
            if (c>0)
                ans+=",";
        }
        // cout<<c<<endl;
    }
    if (c>0)
        cout<<"Error occurred";
    else
        cout<<ans;
    
}