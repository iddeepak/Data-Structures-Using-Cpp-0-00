#include<bits/stdc++.h>
#include<vector>
#include<unordered_map>
using namespace std;

void intersection(int* a, int* b, int m , int n) {
	sort(a,a+m);
	sort(b,b+n);
	
	int i=0;
	int j=0;
	
	while(i<m && j<n){
		if(a[i] == b[j]){
			cout<<a[i]<<endl;
			i++;
			j++;
		}else if(a[i] < b[j]){
			i++;
		}else{
			j++;
		}
	}
}

int main(){
	int m;
	cout<<"Enter the length of First Array\n";
    cin>>m;
    int* a = new int[m];
    cout<<"Enter the elements of First Array\n";
    for(int i=0; i<m; i++)
    {
        cin>>a[i];
    }
    int n;
	cout<<"Enter the length of Second Array\n";
    cin>>n;
    int* b= new int[n];
    cout<<"Enter the elements of Second Array\n";
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
    }
    intersection(a,b,m,n);
    delete []b;
    delete []a;
    return 0;
}
