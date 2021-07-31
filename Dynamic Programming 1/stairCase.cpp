// A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child
// can run up to the stairs. You need to return all possible number of ways.
// Time complexity of your code should be O(n).

#include <iostream>
using namespace std;

// DP
long staircase(int n)
{
	if(n<=0){
        return 0;
    }
    
    long long int* ans = new long long int[n+1];
    
    ans[0] = 1;
    ans[1] = 1;
    
    for(int i=2;i<=n;i++){
        long long int output =0;
        if(i-1 >=0){
            output += ans[i-1];
        }
        if(i-2 >= 0){
            output += ans[i-2];
        }
        
        if(i-3 >= 0){
            output += ans[i-3];
        }
        
        ans[i] = output;
    }
    
    long long int Finaloutput = ans[n];
    delete [] ans;
    return Finaloutput;
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}
