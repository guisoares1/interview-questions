#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};
    
*/
    int heightTree =-1;
    
    void numsNodes(Node* root, int count){
       count++;
       if(count>heightTree)
            heightTree = count;
            
       if(root->left!=NULL)
          numsNodes(root->left, count);
        
       if(root->right!=NULL) 
          numsNodes(root->right, count);

    }
    
    int height(Node* root) {
        // Write your code here.
        numsNodes(root, -1);
        return heightTree;
    }

};