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


BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int s){
   if(root ==NULL){
		return NULL;
	}
	if(root->data ==s){
		return root;
	}else if(root->data >s){
		return searchInBST(root->left ,s);
	}else{
		return searchInBST(root->right, s);
	}
}


int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
	int n;
	cout<<"Enter the node you want to search in BST:-  ";
	cin>>n;
    cout<<(searchInBST(root,n)->data)<<endl;

	delete root;
	return 0;
}

// We are expecting the input to be in BST mode