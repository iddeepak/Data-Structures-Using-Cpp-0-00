#include<iostream>
#include<queue>
#include<climits>
#include<vector>
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


vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data){
	if(root==NULL){
		return NULL;
	}
	if(root->data == data){
		vector<int>* output = new vector<int>();
		output->push_back(root->data);
		return output;
	}
	
	vector<int>* leftOutput = getRootToNodePath(root->left, data);
	if(leftOutput != NULL){
		leftOutput->push_back(root->data);
		return leftOutput;
	}
	
	vector<int>* rightOutput = getRootToNodePath(root->right,data);
	if(rightOutput != NULL){
		rightOutput->push_back(root->data);
		return rightOutput;
	}else{
		return NULL;
	}
}

int main(){
	 BinaryTreeNode<int>* root = takeInputLevelWise();
    int n;
    cout<<"Enter node you want to search in Tree\n";
    cin>>n;
    vector<int>* output = getRootToNodePath(root,n);
    for(int i=(output->size()-1);i>=0;i--){
		cout<<output->at(i)<<" ";
	}
	cout<<endl;
	delete output;
	delete root;
	return 0;
}

