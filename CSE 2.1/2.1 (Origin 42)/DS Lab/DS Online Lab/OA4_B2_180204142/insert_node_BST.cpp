#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* create_node(int data)
 {
	Node* new_node = new Node();

	if(new_node == NULL)
    {
        cout << "Error! Could not create a new node" << endl;
    }

	new_node->data = data;
	new_node->left = NULL;
    new_node->right = NULL;

	return new_node;
}


Node* bst_insert(Node* root,int data)
{
	if(root == NULL)
    {
		root = create_node(data);
	}

	else if(data < root->data)
    {
		root->left = bst_insert(root->left,data);
	}

	else if(data >= root->data)
    {
		root->right = bst_insert(root->right,data);
	}

	return root;
}

void Inorder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

int main()
 {
	Node* root = NULL;

	root = bst_insert(root, 38);
    root = bst_insert(root, 14);
	root = bst_insert(root, 8);
	root = bst_insert(root, 23);
	root = bst_insert(root, 18);
	root = bst_insert(root, 56);
	root = bst_insert(root, 45);
	root = bst_insert(root, 82);
	root = bst_insert(root, 70);

    cout << "Before Insert(In Order): ";
    Inorder(root);
    cout << endl;

    root = bst_insert(root, 16);

    cout << "After Insert(In Order): ";
    Inorder(root);
    cout << endl;
}
