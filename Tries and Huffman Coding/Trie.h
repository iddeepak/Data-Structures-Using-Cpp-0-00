#include<string>
#include"TrieNode.h"

class Trie{
    TrieNode* root;
    
    public:
        Trie(){
            root = new TrieNode('\0');
        }

        private:    
            void insertWord(TrieNode* root, string word){
                //Base Case
                if(word.size() ==0){
                    root->isTerminal = true;
                    return;
                }
                
                //Small Calculation
                int index = word[0]-'a';
                TrieNode *child;
                if(root->children[index] != NULL){
                    child = root->children[index];
                }
                else{
                    child = new TrieNode(word[0]);
                    root->children[index] = child;
                }
                
                //Recursive Call
                insertWord(child,word.substr(1));
            }

        public:            
            void insertWord(string word){
                insertWord(root,word);
            }
            
        private:
            bool search(TrieNode* root, string word){
                if(word.size()==0){
                    if(root->isTerminal == true){
                        return true;
                    }
                    return false;
                }
                
                //Small Calucaltion
                int index = word[0]-'a';
                if(root->children[index] !=NULL){
                    return search(root->children[index],word.substr(1));
                }
                else{
                    return false;
                }
            }
        
        public:
            bool search(string word){
                return search(root,word);
            }


        private:
            void removeWord(TrieNode* root, string word){
                if(word.size()==0){
                    root->isTerminal = false;
                    return;
                }
                
                
                TrieNode * child;
                int index = word[0]-'a';
                if(root->children[index] != NULL){
                    child = root->children[index];
                }else{
                    return ;
                }
                
                removeWord(child, word.substr(1));
                
                //Remove Child Node if it is useless
                if(child->isTerminal ==false){
                    for(int i =0 ;i<26;i++){
                        if(child->children[i] !=NULL){
                            return;
                        }
                    }
                    delete child;
                    root->children[index] =NULL;
                }
            }
            
        public:
            void removeWord(string word){
                return removeWord(root, word);
            }
};
