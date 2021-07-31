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

BInaryTreeNode<int>* helper(int* preor, int preS, int preE, int* inor, int inS, int inE){
	if(preE<preS || inE<inS){
		return NULL;
	}
	BInaryTreeNode<int>* root = new BInaryTreeNode<int>(preor[preS]);
	int inR;
	for(int i=inS; i <= inE; i++){
		if(preor[preS] ==inor[i]){
			inR = i;
			break;
		}
	}
	BInaryTreeNode<int>* left = helper(preor, preS+1, (preS+inR-inS), inor, inS, inR-1);
	BInaryTreeNode<int>* right = helper(preor,(preS+inR-inS+1),preE,inor,inR+1,inE);
	root->left = left;
	root->right = right;
	return root;
}

BInaryTreeNode<int>* buildTree(int *preorder, int preLenght, int *inorder, int inLength) {
	if(preLenght ==inLength){
		BInaryTreeNode<int>* root = helper(preorder,0,(preLenght-1),inorder,0,(inLength-1));        
		return root;
	}
	else{
		return NULL;
	}
}


int main(){
	int n;
	cout<<"Enter the length of Tree for inOrder & PreOrder"<<endl;
	int * in = new int[n];
	int * pre = new int[n];
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	for(int i=0;i<n;i++){
		cin>>pre[i];
	}
	BInaryTreeNode<int>* root = buildTree(pre,n,in,n);
	//printLevelWise(root);
	
	delete []in;
	delete []pre;
	delete root;
	return 0;
}
