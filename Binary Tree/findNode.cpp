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

bool isNodePresent(BInaryTreeNode<int>* root, int x) {
  
  if(root==NULL){
		return false;
	}
	if(root->data == x) {
		return true;
	}
	bool left = isNodePresent(root->left, x);
	bool right = isNodePresent(root->right,x);
	if( left || right){
		return true;
	}else{
		return false;
	}
}


int main(){
	cout<<"enter the node you want to find in tree:";
	int x;
	cin>>x;
	BInaryTreeNode<int>* root = takeInputLevelWise();
	cout<<endl;
	if(isNodePresent(root, x)) {
        cout << "true";
    }
    else {
        cout << "false";
    }
    cout<<endl;
	delete root;
	return 0;
}