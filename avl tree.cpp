#include <iostream>
#include <string>
using namespace std;

// A structure to represent a node of the height-balanced tree
struct Node
{
    string keyword;
    string meaning;
    int height;
    Node* left;
    Node* right;
};

// Function to create a new node with given keyword and meaning
Node* newNode(string keyword, string meaning)
{
    Node* node = new Node();
    node->keyword = keyword;
    node->meaning = meaning;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Function to calculate the height of a node
int height(Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

// Function to get the balance factor of a node
int balanceFactor(Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Function to rotate a subtree to the left
Node* rotateLeft(Node* node)
{
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
}

// Function to rotate a subtree to the right
Node* rotateRight(Node* node)
{
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
}

// Function to balance a node
Node* balance(Node* node)
{
    if (node == NULL)
    {
        return NULL;
    }
    int bf = balanceFactor(node);
    if (bf > 1)
    {
        if (balanceFactor(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }
    else if (bf < -1)
    {
        if (balanceFactor(node->right) > 0)
        {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }
    return node;
}

// Function to insert a new keyword and meaning into the dictionary
Node* insert(Node* root, string keyword, string meaning)
{
    if (root == NULL)
    {
        return newNode(keyword, meaning);
    }
    if (keyword < root->keyword)
    {
        root->left = insert(root->left, keyword, meaning);
    }
    else if (keyword > root->keyword)
    {
        root->right = insert(root->right, keyword, meaning);
    }
    else
    {
        root->meaning = meaning;
        return root;
    }
    root->height = max(height(root->left), height(root->right)) + 1;
    return balance(root);
}

// Function to delete a keyword from the dictionary
Node* deleteNode(Node* root, string keyword)
{
    if (root == NULL)
    {
        return root;
    }
    if (keyword < root->keyword)
    {
        root->left = deleteNode(root->left, keyword);
    }
    else if (keyword > root->keyword)
    {
        root->right = deleteNode(root->right, keyword);
    }
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            delete temp;
        }
        else
        {
            Node* temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;
            root->right = deleteNode(root->right, temp->keyword);
        }
    }
    if (root == NULL)
    {
        return root;
    }
    root->height = max(height(root->left), height(root->right)) + 1;
    return balance(root);
}

// Function to search for the meaning of a keyword in the dictionary
string search(Node* root, string keyword)
{
    if (root == NULL || root->keyword == keyword)
    {
        if (root != NULL)
        {
            return root->meaning;
        }
        return "Keyword not found!";
    }
    if (keyword < root->keyword)
    {
        return search(root->left, keyword);
    }
    return search(root->right, keyword);
}

// Function to display the dictionary in inorder traversal
void display(Node* root)
{
    if (root != NULL)
    {
        display(root->left);
        cout << root->keyword << " - " << root->meaning << endl;
        display(root->right);
    }
}

int main()
{
    Node* root = NULL;
    root = insert(root, "apple", "A fruit");
    root = insert(root, "banana", "A curved fruit");
    root = insert(root, "cat", "A small domesticated carnivorous mammal");
    root = insert(root, "dog", "A domesticated carnivorous mammal");
    
    cout << "Dictionary contents:\n";
    display(root);
    
    cout << "\nMeaning of 'banana': " << search(root, "banana") << endl;
    
    root = deleteNode(root, "banana");
    
    cout << "\nDictionary contents after deleting 'banana':\n";
    display(root);
    
    cout << "\nMeaning of 'banana' after deletion: " << search(root, "banana") << endl;
    
    return 0;
}

