#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *left;
    Node *right;

	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

// Function to print all nodes of a given level from left to right
bool printLevel(Node* root, int level)
{
	if (root == NULL)
		return false;

	if (level == 1)
	{
		cout << root->data << " ";

		// return true if at-least one node is present at given level
		return true;
	}

	bool left = printLevel(root->left, level - 1);
	bool right = printLevel(root->right, level - 1);

	return left || right;
}

// Function to print level order traversal of given binary tree
void levelOrderTraversal(Node* root)
{
	// start from level 1 -- till height of the tree
	int level = 1;

	// run till printLevel() returns false
	while (printLevel(root, level))
		level++;
}

int main()
{
	Node* root = NULL;

	root = new Node(2);

	root->left = new Node(7);
	root->right = new Node(9);

	root->left->left = new Node(1);
	root->left->right = new Node(6);

	root->right->right = new Node(8);

	root->left->right->left = new Node(5);
	root->left->right->right = new Node(10);

	root->right->right->left = new Node(3);
	root->right->right->right = new Node(4);


	levelOrderTraversal(root);

	return 0;
}
