// Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
// That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.

#include <iostream>
#include<climits>
using namespace std;


//Brute Force
int solveBF(int n){
	if(n<=1){
		return n;
	}
	int b=INT_MAX;
	for(int i=1;i*i<=n;i++){
		int a = 1+solveBF(n-(i*i));
		if(a<b){
			b=a;
		}
	}
	return b;
}

//Memoization
int solveMem(int n, int* ans){
	// Base Case
	if(n<=1){
		return n;
	}
	
	//Check if ans Exist
	if(ans[n] != -1){
		return ans[n];
	}
	
	//Small calculation
	int b= INT_MAX;
	for(int i=1;i*i<=n;i++){
		int a = 1+solveMem(n-(i*i),ans);
		if(a<b){
			b=a;
		}
	}
	ans[n] = b;
	return b;	
}

int solveMem(int n){
	int* ans = new int [n+1];
	for(int i=0;i<=n;i++){
		ans[i] = -1;
	}
	ans[0] = 0;
	ans[1] = 1;
	int count = solveMem(n,ans);
	delete [] ans;
	return count;
}

//Dynamic Programming
int solveDP(int n){
	if(n<=0)
		return 0;
	if(n==1)
		return 1;
	
	int* ans = new int[n+1];
	 *(ans +0) = 0;
	 *(ans+1) =1;
	 
	 for(int i=2; i<= n; i++){
		ans[i] = INT_MAX;
		for(int j=1; j*j<=i;j++){
			int a = 1+ ans[i-(j*j)];
			if(a<ans[i]){
				ans[i] = a;
			}
		} 
	 }
	int output = ans[n];
	delete []  ans;
	return output;
}

int main()
{
	int n;
	cin >> n;
	cout << solveDP(n)<<endl;
    return 0;
}
