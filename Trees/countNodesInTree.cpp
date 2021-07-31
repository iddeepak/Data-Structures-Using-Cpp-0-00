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


int numNodes(TreeNode<int>* root){
	if(root==NULL){
		return 0;
	}
	int ans =1;
	for(int i=0;i<(root->children.size());i++){
		ans+=numNodes(root->children[i]);
	}
	return ans;
}

void deleteTree(TreeNode<int>* root){
	for(int i=0; i<(root->children.size()); i++){
		deleteTree(root->children[i]);
	}
	delete root;
}

int main() {
	TreeNode<int>* root = takeInputLevelWise();
	
	cout<<"The Nodes in tree are: "<<numNodes(root)<<endl;
	// delete the dynamically allocated memory
	deleteTree(root);
	return 0;
}
