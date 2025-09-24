#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree (vector <int> preorder)  // Time Complexity: O(n)
{
    idx++;
    if (preorder[idx]==-1)
        return NULL;

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void preorder_traversal (Node* root)  // Time Complexity: O(n)
{                                     // Path: root -> left -> right
    if (root == NULL)
        return;
    
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal (Node* root)  // Time Complexity: O(n)
{                                    // Path: left -> root -> right
    if (root == NULL)
        return;
    
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
} 

void postorder_traversal (Node* root)  // Time Complexity: O(n)
{                                      // Path: left -> right -> root
    if (root == NULL)
        return;
    
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<" ";
}

void levelorder_traversal (Node* root)  // Time Complexity: O(n)
{                                       // Path: topmost level -> bottomost level
    queue <Node*> q;
    q.push(root);
    while (q.size()>0)
    {
        Node* curr = q.front();
        q.pop();
        cout<<curr->data<<" ";

        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

int main()
{
    vector <int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);
    preorder_traversal(root);
    cout<<endl;
    inorder_traversal(root);
    cout<<endl;
    postorder_traversal(root);
    cout<<endl;
    levelorder_traversal(root);
    cout<<endl;
}