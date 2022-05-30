#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* create_node(int item)
{
    Node *new_node = new Node;

    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void add_left_child(Node *parent_node, Node *child)
{
    parent_node->left = child;
}

void add_right_child(Node *parent_node, Node *child)
{
    parent_node->right = child;
}

Node* create_tree()
{
    Node *two = create_node(2);
    Node *seven = create_node(7);
    Node *nine = create_node(9);
    add_left_child(two, seven);
    add_right_child(two,nine);

    Node *one = create_node(1);
    Node *six = create_node(6);
    add_left_child(seven,one);
    add_right_child(seven,six);

    Node *five = create_node(5);
    Node *ten = create_node(10);
    add_left_child(six,five);
    add_right_child(six,ten);

    Node *eight = create_node(8);
    add_right_child(nine,eight);

    Node *three = create_node(3);
    Node *four = create_node(4);
    add_left_child(eight,three);
    add_right_child(eight,four);

    return two;
}

struct Stack
{
    Node* n[50];
    int a[50];
    int top=0;

    void push(Node *n1, int n2)
    {
        n[top]=n1;
        a[top]=n2;
        top++;
    }

    Node* popNode()
    {
        top--;
        return n[top];
    }

    int popInt()
    {
        return a[top];
    }

    bool isEmpty()
    {
        if(top==0) return true;
        else return false;
    }

}stk;

void pre_order(Node *node)
{
    stk.push(node, 1);
    while(!stk.isEmpty())
    {
        Node* p = stk.popNode();
        int i = stk.popInt();
        if(p!=NULL)
        {
            if(i==1)
            {
                stk.push(p,2);
                cout << p->data << "->";
            }
            if(i==2)
            {
                stk.push(p,3);
                stk.push(p->left, 1);
            }
            if(i==3)
            {
                stk.push(p->right, 1);
            }
        }
    }

}

int main()
{
    Node *root = create_tree();

    cout<<root->data<<endl;
    pre_order(root);
    return 0;
}

