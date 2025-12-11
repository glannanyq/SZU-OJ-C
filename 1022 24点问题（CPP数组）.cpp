#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t , i , s , k ;
	int a[5] ;
	int c ;
	cin >> t ;
	while(t--)
	{
		c = 0 ;
		for(i = 0 ; i < 5 ; i++)
			cin >> a[i] ;
		for(k = 0 ; k < 16 ; k++)
		{
			s = a[0] ;
			for(i = 0 ; i < 4 ; i++)
			{
				if(k & (1 << i))
					s -= a[i + 1] ;
				else
					s += a[i + 1] ;
			}
			if(s == 24)
				c++ ;
		}
		cout << c << endl;
	}
}
