#include<iostream>
#include<queue>
#include<climits>
using namespace std;

template<typename T>
class BinaryTreeNode{
	public:
		T data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;
		
		BinaryTreeNode(T data){
			this->data = data;
			left= NULL;
			right = NULL;
		}
		
		~BinaryTreeNode(){
			delete left;
			delete right;
		}
};

BinaryTreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout<<"Enter Data\n";
	cin>>rootData;
	if(rootData == -1){
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>* > pendingNodes ;
	pendingNodes.push(root);
	while(pendingNodes.size()){
		BinaryTreeNode<int>*  front  = pendingNodes.front();
		pendingNodes.pop();
		int leftData;
		cout<<"Enter the left child of "<<front->data<<":"<<endl;
		cin>>leftData;
		if(leftData != -1){
			BinaryTreeNode<int>*  leftNode = new BinaryTreeNode<int>(leftData);
			front->left = leftNode;
			pendingNodes.push(leftNode);
		}
		int rightData;
		cout<<"Enter the right child of "<<front->data<<":"<<endl;
		cin>>rightData;
		if(rightData != -1){
			BinaryTreeNode<int>*  rightNode = new BinaryTreeNode<int>(rightData);
			front->right = rightNode;
			pendingNodes.push(rightNode);
		}
	}
	return root;
}


void printBinaryTreeLevelWise(BinaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	queue<BinaryTreeNode<int>*> pendingPrinting;
	pendingPrinting.push(root);
	while(pendingPrinting.size()){
		BinaryTreeNode<int>* front = pendingPrinting.front();
		pendingPrinting.pop();
		cout<<front->data<<":";
		if(front->left !=NULL){
			cout<<"L:"<<front->left->data<<",";
			pendingPrinting.push(front->left);
		}else{
			cout<<"L:-1,";
		}
		if(front->right !=NULL){
			cout<<"R:"<<front->right->data;
			pendingPrinting.push(front->right);
		}else{
			cout<<"R:-1";
		}
		cout<<endl;
	}
}


BinaryTreeNode<int>* makingBST(int* a ,int si, int ei){
	if(si>ei){
		return NULL;
	}
	int mid = (si+ei)/2;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(a[mid]) ;
	//root->data = a[mid];
	root->left = makingBST(a,si,mid-1);
	root->right = makingBST(a,mid+1,ei);
	return root;
}

BinaryTreeNode<int>*  makeBST(int* a, int n){
	return makingBST(a, 0,n-1);
}


int main(){
	int n;
	cout<<"Enter the Size of Sorted Array\n";
	cin>>n;
	int* a = new int[n];
	cout<<"Enter the Sorted Order Elements\n";
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	BinaryTreeNode<int>* root = makeBST(a,n);	
	cout<<"Here is the tree\n";
	printBinaryTreeLevelWise(root);
		
	cout<<endl;
	delete root;
    delete []a;
	return 0;
}
