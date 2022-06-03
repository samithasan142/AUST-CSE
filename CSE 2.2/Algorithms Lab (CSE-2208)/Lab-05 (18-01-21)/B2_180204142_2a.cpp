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


Node* bst_insert(Node* root, int data)
{
	if(root == NULL)
    {
		root = create_node(data);
	}

	else if(data < root->data)
    {
		root->left = bst_insert(root->left, data);
	}

	else if(data >= root->data)
    {
		root->right = bst_insert(root->right, data);
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
        cout<< root->data << " ";
        Inorder(root->right);
    }
}

bool bst_search(Node* root, int data)
 {
	if(root == NULL)
    {
		return false;
	}

	else if(root->data == data)
    {
		return true;
	}

	else if(data < root->data)
    {
		return bst_search(root->left, data);
	}

	else if(data >= root->data)
    {
		return bst_search(root->right, data);
	}

}

//For find the smallest node in BST & also find in order successor
Node* bst_minimum(Node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node* bst_delete(Node *root, int data)
{
    if(root == NULL)
    {
        return root;
    }

    else if(data < root->data)
    {
        root->left = bst_delete(root->left, data);
    }

    else if (data > root->data)
    {
        root->right = bst_delete(root->right, data);
    }

    else
    {
        // First Case:  Node with no child (Leaf Node)
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        //Second Case: Node with only One child
        else if(root->left == NULL)
        {
            struct Node *temp = root;
            root = root->right; // Replace the node with its child
            delete temp;
        }
        else if(root->right == NULL)
        {
            struct Node *temp = root;
            root = root->left;
            delete temp;
        }
        // Third Case: Node with Two child
        else
        {
            struct Node *temp = bst_minimum(root->right);
            root->data = temp->data;
            root->right = bst_delete(root->right, temp->data);
        }
    }

    return root;
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


	cout << "In Order: ";
    Inorder(root);
    cout << endl;

    //BST Search Start
    int key;
	cout << "Enter node to search: ";
	cin >> key;

	if(bst_search(root, key) == true)
    {
        printf("Node %d is Found in the tree.\n\n", key);
	}
	else{
       printf("Node %d is not Found in the tree.\n\n", key);
	}
    //BST Search End

    //BST Insert Start
	int key2;
	cout << "Enter A Node to Insert: ";
	cin >> key2;
	cout << "Before Insert(In Order): ";
    Inorder(root);
    cout << endl;

    root = bst_insert(root, key2);

    cout << "After Insert(In Order): ";
    Inorder(root);
    cout << endl;
    cout << endl;
    //BST Insert End

    //BST Delete Start
    int key3;
	cout << "Enter A Node to Delete: ";
	cin >> key3;
    cout<<"Before Delete(In Order): ";
    Inorder(root);
    cout << endl;

    root = bst_delete(root, key3);

    cout<<"After Delete(In Order): ";
    Inorder(root);
    cout << endl;
    //BST Delete End

	return 0;
}

