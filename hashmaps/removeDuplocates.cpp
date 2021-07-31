// Remove Duplicates and print the number according to first occurence

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> removeDuplicates(int* a, int n){
	vector<int> output;
	unordered_map<int, bool>  seen;
	for(int i=0; i<n; i++){
		if(seen.count(a[i]) >0) {
			continue;
		}
		output.push_back(a[i]);
		seen[a[i]] = true;
	}
	return output;
}

int main(){
	int n;
	cout<<"Enter the size of Array\n";
	cin>>n;
	int* a = new int[n];
	for(int i=0;i<n;i++){
			cin>>a[i];
	}
	vector<int> output = removeDuplicates(a, n);
	for(int i=0;i< output.size();i++){
			cout<<output.at(i)<<" ";
	}
	cout<<endl;
	delete [] a;
	return 0;
}
