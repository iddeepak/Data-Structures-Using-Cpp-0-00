#include <iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> kSmallest(int *input, int n, int k) {
	// Write your code here
	priority_queue<int> pq;
	for(int i=0;i<k;i++){
		pq.push(input[i]);
	}
	for(int i=k;i<n;i++){
		pq.push(input[i]);
		pq.pop();
	}
    vector<int> v;
    // for(int i=0;i<pq.size();i++){
    while(!pq.empty()){
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
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
	vector<int> output = kSmallest(a, n, k);
	for(int i = 0; i < output.size(); i++){
		cout << output[i] << endl;
	}
	cout<<endl;
	delete [] a;
	return 0;
}
