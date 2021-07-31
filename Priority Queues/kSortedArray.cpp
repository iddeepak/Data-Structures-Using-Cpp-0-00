#include <iostream>
#include<queue>
using namespace std;

void kSortedArray(int input[], int n, int k){
	priority_queue<int> pq;
	for(int i=0;i<k;i++){
		pq.push(input[i]);
	}
	int j =0 ;
	for(int i=k;i<n;i++){
		input[j] = pq.top();
		pq.pop();
		pq.push(input[i]);
		j++;
	}
	while(!pq.empty()){
		input[j] = pq.top();
		pq.pop();
		j++;
	}
}

int main() {
	int n,k;
	cout<<"Enter the size of an Array & k factor\n";
	cin>>n>>k;
	int* a = new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<endl;
	kSortedArray(a,n,k);
	cout<<"sorted Array\n";
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}
	cout<<endl;
	delete [] a;
	return 0;
}
