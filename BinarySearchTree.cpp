#include <iostream>
#include <stack>
using namespace std;

struct node
{
    node *left = NULL;
    node *right = NULL;
    int val;
};

void insert(node **head, int val)
{
    node *temp = *head;
    node *NewNode = new node();
    NewNode->val = val;
    if (*head == NULL)
    {
        *head = NewNode;
    }
    else
    {
        node *parent = *head;
        while (temp != NULL)
        {
            parent = temp;
            if (temp->val < val)
                temp = temp->right;
            else
                temp = temp->left;
        }
        if (parent->val < val)
            parent->right = NewNode;
        else
            parent->left = NewNode;
    }
}

void Inorder(node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->val << " ";
        Inorder(root->right);
    }
}

void Postorder(node *root)
{
    if (root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->val << " ";
    }
}

void Preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->val << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Inorder(node *root)
{
    stack<node *> s;
    node *curr = root;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
}

void Preorder(node *root)
{
    stack<node *> stk;
    node *temp;
    stk.push(root);
    while (stk.empty() == false)
    {
        temp = stk.top();
        stk.pop();
        cout << temp->val << " ";
        if (temp->right)
            stk.push(temp->right);
        if (temp->left)
            stk.push(temp->left);
    }
}

void Postorder(node *root)
{
    stack<node *> stk1;
    stack<node *> stk2;
    node *curr = NULL;
    stk1.push(root);
    while (!stk1.empty())
    {
        curr = stk1.top();
        stk1.pop();
        stk2.push(curr);
        if (curr->left != NULL)
            stk1.push(curr->left);
        if (curr->right != NULL)
            stk1.push(curr->right);
    }

    while (!stk2.empty())
    {
        cout << (stk2.top())->val << " ";
        stk2.pop();
    }
}

int main()
{
    node *head = NULL;
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 10);
    insert(&head, 2);
    insert(&head, 93);
    insert(&head, 92);
    Inorder(head);
    cout << endl;
    Postorder(head);
    cout << endl;
    Preorder(head);
}