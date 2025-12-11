#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n , l , z , f ;
	l = z = f = 0 ;
	string name ;
	cin >> n ;
	while(n--)
	{
		cin >> name ;
		if(name == "Li")
			++l ;
		if(name == "Zhang")
			++z ;
		if(name == "Fu")
			++f ;
	}
	cout << "Li:" << l << "\n" << "Zhang:" << z << "\n" << "Fu:" << f << "\n" ;
}
