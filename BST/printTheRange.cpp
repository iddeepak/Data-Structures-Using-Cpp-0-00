#include<iostream>
#include<queue>
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


void printRangeBST(BinaryTreeNode<int>* root , int l, int h){
		if(root==NULL){
			return;
		}
		if(root->data >h){
			printRangeBST(root->left,l,h);
		}else if(root->data < l){
			printRangeBST(root->right,l,h);
		}else if(root->data >=l && root->data <=h){
			cout<<root->data<<" ";
			printRangeBST(root->left,l,h);
			printRangeBST(root->right,l,h);
		}
		return;
}


int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
	int l,h;
	cout<<"Enter the low & high in between you want to print the tree Nodes\n";
	cin>>l>>h;
	printRangeBST(root,l,h);
	cout<<endl;
	delete root;
	return 0;
}
