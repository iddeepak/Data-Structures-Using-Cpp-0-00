//Longest Common Subsequence-----

#include <iostream>
#include<string>
#include<cmath>
using namespace std;

//Basic Recursion
int lcs(string s, string t){
	if(s.length()==0 || t.length() == 0){
		return 0;
	}
	
	if(s[0] == t[0]){
		return 1+lcs(s.substr(1), t.substr(1));
	}
	
	else{
		int a = lcs(s,t.substr(1));
		int b = lcs(s.substr(1),t);
		return max(a,b);
	}
}

int main()
{
	string s,t;
	cin>>s>>t;
	cout<<lcs(s,t)<<endl;
	return 0;
}
