#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node* bst_minimum(Node* root)
{
    while(root->left != NULL)
        root = root->left;
    return root;
}

Node* bst_delete(Node *root, int data)
{
    if(root == NULL)
        return root;

    else if(data < root->data)
        root->left = bst_delete(root->left, data);

    else if (data > root->data)
        root->right = bst_delete(root->right, data);

    else
    {
        // Case 1:  Node with no child (Leaf Node)
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        //Case 2: Node with only One child
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
        // case 3: Node with Two child
        else
        {
            struct Node *temp = bst_minimum(root->right);
            root->data = temp->data;
            root->right = bst_delete(root->right, temp->data);
        }
    }

    return root;
}


void Inorder(Node *root)
{
    if(root == NULL){
        return;
    }

    else{
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

Node* bst_insert(Node *root, char data)
{
    if(root == NULL)
    {
        root = new Node();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if(data < root->data)
        root->left = bst_insert(root->left, data);

    else if(data>=root->data)
        root->right = bst_insert(root->right, data);

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

    cout<<"Before Delete(In Order): ";
    Inorder(root);
    cout << endl;

    root = bst_delete(root, 23);

    cout<<"After Delete(In Order): ";
    Inorder(root);
    cout << endl;

    return 0;
}
