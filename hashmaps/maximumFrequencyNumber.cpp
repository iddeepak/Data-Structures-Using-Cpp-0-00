#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int highestFrequency( int* a,  int n){
	unordered_map<int, int> occur;
	int key = a[0], value = 0;
	for(int i=0;i<n;i++){
		if(occur.count(a[i])>0){
			occur[a[i]]++;
		}else{
			occur[a[i]] = 1;
		}
		if(occur[a[i]] > value){
			value = occur[a[i]];
			key = a[i];
		}
	}
	return key;
}

int main(){
	int n;
	cout<<"Enter the length of Array\n";
    cin>>n;
    int* a = new int[n];
    cout<<"Enter the elements of Array\n";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int maxKey= highestFrequency(a, n);
    cout<<maxKey;
    delete []a;
    return 0;
}
