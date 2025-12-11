#include <bits/stdc++.h>

using namespace std;

int main(){
	string x;
	while(cin >> x){
		string s[2000] = {};
		int c = 2;
		int i;
		s[1] = x;
		while(s[c - 1] != "-==-"){
			cin >> s[c];
			if(s[c] == "you") s[c] = "we";
			++c;
		}
		c = c - 2;
		for(i = 1; i <= c; ++i){
			cout << s[i] << (i [1]1= c ? ' ' : '\n')
		}	
		}
	}
}
