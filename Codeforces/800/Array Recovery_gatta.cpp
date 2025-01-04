#include <vector>
#include <iostream>

using namespace std;

int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> d(n,0),a(n,0);
        for (int i=0;i<n;i++)
        {
            cin>>d[i];
        }
        a[0]=d[0];
        int f=0;
        for (int i=1;i<n;i++)
        {
            int a1,a2;
            a1=(a[i-1]+d[i]);
            a2=(a[i-1]-d[i]);
            if (a1>=0 && a2>=0 && a1!=a2)
            {
                f=1;
                cout<<-1<<endl;
                break;
            }
            else
            {
                if(a1>=0 && a2<0)
                    a[i]=a1;
                else if (a1<0 && a2>=0)
                    a[i]=a2;
                else
                    a[i]=a1;
            }
            
        }
        if (f==0)
        {
            for (int i=0;i<n;i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}