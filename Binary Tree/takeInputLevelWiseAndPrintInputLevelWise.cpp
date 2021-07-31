#include<iostream>
#include<queue>
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

void printBinaryTreeLevelWise(BInaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	queue<BInaryTreeNode<int>*> pendingPrinting;
	pendingPrinting.push(root);
	while(pendingPrinting.size()){
		BInaryTreeNode<int>* front = pendingPrinting.front();
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

BInaryTreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout<<"Enter Data\n";
	cin>>rootData;
	if(rootData == -1){
		return NULL;
	}
	BInaryTreeNode<int>* root = new BInaryTreeNode<int>(rootData);
	queue<BInaryTreeNode<int>* > pendingNodes ;
	pendingNodes.push(root);
	while(pendingNodes.size()){
		BInaryTreeNode<int>*  front  = pendingNodes.front();
		pendingNodes.pop();
		int leftData;
		cout<<"Enter the left child of "<<front->data<<":"<<endl;
		cin>>leftData;
		if(leftData != -1){
			BInaryTreeNode<int>*  leftNode = new BInaryTreeNode<int>(leftData);
			front->left = leftNode;
			pendingNodes.push(leftNode);
		}
		int rightData;
		cout<<"Enter the right child of "<<front->data<<":"<<endl;
		cin>>rightData;
		if(rightData != -1){
			BInaryTreeNode<int>*  rightNode = new BInaryTreeNode<int>(rightData);
			front->right = rightNode;
			pendingNodes.push(rightNode);
		}
	}
	return root;
}

int main(){
	BInaryTreeNode<int>* root = takeInputLevelWise();
	printBinaryTreeLevelWise(root);
	delete root;
	return 0;
}
