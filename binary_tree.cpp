#include <iostream>
#include <list> 

using namespace std;


struct Node 
{ 
    int data; 
    struct Node* left, *right; 
    Node(int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    }
};


 /* Given a binary tree, print its nodes according to the 
"bottom-up" postorder traversal. */
void printPostorder(struct Node* node) 
{ 
    if (node == NULL) {
        return; 
    }
        
    // first recur on left subtree 
    printPostorder(node->left); 
  
    // then recur on right subtree 
    printPostorder(node->right); 
  
    // now deal with the node 
    cout << node->data << " "; 
} 


/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    cout << node->data << " "; 
  
    /* now recur on right child */
    printInorder(node->right); 
} 
  
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first print data of node */
    cout << node->data << " "; 
  
    /* then recur on left sutree */
    printPreorder(node->left);  
  
    /* now recur on right subtree */
    printPreorder(node->right); 
}  


struct Node* search(struct Node* root, int key) 
{ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->data == key) {
       return root;  
    }
       
     
    // Key is greater than root's key 
    if (root->data < key) {
       return search(root->right, key);  
    }
    
    // Key is smaller than root's key 
    return search(root->left, key); 
} 

struct Node *newNode(int item) 
{ 
    return new struct Node(item);
}

/* A utility function to insert a new node with given key in BST */
struct Node* insert(struct Node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 

    /* Otherwise, recur down the tree */
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key);    

    /* return the (unchanged) node pointer */
    return node; 
} 


int main() 
{
    struct Node *pTree = NULL;
    pTree = insert(pTree,80);
    pTree = insert(pTree,20);
    pTree = insert(pTree,60);
    pTree = insert(pTree,40);
    pTree = insert(pTree,30);
    pTree = insert(pTree,50);
    printInorder(pTree);
    return 0; 
} 