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
    Node* n[30];
    int a[30];
    int top=0;

    void push(Node *y, int z)
    {
        n[top]=y;
        a[top]=z;
        top++;
    }
    Node* popN()
    {
        top--;
        return n[top];
    }
    int popI()
    {
        return a[top];
    }
    bool isEmpty()
    {
        if(top==0) return true;
        else return false;
    }
}s;

void pre_order(Node *node)
{
    /*printf("%d->",node->data);
    if(node->left != NULL)
        pre_order(node->left);
    if(node->right != NULL)
        pre_order(node->right);*/

    s.push(node, 1);
    while(!s.isEmpty())
    {
        Node* p = s.popN();
        int i = s.popI();
        if(p!=NULL)
        {
            if(i==1)
            {
                s.push(p,2);
                printf("%d->", p->data);
            }
            if(i==2)
            {
                s.push(p,3);
                s.push(p->left, 1);
            }
            if(i==3)
            {
                s.push(p->right, 1);
            }
        }
    }

}
void in_order(Node *node)
{
    //implement by yourself

    s.push(node, 1);
    while(!s.isEmpty())
    {
        Node* p = s.popN();
        int i = s.popI();
        if(p!=NULL)
        {
            if(i==1)
            {
                s.push(p,2);
                s.push(p->left, 1);

            }
            else
            {
                printf("%d->", p->data);
                s.push(p->right, 1);
            }
        }
    }



}
void post_order(Node *node)
{
    //implement by yourself

    s.push(node, 1);
    while(!s.isEmpty())
    {
        Node* p = s.popN();
        int i = s.popI();
        if(p!=NULL)
        {
            if(i==1)
            {
                s.push(p,2);
                s.push(p->left, 1);

            }
            if(i==2)
            {
                s.push(p,3);
                s.push(p->right, 1);

            }
            if(i==3)
            {
                printf("%d->", p->data);
            }
        }
    }


}
int main()
{
    Node *root = create_tree();

    cout<<root->data<<endl;
    post_order(root);
    return 0;
}
