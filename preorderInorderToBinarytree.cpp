#include<bits/stdc++.h>
using namespace std;

/*
Input:
9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6
*/

class treeNode
{
    public:
        int data;
        treeNode *leftChild;
        treeNode *rightChild;

        treeNode(int val)
        {
            this->data = val;
            this->leftChild = NULL;
            this->rightChild = NULL;
        }

}; 
void preOrderTraversal(treeNode *root)
{   
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->leftChild);
    preOrderTraversal(root->rightChild);
}


int searchInOrder(int inOrder[],int current,int start,int end)
{
    for (int i = start;i <= end;i++)
    {
        if (inOrder[i] == current)
        {
            return i;
        }
    }

    return -1;
}

treeNode* buildTreePreIn(int preOrder[],int inOrder[],int start,int end)
{
    static int id = 0;
    int current = preOrder[id];
    id++;
    treeNode* newNode = new treeNode(current);
    if (start == end)
    {
        return newNode;
    }
    int pos = searchInOrder(inOrder,current,start,end);
    newNode->leftChild = buildTreePreIn(preOrder,inOrder,start,pos-1);
    newNode->rightChild = buildTreePreIn(preOrder,inOrder,pos+1,end);
    return newNode;
}


int main()
{
    int n;
    cin>>n;
    int preOrder[n];
    int inOrder[n];

    for (int i = 0;i < n;i++)
    {
        cin>>preOrder[i];
    }

    for (int i = 0;i < n;i++)
    {
        cin>>inOrder[i];
    }

    treeNode* root = buildTreePreIn(preOrder,inOrder,0,n-1);
    preOrderTraversal(root);

    
}