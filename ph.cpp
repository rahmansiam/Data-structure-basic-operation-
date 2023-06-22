#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* left;
        Node* right;
        Node(int value)
        {
            this->val = value;
            this->left = NULL;
            this->right = NULL;
        }
};



void level_order(Node* root)
{
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        Node* parant = q.front();
        cout<<parant->val<<" ";
        q.pop();
        if (parant->left != NULL) q.push(parant->left);
        if (parant->right != NULL) q.push(parant->right);
    }
    
}
// Node* insertBST(int l,int r,int ar[]) //////take input using binary searach algrithm(Balanced hight tree).
// {   
//     if (l > r) return NULL;
//     int mid = l+(r-l)/2;
//     Node* newNode = new Node(ar[mid]);
//     newNode->left = insertBST(l,mid-1,ar);
//     newNode->right = insertBST(mid+1,r,ar);
//     return newNode;
// }
Node* insert_bst(Node* root,int val)
{   
    Node *newNode = new Node(val);  
    if (root == NULL)
    {
        root = newNode;
        return root;
    }
    if (val < root->val) root->left =  insert_bst(root->left,val);
    else root->right = insert_bst(root->right,val); 
    return root;
}
Node* minNode(Node* root)
{
    if (root == NULL) return NULL;
    Node* x = minNode(root->left);
    if (x == NULL) return root;
    else return x;

}
Node* deletionInBST(Node* root,int key)
{
    if (root == NULL) return NULL;

    if (root->val == key)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            root = temp;
        }
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            root = temp;
        }
        else
        {
            Node* min = minNode(root->right);
            root->val = min->val;
            root->right = deletionInBST(root->right,min->val);
        }
    }
    else if (key < root->val)
    {
        root->left = deletionInBST(root->left,key);
    }
    else
    {   
        root->right = deletionInBST(root->right,key);
    }
    return root;
}
void zigzagTraversal(Node* root)
{   
    if (root == NULL) return;
    stack<Node*>currLevel;
    stack<Node*>nextLevel;
    bool leftToright = true;
    currLevel.push(root);
    while (!currLevel.empty())
    {
        Node* temp = currLevel.top();
        currLevel.pop();
        if (temp != NULL)
        {
            cout<<temp->val<<" ";
            if (leftToright)
            {
                if (temp->left) nextLevel.push(temp->left);
                if (temp->right) nextLevel.push(temp->right);
            }
            else
            {
                if (temp->right) nextLevel.push(temp->right);
                if (temp->left) nextLevel.push(temp->left);
            }
        }
        if (currLevel.empty())
        {
            leftToright =! leftToright;
            swap(currLevel,nextLevel);
        }
    }
    
}
Node* invert(Node* root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node* temp;
    invert(root->left);
    invert(root->right);
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}
int main()
{
    int n;
    cin>>n;
    // int a[n];
    Node* root = NULL;
    for (int i = 0;i < n;i++)
    {   
        int a;
        cin>>a;
        // cin>>a[i];
        root = insert_bst(root,a);
    }
    // root = insertBST(0,n-1,a);
    // level_order(root);
    zigzagTraversal(root);

    return 0;
}