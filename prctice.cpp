#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node(int val)
    {
        this->value = val;
        Next = NULL;
    }
};
void insertionAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}
void display(Node *n)
{
    while (n != NULL)
    {
        cout<<n->value;
        if (n->Next != NULL)
        {
            cout << "-> ";
        }
        n = n->Next;
    }
}
int findMid(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->Next != NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
    }
    return slow->value;
    
}
void moveTailToHead(Node* &head)
{
    Node *last = head;
    Node *secLast = NULL;
    while (last->Next != NULL)
    {
        secLast = last;
        last = last->Next;
    }
    secLast->Next = NULL;
    last->Next = head;
    head = last;

}
void moveHeadToTail(Node* &head)
{
    Node *last = head;
    Node *first = head;
    while (last->Next != NULL)
    {
    
        last = last->Next;
    }
    head = first->Next;
    first->Next = NULL;
    last->Next = first;
    
    
}
int main()
{
    Node *head = NULL;
    cout<<"Enter the number of input:";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        insertionAtTail(head, value);
    }
    moveHeadToTail(head);
    cout << endl;
    display(head);

    // cout<<endl;
    // cout<<"The middle value is:"<<findMid(head)<<endl;
  

    return 0;
}
