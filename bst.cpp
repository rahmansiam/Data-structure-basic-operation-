#include<bits/stdc++.h>
using namespace std;

class treeNode
{
    public:
        int data;
        treeNode* leftChilde;
        treeNode* rightChilde;
        treeNode(int val)
        {
            this->data = val;
            leftChilde = NULL;
            rightChilde = NULL;
        }
};
void inOrder(treeNode* root)
{
    if(root == NULL)
    {
        return;
    }
    inOrder(root->leftChilde);
    cout<<root->data<<" ";
    inOrder(root->rightChilde);
}

treeNode* insertionBST(treeNode* root,int value)
{
    treeNode* newNode = new treeNode(value);
    if (root == NULL)
    {
        root = newNode;
        return root;
    }

    if (value < root->data)
    {
        root->leftChilde = insertionBST(root->leftChilde,value);
    }
    else if (value > root->data)
    {
        root->rightChilde = insertionBST(root->rightChilde,value);
    }
    return root;
}

treeNode* searchBST(treeNode* root,int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == value)
    {   
        cout<<root->data;
        return root;
    }
    else if (value < root->data)
    {   
        cout<<root->data<<"->";
        searchBST(root->leftChilde,value);
    }
    else
    {   
        cout<<root->data<<"->";
        searchBST(root->rightChilde,value);
    }
   
    cout<<endl;
 
}
treeNode* inordersucc(treeNode* root)
{
    treeNode* curr = root;
    while (curr->leftChilde != NULL)
    {
        curr = curr->leftChilde;
    }
    return curr;
    
}

treeNode* deletionBST(treeNode* root,int value)
{
    if (value < root->data)
    {
        root->leftChilde = deletionBST(root->leftChilde,value);
    }
    else if (value > root->data)
    {
        root->rightChilde = deletionBST(root->rightChilde,value);
    }
    else
    {
        if (root->leftChilde == NULL)   //case 1:if node is leaf node,case2:if root->leftchilde is null.
        {
            treeNode* temp = root->rightChilde;
            free(root);
            return temp;
        }
        else if(root->rightChilde == NULL)   //case 2:if root->rightchilde is null;
        {
            treeNode* temp = root->leftChilde;
            free(root);
            return temp;
        }
        else
        {
            treeNode* temp = inordersucc(root->rightChilde);
            root->data = temp->data;
            root->rightChilde = deletionBST(root->rightChilde,temp->data);
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

    // inOrder(root);
    // int key;
    // cin>>key;
    // if (searchBST(root,key) == NULL)
    // {
    //     cout<<"Value does not exist"<<endl;
    // }
    // else
    // {
    //     cout<<"Value is exist"<<endl;
    // }
    // root = deletionBST(root,key);
    inOrder(root);
    return 0;
}