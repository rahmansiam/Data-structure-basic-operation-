#include <bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode *left;
    treeNode *right;

    treeNode(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// void KthInorder(treeNode *root, int k)
// {
//     static int count = 0;
//     if (root == NULL)
//     {
//         return;
//     }
//     if (count <= k)
//     {
//         KthInorder(root->leftChild, k);
//         count++;

//         if (count == k)
//             ;
//         {
//             cout << root->data << endl;
//         }

//         KthInorder(root->rightChild, k);
//     }
// }
// void printLeaf(treeNode *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     if (root->leftChild == NULL && root->rightChild == NULL)
//     {
//         cout << root->data << " ";
//     }
//     printLeaf(root->leftChild);

//     printLeaf(root->rightChild);
// }
// int findMaxInBinaryTreeInLevelOrder(treeNode *root, int k)
// // {
// //     if (root == NULL)
// //     {
// //         return -1;
// //     }
// //     queue<treeNode *> q;
// //     q.push(root);
// //     q.push(NULL);
// //     int level = 0;
// //     int max = -9999;
// //     while (!q.empty())
// //     {
// //         treeNode *chk = q.front();
// //         q.pop();
// //         if (chk != NULL)
// //         {
// //             if (level == k)
// //             {
// //                 if (max < chk->data)
// //                 {
// //                     max = chk->data;
// //                 }
// //             }
// //             if (chk->leftChild != NULL)
// //             {
// //                 q.push(chk->leftChild);
// //             }
// //             if (chk->rightChild != NULL)
// //             {
// //                 q.push(chk->rightChild);
// //             }
// //         }
// //         else
// //         {
// //             if (!q.empty())
// //             {
// //                 q.push(NULL);
// //                 level++;
// //             }
// //         }
// //     }
// //     return max;
// // }
void inOrder(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
// bool isSame(treeNode *root1,treeNode *root2) //recusive
// {
//     if (root1 == NULL && root2 == NULL)
//     {
//         return true;
//     }
//     if (root1 == NULL || root2 == NULL || root1->data != root2->data)
//     {
//        return false;
//     } 
//     return isSame(root1->left,root2->left) && isSame(root1->right,root2->right);
// }

void levelOrderReverse(treeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    queue<treeNode*>q;
    stack<treeNode*>st;
    q.push(root);
    st.push(root);
    
    while (!q.empty())
    {
        treeNode *checkNode = q.front();
        q.pop();
        if (checkNode != NULL)
        {


            if (checkNode->left != NULL)
            {
                q.push(checkNode->left);
                st.push(checkNode->left);
                
            }
            if (checkNode->right != NULL)
            {
                q.push(checkNode->right);
                st.push(checkNode->right);
               
            }
        }
        
    }
    while (!st.empty())
    {
        root = st.top();
        cout<<root->data<<" ";
        st.pop();
    }
    
}
bool isMirror(treeNode *root1,treeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    else 
    {
        return (root1->data == root2->data&&
        isMirror(root1->left,root2->right)&&
        isMirror(root1->right,root2->left));
    }
    return false;
}

bool isSymmetric(treeNode* root)
{
    if (root == NULL)
    {
        return true;
    }
    return isMirror(root->left,root->right);
}


void zigzag_order(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<treeNode*>current;
    stack<treeNode*>next;
    current.push(root);
    bool leftToRight = true;
    while (!current.empty())
    {
        treeNode *temp = current.top();
        current.pop();
        if (temp != NULL)
        {
            cout<<temp->data<<" ";
            if (leftToRight)
            {
                if (temp->left)
                {
                    next.push(temp->left);
                }
                if (temp->right)
                {
                    next.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    next.push(temp->right);
                }
                if (temp->left);
                {
                    next.push(temp->left);
                }
            }
        }
        if (current.empty())
        {
            leftToRight != leftToRight;
            swap(current,next);
        }
    }
    
    
}

bool is_uniVal(treeNode* root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left != NULL && root->left->data != root->data)
    {
        return false;
    }
    if (root->right != NULL && root->right->data != root->data)
    {
        return false;
    }
    return is_uniVal(root->left) && is_uniVal(root->right);
}
void preOrder(treeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(treeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    // int n;
    // cin>>n;
    // treeNode *allNodes[n];
    // for (int i = 0;i < n;i++)
    // {
    //     allNodes[i] = new treeNode(-1);
    // }

    // for (int i = 0;i < n;i++)
    // {
    //     int val,left,right;
    //     cin>>val>>left>>right;
    //     allNodes[i]->data = val;

    //     if (left != -1)
    //     {
    //         allNodes[i]->left = allNodes[left];
    //     }
    //     if (right != -1)
    //     {
    //         allNodes[i]->right = allNodes[right];
    //     }
    // }

    // levelOrderReverse(allNodes[0]);

    // levelOrderTraversal(allNodes[0]);

    // KthInorder(allNodes[0],k);
    // printLeaf(allNodes[0]);
    // inOrder(allNodes[0]);
    // int k = 4;
    // cout<<findMaxInBinaryTreeInLevelOrder(allNodes[0],2);



    // treeNode* root1 = new treeNode(1); //Input in naiv approch
    // treeNode* root2 = new treeNode(1);
    // root1->left = new treeNode(1);
    // root1->right = new treeNode(1);
    // root1->left->left = new treeNode(1);
    // root1->left->right = new treeNode(1);
 
    // root2->left = new treeNode(2);
    // root2->right = new treeNode(3);
    // root2->left->left = new treeNode(4);
    // root2->left->right = new treeNode(5);




    // if (isSame(root1,root2))
    // {
    //     cout<<"Same"<<endl;
    // }
    // else
    // {
    //     cout<<"Not"<<endl;
    // }




    int a;  //levelOrderInput
    cin >> a;
    treeNode *root = new treeNode(a);
    queue<treeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        treeNode *presentNode = q.front();
        q.pop();
        int x, y;
        cin >> x >> y;
        treeNode *n1 = NULL;
        treeNode *n2 = NULL;
        if (x != -1)
            n1 = new treeNode(x);
        if (y != -1)
            n2 = new treeNode(y);
        presentNode->left = n1;
        presentNode->right = n2;
        if (n1 != NULL)
        {
            q.push(n1);
        }
        if (n2 != NULL)
        {
            q.push(n2);
        }
    }
    
    
    // levelOrderReverse(allNodes[0]);


    inOrder(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);


    // if (isSymmetric(allNodes[0]))
    // {
    //     cout<<"Mirror";
    // }
    // else
    // {
    //     cout<<"Not";
    // }
    // zigzag_order(allNodes[0]);

    // if (is_uniVal(root1))
    // {
    //     cout<<"Yes"<<endl;
    // }
    // else
    // {
    //     cout<<"NO"<<endl;
    // }

    return 0;
}