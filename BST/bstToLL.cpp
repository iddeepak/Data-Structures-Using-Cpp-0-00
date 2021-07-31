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

template<typename T>
class Node{
	public:
		int data;
		Node<int>* next;
		
		Node(T data){
			this->data = data;
			this->next = NULL;
		}	
};
class SortedLL{
	public:
		Node<int>* head;
		Node<int>* tail;
};

SortedLL helper(BinaryTreeNode<int>* root){
  
  if(root == NULL){
    SortedLL output;
    output.head = NULL;
    output.tail = NULL;
    return output;
  }
  
  SortedLL leftLL = helper( root->left );
  Node<int>* newnode = new Node<int>(root->data);
  SortedLL output;
  
  if(leftLL.head == NULL){
    output.head = newnode ;
    output.tail = newnode ;
  }
  else {
    output.head = leftLL.head;
    leftLL.tail -> next = newnode;
    leftLL.tail = leftLL.tail->next;
    output.tail = leftLL.tail;  
  }
  SortedLL rightLL = helper(root->right);
  if(rightLL.head == NULL){
    return output;
  }
  output.tail -> next = rightLL.head;
  output.tail = rightLL.tail;
  return output;
}

Node<int>* constructBST(BinaryTreeNode<int>* root) {
  SortedLL ans = helper(root);
  return ans.head;
}

int main(){
	 BinaryTreeNode<int>* root = takeInputLevelWise();
    Node<int>* head = constructBST(root);
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
	cout<<endl;
	delete root;
	return 0;
}

