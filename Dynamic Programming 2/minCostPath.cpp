// Given an integer matrix of size m*n, you need to find out the value of minimum cost to reach from the cell (0, 0) to (m-1, n-1).
// From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1) and (i+1, j+1).
// Cost of a path is defined as the sum of values of each cell through which path passes.

#include <iostream>
#include<cmath>
#include<climits>
using namespace std;

//Basic Recusrion
int minCostPath(int** a , int m, int n, int x, int y){
	if(m-1==x && n-1==y){
		return a[x][y];
	}
	
	if(x >= m ||  y>= n){
		return INT_MAX;
	}
	
	int e = minCostPath(a,m,n, x,y+1);
	int b = minCostPath(a,m,n,x+1,y+1);
	int c = minCostPath(a,m,n,x+1,y);
	
	int d = min(e,min(b,c));
	return a[x][y]+d;
	
}

int minCostPath(int** ans, int m , int n){
	return minCostPath(ans,m,n,0,0);
}


//Memoization
int minCostPath2(int** a , int m, int n, int x, int y , int** ans){
	//Base Case
	if(m-1==x && n-1==y){
		return a[x][y];
	}
	
	if(x >= m ||  y>= n){
		return INT_MAX;
	}
	
	//ans Check
	if(ans[x][y]!=-1){
		return ans[x][y];
	}
	
	//Recursion Call
	int e = minCostPath2(a,m,n, x,y+1,ans);
	if(e<INT_MAX){
		ans[x][y+1]  = e;
	}
	
	int b = minCostPath2(a,m,n,x+1,y+1,ans);
	if(b<INT_MAX){
		ans[x+1][y+1] = b;
	}
	
	int c = minCostPath2(a,m,n,x+1,y,ans);	
	if(c<INT_MAX){
		ans[x+1][y] = c;
	}
	
	//Small calulation
	int d = min(e,min(b,c));
	ans[x][y] = a[x][y]+d;;
	return ans[x][y]; 
	
}

int minCostPath2(int** input, int m , int n){
	int** ans = new int*[m];
	for(int i=0;i<m;i++){
		ans[i] = new int[n];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			ans[i][j]=-1;
		}
	}
	int a = minCostPath2(input,m,n,0,0,ans);
	for(int i=0;i<m;i++){
		delete [] ans[i];
	}
	delete []ans;
	return a;	
}


//Dynamic Programmig
int minCostPathDP(int** input, int m, int n){
	int** ans = new int*[m];
	for(int i=0;i<m;i++){
		ans[i] = new int[n];
	}
	
	ans[m-1][n-1] = input[m-1][n-1];
	
	//Last Row (m-1)Fixed n=0 to n-2
	for(int j=n-2; j>=0;j--){
		ans[m-1][j] = ans[m-1][j+1]+input[m-1][j];
	}
	//Last Col Fixes(n-1)  m=0 to m-1
	for(int j=m-2; j>=0;j--){
		ans[j][n-1] = ans[j+1][n-1]+input[j][n-1];
	}
	
	for(int i=m-2;i>=0;i--){
		for(int j=n-2;j>=0;j--){
			ans[i][j] = input[i][j]+min(ans[i][j+1],min(ans[i+1][j+1],ans[i+1][j]));
		}
	}
	return ans[0][0];
}


int main()
{
	int m,n;
	cin>>m>>n;
	int** ans = new int*[m];
	for(int i=0;i<m;i++){
		ans[i] = new int[n];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>ans[i][j];
		}
	}
	
	int minCost = minCostPathDP(ans,m,n);
	cout<<minCost<<endl;
	
	for(int i=0;i<m;i++){
		delete [] ans[i];
	}
	delete []ans;
	return 0;
}
