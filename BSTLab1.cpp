#include <iostream>

using namespace std;

// Implement the node class we will need for our Binary Search Tree
class Node {
	public:
		// the Node should contain
		// 	- an integer "key" that holds the value of the Node
		// 	- a pointer to each child possible child node ("right" and "left")
		int key;
		Node* right;
		Node* left;



		// Write a constructor for the Node
		// input: only an integer value for "key", no pointer arguments
		// 		right and left pointers should be null

		Node(int k){
			key = k;
			right = nullptr;
			left = nullptr;
		}
};


// Use this function to create a Binary Search Tree (BST) tree with the following values
// {13, 0, 7, 6, 21, 15, -2, 12, 99, 18, 19, -1}
Node* createTree() {
	// root
	Node *root = nullptr;

	// level 1 (children of root)
	root = new Node(13);
	root -> left = new Node(0);
	root -> right = new Node(21);
	
	// level 2 (children of 0)
	root -> left -> right = new Node(7);
	root -> left -> left = new Node(-2);
	

	// level 2 (children of 21)
	root -> right -> right = new Node(99);
	root -> right -> left = new Node(15);
	// level 3 (children of -2)
	root -> left -> left -> right = new Node(-1);
	
	// level 3 (children of 7)
	root -> left -> right -> right = new Node(12);
	root -> left -> right -> left = new Node(6);
	// level 3 (children of 15)
	root -> right -> left -> right = new Node(18);
	
	// level 3 (children of 99)

	// level 4 (children of 18)
	root -> right -> left -> right -> right = new Node(19);
	return root;
}

// Write a function that will search the BST for a target value
//	input: integer target to search for,
			// pointer to root Node
// 	returns: true or false depending on if the value is found
// You should write this function recursively! What is the base case? What is the general case?
bool searchTree(int target, Node* root) {
	// Base cases
	if(root -> key == target) return true;

	else if(root -> left == nullptr && root -> right == nullptr) return false;

	// General case
	if(root -> key < target){
		return searchTree(target, root -> right);
	}
	else if(root -> key > target){
		return searchTree(target, root -> left);
	}
	
}

// Write a function that will return the total number of Nodes in the tree
// 	input: pointer to the root Node
// 	returns: number of nodes currently in the tree
// You should write this function recursively!
int treeSize(Node* root) {
	// base case
	if(root == nullptr) return 0;

	// General case
	int counter = 0;
	if(root -> left){
		counter += treeSize(root -> left);
	} 
	if(root -> right){
		counter += treeSize(root -> right);
	}
	return counter + 1;

}

// BONUS! Write a function that will determine the height of the tree
int treeHeight(Node* root) {
	// base case
	if(root == nullptr) return -1;

	// General case
	
	int left = treeHeight(root -> left);
	int right = treeHeight(root -> right);
	
	return max(left, right) + 1;
}
