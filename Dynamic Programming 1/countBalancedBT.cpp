// Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
// This number can be huge, so return output modulus 10^9 + 7.


#include <iostream>
#include<cmath>
using namespace std;

int balBT_BF(int h){
	if(h<=1){
		return 1;
	}
	int mod = (int)(pow(10,9))+7;
	int c1 = balBT_BF(h-1);
	int c2 = balBT_BF(h-2);
	int t1 = (int)(((long)(c1)*c1)%mod);
	int t2 = (int)((2*(long)(c1)*c2)%mod);
	int ans = (t1+t2)%mod;
	return ans;
}

int main()
{
	int h;
	cin >> h;
	cout << balBT_BF(h)<<endl;
}
