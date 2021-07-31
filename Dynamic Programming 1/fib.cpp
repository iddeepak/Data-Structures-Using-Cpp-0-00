#include<iostream>
using namespace std;

//Brute Force
/*//Normal Function O(2^n)
int fibo(int n){
    if(n<=1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}
*/

// Memoization (Top-Down Approach)
int fibo_Helper(int n,  int* ans){
    if(n<=1){
        return n;
    }
    // check if output already exist
    if(ans[n] != -1){
        return ans[n];
    }
    
    int a = fibo_Helper(n-1,ans);
    int b = fibo_Helper(n-2,ans);
    // Save the output for future use
    ans[n] = a+b;
    
    return ans[n];
}
//O(n) T.C.
int fibo_2(int n){
    int *ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }
    int a = fibo_Helper(n,ans);
    delete [] ans;
    return a;
}

//Iterative
//Dynamic Programming (Bottom -Up Approach)
//O(n)
int fibo_3(int n){
    int* ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    for(int i=2;i<= n;i++){
        ans[i] = ans[i-1]+ans[i-2];
    }
    return ans[n];
}

int main() {
    int n;
    cout<<"Enter the i-th position of fibonnaci series to calculate the number at that point\n";
    cin>>n;
    cout<<fibo_2(n)<<endl;
    return 0;
}
