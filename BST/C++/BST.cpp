// Sample Input/Output:
/*
Inorder traversal of BST :
1       3       4       5       7       8       9       11      12
Min Element : 1
Max Element : 12
*/

// Including header files.
#include<iostream>
using namespace std;

// BST class defination.
class BST{
    // Private data members.
    int data;
    BST* left;
    BST* right;
    public:
        // Constructor declaration.
        BST(int data);
        // Declaration of member function of BST class.
        void insert(int data);
        void inorder();
        int getMin();
        int getMax();
};

// Defination of Constructor of BST class.
BST::BST(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

// insert() fucntion that will insert the data,
// at right place in a BST.
void BST::insert(int data){
    BST *root = this;
    BST *node = new BST(data);
    if(root == nullptr)
        return;
    BST *temp;
    while(root != nullptr){
        temp = root;
        if(root->data < data)
            root = root->right;
        else
            root = root->left;
    }
    if(temp->data < data)
        temp->right = node;
    else
        temp->left = node;
}

// inorder() function to print the tree,
// using Inorder traversal.
void BST::inorder(){
    if(this != nullptr){
        this->left->inorder();
        cout<< this->data<< "\t";
        this->right->inorder();
    }
}

// getMin() function to get the,
// minimum element from the BST.
int BST::getMin(){
    BST *temp = this;
	if(this == nullptr)
		return -1;
	while(temp->left != NULL)
		temp = temp->left;
    return temp->data;
}

// getMax() function to get the,
// maximum element from the BST.
int BST::getMax(){
    BST *temp = this;
	if(this == nullptr)
		return -1;
	while(temp->right != NULL)
		temp = temp->right;
    return temp->data;
}

// main function or the driver function.
int main(){
    // Instantiating BST class,
	// and inserting data in it.
    BST *root = new BST(7);
    root->insert(8);
	root->insert(1);
	root->insert(5);
	root->insert(3);
	root->insert(9);
	root->insert(11);
	root->insert(12);
	root->insert(4);

    // Printing Inorder traversal of BST.
	printf("\nInorder traversal of BST :\n");
	root->inorder();

    // Printing minimum element fron BST.
	cout<< "\nMin Element : "<< root->getMin()<< endl;
	
	// Printing maximum element fron BST.
	cout<< "\nMax Element : "<< root->getMax()<< endl;

    return 0;
}