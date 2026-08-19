#include <iostream>
#include <string>
using namespace std;

class customStack{
	
	public:
	int top=0;
	int found=0;
	string* array;
	void createarray(int n)
	{
		array=new string[n];
		
		for(int i=0;i<n;i++)
		array[i]="0";
	}
	void push(string& s)
	{
		found=0;
		for(int i=0;i<top;i++)
	    {
		    if(array[i]==s)
		    found=1;
	    }
	
	    if(found==0)
        {
            array[top]=s;
            top++;
        }
	}
};

int main()
{
    int t;
    cin >> t;
    while (t--){
	int n=0;
	string s;
	
	cin>>n;
	cin>>s;
	
	customStack obj;
	obj.createarray(n);
	

	for(int i=0;i<n-1;i++)
	{
			string test;
		test.push_back(s[i]);
		test.push_back(s[i+1]);
		
	//	cout<<endl<<test<<endl;
		obj.push(test);
	}
	cout<<obj.top << "\n";
    }
}