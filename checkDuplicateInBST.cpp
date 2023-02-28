#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node -> data  = data;
    node -> left = node -> right = NULL;
    return (node);
}

bool checkDuplicate(Node* root  , unordered_set<int> &s)
{
    if(root == NULL) // if tree contain only one node
    {
        return false;
    }

    if (s.find(root -> data) != s.end())
    {
        return true;
    }

    s.insert(root -> data); // insert current node

    return checkDuplicate(root->left , s) || checkDuplicate(root->right , s);
}

bool checkdup(struct Node* root)
{
    unordered_set<int> s;
    return checkDuplicate(root , s);
}

int main()
{
    struct Node* root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(2);
    root -> left -> left = newNode(4);

    if(checkdup(root))
    {
        cout << "yes" << endl;
    }

    else{
        cout << "No" << endl;
    }

    return 0;

}