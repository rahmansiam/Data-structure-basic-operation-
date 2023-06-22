#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int value;
        Node *Next;
        Node(int val)
        {
            this->value = val;
            this->Next = NULL;
        }
};
int countLength(Node* &head)
{
    int count = 0;
    Node *temp = head;
    do
    {
       count++;
       temp = temp->Next;
    } while (temp != head);
    return count;
}
void insertAtTail(Node* &head,int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        newNode->Next = head;
        return;
    }
    Node *temp = head;
    while (temp->Next != head)
    {
        temp = temp->Next;
    }
    newNode->Next = head;
    temp->Next = newNode;
    
}
void insertAtHead(Node* &head,int value)
{
    Node *newNode = new Node(value);
    newNode->Next = head;
    if (head == NULL)
    {
        head = newNode;
        newNode->Next = head;
        return;
    }

    Node *temp = head;
    while (temp->Next != head)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
    head = newNode;
    
}
void display(Node *head)
{
   if (head == NULL)
   {
        cout<<"There is no value in the list yet!"<<endl;
        return;
   }
   Node *temp = head;
   do
   {
    cout<<temp->value;
    temp = temp->Next;
    if (temp != head)cout<<" -> ";
   } while (temp != head);
   cout<<endl;
   
}
void deletionAtHead(Node* &head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        Node *delNode = temp;
        while (temp->Next != head)
        {
            temp = temp->Next;
        }
        temp->Next = delNode->Next;
        head = delNode->Next;
        delete delNode;
        
    }
    else
    {
        cout<<"There is no value in the list yet!"<<endl;
    }
}

void deletionAtTail(Node *&head)
{
     Node *temp = head;
     if (temp != NULL && temp->Next != head)
     {
          while (temp->Next->Next != head)
          {
               temp = temp->Next;
          }
          Node *delNode = temp->Next;
          temp->Next = delNode->Next;
          delete delNode;
          
     }
     else
     {
          if (temp == NULL)
          {
               cout<<"There is no value in the linked list yet!"<<endl;
               
          }
          else
          {
               deletionAtHead(head);    
          }
     }
}


int main()
{
    Node *head = NULL;
    int value,position;
    cout<<"Choice 1:Insert at head"<<endl;
    cout<<"Choice 2:Insert at tail"<<endl;
    cout<<"Choice 3:Deletion at head"<<endl;
    cout<<"Choice 4:Deletion at tail"<<endl;
    cout<<"Choice 5:Insert at specific position"<<endl;
    cout<<"Choice 6:Enter 0 to exit"<<endl;
    int choice;
    cout<<"Next choice:";
    cin>>choice;

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout<<"Enter the value to insert at head:";
            cin>>value;
            insertAtHead(head,value);
            break;
        case 2:
            cout<<"Enter the value to insert at tail:";
            cin>>value;
            insertAtTail(head,value);
            break;
        case 3:
            deletionAtHead(head);
            display(head);
            break;
        case 4: 
            deletionAtTail(head);
            display(head);
            break;
        default:
            break;
        }  
        cout<<"Next Choice:";
        cin>>choice; 
    }
    cout<<"Linked list:";
    display(head);
    cout<<"Lenth of linked list:"<<countLength(head);

    return 0;
    
}
