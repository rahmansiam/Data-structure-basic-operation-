#include <bits/stdc++.h>
using namespace std;

/*
Input:
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1
*/

/*
Output:
Root:0
Left:
   Root:1
   Left:3
   Right:4
Right:
   Root:2
   Left:
      Root:5
      Left:7
      Right:8
   Right:6
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

void spacePrint(int level);
void printTree(treeNode *root, int level);
void levelOrderTraversal(treeNode *root);
void boundaryTraversal(treeNode *root);

void printTree(treeNode *root, int level)
{
    if (root == NULL) // When the tree is empty
    {
        return;
    }
    if (root->leftChild == NULL && root->rightChild == NULL) // case 1
    {
        cout << root->data << endl;
    }
    else
    {
        cout << endl;
        spacePrint(level);
        cout << "Root:" << root->data << endl;
    }
    if (root->leftChild != NULL)
    {
        spacePrint(level);
        cout << "Left:";
        printTree(root->leftChild, level + 1);
    }
    if (root->rightChild != NULL)
    {
        spacePrint(level);
        cout << "Right:";
        printTree(root->rightChild, level + 1);
    }
}

void spacePrint(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "   ";
    }
}

void inOrder(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->leftChild);
    cout << root->data << " ";
    inOrder(root->rightChild);
}
void preOrder(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->leftChild);
    preOrder(root->rightChild);
}
void postOreder(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postOreder(root->leftChild);
    postOreder(root->rightChild);
    cout << root->data << " ";
}

void levelOrderTraversal(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<treeNode *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        treeNode *checkNode = q.front();
        q.pop();
        if (checkNode != NULL)
        {
            cout << checkNode->data << " ";
            if (checkNode->leftChild != NULL)
            {
                q.push(checkNode->leftChild);
            }
            if (checkNode->rightChild != NULL)
            {
                q.push(checkNode->rightChild);
            }
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
                cout << endl;
            }
        }
    }
}

void levelOrderReverse(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<treeNode *> q;
    stack<treeNode *> st;
    q.push(root);
    st.push(root);

    while (!q.empty())
    {
        treeNode *checkNode = q.front();
        q.pop();
        if (checkNode != NULL)
        {
            if (checkNode->leftChild != NULL)
            {
                q.push(checkNode->leftChild);
                st.push(checkNode->leftChild);
            }
            if (checkNode->rightChild != NULL)
            {
                q.push(checkNode->rightChild);
                st.push(checkNode->leftChild);
            }
        }
    }
    while (!st.empty())
    {
        root = st.top();
        cout << root->data << " ";
        st.pop();
    }
}

void printLeftNonLeaves(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->leftChild != NULL)
    {
        cout << root->data << " ";
        printLeftNonLeaves(root->leftChild);
    }
    else if (root->rightChild != NULL)
    {
        cout << root->data << " ";
        printLeftNonLeaves(root->rightChild);
    }
}
void printLeaves(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        cout << root->data << " ";
    }
    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
}
void printRightNonLeaves(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->rightChild != NULL)
    {
        cout << root->data << " ";
        printRightNonLeaves(root->rightChild);
    }
    else if (root->leftChild != NULL)
    {
        cout << root->data << " ";
        printRightNonLeaves(root->leftChild);
    }
}
void boundaryTraversal(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printLeftNonLeaves(root->leftChild);
    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
    printRightNonLeaves(root->rightChild);
}
 
int main()
{

    int n;
    cin >> n;
    treeNode *allNodes[n];
    for (int i = 0; i < n; i++)
    {
        allNodes[i] = new treeNode(-1);
    }

    for (int i = 0; i < n; i++)
    {
        int val, left, right;
        cin >> val >> left >> right;
        allNodes[i]->data = val;

        if (left != -1)
        {
            allNodes[i]->leftChild = allNodes[left];
        }
        if (right != -1)
        {
            allNodes[i]->rightChild = allNodes[right];
        }
    }

    // printTree(allNodes[0],0);

    // cout<<"Inorder:";
    inOrder(allNodes[0]);
    // cout<<"Preorder:";
    // preOrder(allNodes[0]);
    // cout<<"Postorder:";
    // postOreder(allNodes[0]);
    // levelOrderTraversal(allNodes[0]);
    // boundaryTraversal(allNodes[0]);

    // levelOrderReverse(allNodes[0]);

    return 0;
}
