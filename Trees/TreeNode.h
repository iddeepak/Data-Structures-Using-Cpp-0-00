#include<vector>
using namespace std;

template<typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data){
            this->data = data;
        }

        ~TreeNode(){
            for(int i=0; i<(root->children.size()); i++){
		        delete children[i];
	        }
        }
};


// we can simply use( delete root;) after making destructor