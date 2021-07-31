#include<iostream>
#include<climits>
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



// in Some cases it will not going to work because this only check with adjcent childrens but we wanr leftMax & rightMin to verify if it's BST or not... :)
// bool isBST(BinaryTreeNode<int>* root){
// 	if(root==NULL){
// 		return true;
// 	}
//     bool y,z;
//     if(root->left ==NULL){
//         y= true;
//     }else if(root->left->data <= root->data){
// 		y = isBST(root->left);
// 	}else{
// 		y= false;
// 	}
//     if(root->right==NULL){
//         z = true;
//     }else if(root->right->data >= root->data){
// 		z = isBST(root->right);
// 	}else{
// 		z = false;
// 	}
//     return (y && z);
// }

// This is the right way to check whether the given tree is BST or not but it is not time efficient
int maximum(BinaryTreeNode<int>* root){
	if(root==NULL){
		return INT_MIN;
	}
	return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root){
	if(root==NULL){
		return INT_MAX;
	}
	return min(root->data, min(minimum(root->left) , minimum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root){
	if(root ==NULL){
		return true;
	}
	int leftMax = maximum(root->left);
	int rightMin = minimum(root->right);
	bool output = (isBST(root->left) && isBST(root->right)  && (root->data > leftMax) && (root->data <= rightMin));
	return output; 
}


// Approach 2 O(n)
class IsBSTReturn{
	public:
		bool isBST;
		int minimum;
		int maximum;
};

IsBSTReturn isBST2(BinaryTreeNode<int>* root){
	if(root==NULL){
		IsBSTReturn output;
		output.isBST = true;
		output.minimum = INT_MAX;
		output.maximum = INT_MIN;
		return output;
	}
	
	IsBSTReturn leftBST  = isBST2(root->left);
	IsBSTReturn rightBST = isBST2(root->right);
	
	IsBSTReturn output;
	output.minimum = min(root->data , min(leftBST.minimum,rightBST.minimum));
	output.maximum = max(root->data, max(rightBST.maximum, rightBST.maximum));
	output.isBST = (root->data  >leftBST.maximum) &&(root->data <= rightBST.minimum) && leftBST.isBST && rightBST.isBST;
	return output;
}


// Approach 3 Mine Fav O(n)
bool isBST3(BinaryTreeNode<int>* root, int max = INT_MAX,  int min = INT_MIN){
	if(root==NULL){
		return true;
	}
	if(root->data < min || root->data > max){
		return false;
	}
	bool isLeftOK = isBST3(root->left, root->data-1, min);
	bool isRightOK = isBST3(root->right, max, root->data);
	return (isLeftOK && isRightOK);
}

int main(){
     BinaryTreeNode<int>* root = takeInputLevelWise();	
	if(isBST(root)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    if(isBST2(root).isBST) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    if(isBST3(root)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
		
	cout<<endl;
	delete root;
	return 0;
}
