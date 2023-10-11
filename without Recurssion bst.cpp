#include<iostream> 
#include<stdlib.h> 
using namespace std; 
struct BST { 
 struct BST *left; 
 int data; 
 struct BST *right; 
}; 
struct BST* root = NULL; 
struct BST* createNode(int data) { 
 struct BST* newNode = (struct BST*)malloc(sizeof(struct BST)); 
 newNode->data = data; 
 newNode->left = newNode->right = NULL; 
 return newNode; 
} 
struct BST* insert(struct BST* root, int data) { 
 if (root == NULL) { 
 root = createNode(data); 
 return root; 
 } 
 if (data <= root->data) { 
 root->left = insert(root->left, data); 
 } else { 
 root->right = insert(root->right, data); 
 } 
 return root; 
} 
void inOrder(struct BST* node) { 
 if (node == NULL) { 
 return; 
 } 
 inOrder(node->left); 
 cout << node->data << " "; 
 inOrder(node->right); 
} 
void preOrder(struct BST* node) { 
 if (node == NULL) { 
 return; 
 } 
 cout << node->data << " "; 
 preOrder(node->left); 
 preOrder(node->right); 
} 
int Height1(struct BST *root) 
{ 
 if(root==NULL) 
 { 
 return 0; 
 } 
 else 
 { 
 if(Height1(root->right)>Height1(root->left)) 
 { 
 return(1+Height1(root->right)); 
 } 
 else 
 { 
 return(1+Height1(root->left)); 
 } 
 } 
} 
int findMin(struct BST* root) { 
 if (root == NULL) { 
 cout << "Tree is empty." << endl; 
 return -1; 
 } 
 struct BST* current = root; 
 while (current->left != NULL) { 
 current = current->left; 
 } 
 return current->data; 
} 
struct BST* mirrorImage(struct BST* root) { 
 if (root == NULL) { 
 return NULL; 
 } 
 struct BST* temp = root->left; 
 root->left = mirrorImage(root->right); 
 root->right = mirrorImage(temp); 
 return root; 
} 
void search(struct BST* root, int key) { 
 if (root == NULL) { 
 cout << "Key not found." << endl; 
 return; 
 } 
 if (root->data == key) { 
 cout << "Key Found." << endl; 
 } else if (key < root->data) { 
 search(root->left, key); 
 } else { 
 search(root->right, key); 
 } 
} 
int main() { 
 int ch, key, data; 
 while (1) { 
 cout << "\n***********************" << endl; 
 cout << "Operations on BST" << endl; 
 cout << "1. Insert Element." << endl; 
 cout << "2. No.of nodes in longest path of the tree." << endl; 
 cout << "3. Smallest value in the tree." << endl; 
 cout << "4. Display." << endl; 
 cout << "5. Mirror image of the tree." << endl; 
 cout << "6. Search an element." << endl; 
 cout << "7. Exit." << endl; 
 cout << "Enter your choice : " << endl; 
 cin >> ch; 
 switch (ch) { 
 case 1: 
 cout << "Enter data: "; 
 cin >> data; 
 root = insert(root, data); 
 break; 
 case 2: 
 cout << "No.of nodes in longest path of the tree: " << Height1(root); 
 break; 
 case 3: 
 cout << "The smallest number in the tree is: " << findMin(root) << 
endl; 
 break; 
 case 4: 
 cout << "Inorder traversal of the constructed tree is: " << endl; 
 inOrder(root); 
 cout << "\nPreorder traversal of the constructed tree is: " << endl; 
 preOrder(root); 
 break; 
 case 5: 
 cout << "Inorder traversal of the constructed tree is: " << endl; 
 inOrder(root); 
 root = mirrorImage(root); 
 cout << "\nInorder traversal of the mirror image tree is: " << endl; 
 inOrder(root); 
 break; 
 case 6: 
 cout << "Enter the number to search: "; 
 cin >> key; 
 search(root, key); 
 break; 
 case 7: 
 exit(0); 
 } 
 } 
 return 0; 
} 
