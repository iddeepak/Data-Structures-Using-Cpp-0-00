#include <iostream>
#include<vector>
#include<queue>
using namespace std;


template<typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data){
            this->data = data;
        }
};



TreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout<<"Enter root Data: "<<endl;
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	queue<TreeNode<int>*> pendingNodes;
	
	pendingNodes.push(root);
	while(pendingNodes.size() != 0){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout<<"Enter num of children of: "<<(front->data)<<endl;
		int numChild;
		cin>>numChild;
		for(int i=0; i<numChild; i++){
			int childData;
			cout<<"Enter " <<i<<"i-th child of "<<(front->data)<<endl;
			cin>>childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}



void printAtLevelK(TreeNode<int>* root, int k){
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<<root->data<<endl;
		return;
	}
	for(int i=0; i<root->children.size() ; i++){
		printAtLevelK(root->children[i],k-1);
	}
}

void deleteTree(TreeNode<int>* root){
	for(int i=0; i<(root->children.size()); i++){
		deleteTree(root->children[i]);
	}
	delete root;
}


int main() {
	TreeNode<int>* root = takeInputLevelWise();	
	cout<<"Enter the level/depth you want to print: ";
	int k;
	cin>>k;
	printAtLevelK(root,k);
	// delete the dynamically allocated memory
	deleteTree(root);
	return 0;
}


