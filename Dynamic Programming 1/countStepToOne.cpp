#include<iostream>
#include<climits>
using namespace std;


//Recursive BruteForce Solution O(2^n)
int minStepFn(int n){
    if(n<=1){
        return 0;
    }
    
    int y = INT_MAX;
    int z = INT_MAX;
    int x = minStepFn(n-1);
    
    if(n>=3 && n%3==0){
        y = minStepFn(n/3);
    }
    if(n>=2 && n%2==0){
        z = minStepFn(n/2);
    }
    
    if(x<=y && x<=z){
        return x+1;
    }else if(y<=x && y<= z){
        return y+1;
    }else{
        return z+1;
    }
}

// Memoization O(n)
int minStepFn2(int n, int* ans){
    //Base Case
    if(n<=1){
        return 0;
    }
    
    // Check if ans exist
    if(ans[n] != -1){
        return ans[n];
    }
    
    //Small Calculation
    int x = minStepFn2(n-1,ans);
    int y=INT_MAX, z= INT_MAX;
    if(n%2==0){
        y = minStepFn2(n/2,ans);
    }
    if(n%3==0){
        z = minStepFn2(n/3,ans);
    }
    int output;
    if(x<=y && x<=z){
        output =  x+1;
    }else if(y<=x && y<= z){
        output = y+1;
    }else{
        output = z+1;
    }
    ans[n] = output;
    return output;
}
    

int minStepFn2(int n){
    int* ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }
    int output = minStepFn2(n,ans);
    delete [] ans;
    return output;
}


//Dynamic Programming
int minStepFn3(int n){
    if(n<=1){
        return 0;
    }
    
    int* ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 0;
    
    for(int i=2;i<=n;i++){
        int x = ans[i-1]+1;
        //cout<<"x: "<<x<<" ";
        
        int y= INT_MAX;
        if(i%2==0){
            y= 1+ans[i/2];
            //cout<<"y: "<<y<<" ";
        }
        
        int z = INT_MAX;
        if(i%3 ==0){
            z = 1+ans[i/3];
            //cout<<"z "<<z;
        }
        //cout<<endl;
        
        if(x<=y && x<=z){
            ans[i] =  x;
        }else if(y<=x && y<= z){
            ans[i] = y;
        }else{
            ans[i] = z;
        }
        
    }
    int output = ans[n];
    delete [] ans;
    return output;
}
    

int main() {
    int n;
    cout<<"Enter the number of whom we want to calculate the min steps\n";
    cin>>n;
    int minStep = minStepFn3(n);
    cout<<minStep<<endl;
    return 0;
}
