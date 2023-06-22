#include<bits/stdc++.h>
using namespace std;

/*INPUT:
9
11 5 9 43 34 1 2 7 21
*/

class treeNode
{
    public:
        int data;
        treeNode* leftChild;
        treeNode* rightChild;

        treeNode(int val)
        {
            this->data = val;
            this->leftChild = NULL;
            this->rightChild = NULL;
        }

};

treeNode* insertionBST(treeNode* root,int val)
{
    treeNode* newNode = new treeNode(val);
    if (root == NULL)
    {
        root = newNode;
    }
    else if (val < root->data)
    {
        root->leftChild = insertionBST(root->leftChild,val);
    }
    else
    {
        root->rightChild = insertionBST(root->rightChild,val);
    }
    return root;
}

void inOrder(treeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->leftChild);
    cout<<root->data<<" ";
    inOrder(root->rightChild);
}

treeNode* searchBST(treeNode* root,int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == val)
    {   
        cout<<root->data;
        return root;
    }
    else if (val < root->data)
    {   
        cout<<root->data<<"->";
        searchBST(root->leftChild,val);
    }
    else
    {   
        cout<<root->data<<"->";
        searchBST(root->rightChild,val);
    }
    cout<<endl;
}
treeNode* inoerderSucc(treeNode* root)
{
    treeNode* curr = root;
    while (curr->leftChild != NULL)
    {
        curr = curr->leftChild;
    }
    return curr;
    
}

treeNode* deletionBST(treeNode* root,int val)
{
    if (val < root->data)
    {
        root->leftChild = deletionBST(root->leftChild,val);
    }
    else if (val > root->data)
    {
        root->rightChild = deletionBST(root->rightChild,val);
    }
    else
    {
        if (root->leftChild == NULL)
        {
            treeNode* temp = root->rightChild;
            free(root);
            return temp;
        }
        else if (root->rightChild == NULL)
        {
            treeNode* temp = root->leftChild;
            free(root);
            return temp;
            
        }
        else
        {
            treeNode* temp = inoerderSucc(root->rightChild);
            root->data = temp->data;
            root->rightChild = deletionBST(root->rightChild,temp->data);
        }
    }
    return root;
}

int main()
{
    int n;
    cin>>n;
    treeNode* root = NULL;
    for (int i = 0;i < n;i++)
    {   
        int val;
        cin>>val;
        root = insertionBST(root,val);
    }
  
    int key;
    cin>>key;
    // if (searchBST(root,key) == NULL)
    // {
    //     cout<<"Value is not exist!"<<endl;
    // }
    // else
    // {
    //     cout<<"Value is exist"<<endl;
    // }
    root = deletionBST(root,key);
    inOrder(root);
    return 0;
}