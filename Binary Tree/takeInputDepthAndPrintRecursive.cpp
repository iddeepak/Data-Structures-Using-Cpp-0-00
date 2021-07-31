#include<iostream>
using namespace std;

template<typename T>
class BInaryTreeNode{
	public:
		T data;
		BInaryTreeNode* left;
		BInaryTreeNode* right;
		
		BInaryTreeNode(T data){
			this->data = data;
			left= NULL;
			right = NULL;
		}
		
		~BInaryTreeNode(){
			delete left;
			delete right;
		}
};

void printBinaryTree(BInaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<":";
	if(root->left != NULL){
		cout<<" "<<"L"<<root->left->data;
	}
	if(root->right != NULL){
		cout<<" "<<"R"<<root->right->data;
	}
	cout<<endl;
	printBinaryTree(root->left);
	printBinaryTree(root->right);
}

BInaryTreeNode<int>* takeInput(){
	int rootData;
	cout<<"Enter the data"<<endl;
	cin>>rootData;
	if(rootData == -1){
		return NULL;
	}
	BInaryTreeNode<int>* root = new BInaryTreeNode<int>(rootData);
	BInaryTreeNode<int>* leftChild = takeInput();
	BInaryTreeNode<int>* rightChild = takeInput();
	root->left = leftChild;
	root->right = rightChild;
	return root;
}

int main(){
	BInaryTreeNode<int>* root = takeInput();
	printBinaryTree(root);
    delete root;
	return 0;
}
