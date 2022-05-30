#include <iostream>
using namespace std;


struct Node
{
	int key;
	Node *left, *right;

	Node(int key)
	{
		this->key = key;
		this->left = this->right = NULL;
	}
};


bool printLevel(Node* root, int level)
{
	if (root == NULL)
		return false;

	if (level == 1)
	{
		cout << root->key << " ";


		return true;
	}

	bool left = printLevel(root->left, level - 1);
	bool right = printLevel(root->right, level - 1);

	return left || right;
}


void levelOrderTraversal(Node* root)
{

	int level = 1;

	while (printLevel(root, level))
		level++;
}

int main()
{
	Node* root = NULL;

	root = new Node(15);
	root->left = new Node(10);
	root->right = new Node(20);
	root->left->left = new Node(8);
	root->left->right = new Node(12);
	root->right->left = new Node(16);
	root->right->right = new Node(25);

	levelOrderTraversal(root);

	return 0;
}
