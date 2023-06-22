#include<bits/stdc++.h>
using namespace std;

class Node
{
     public:
          int value;
          Node *Next;
          Node(int val)
          {
               value = val;
               Next = NULL;
          }
};
struct Test
{
     int position[1000];
};

int countLinkedList(Node *&head)
{
     int count = 0;
     Node *temp = head;
     while (temp != NULL)
     {
          temp = temp->Next;
          count++;
     }
     return count;
}
void insertionAtTail(Node *&head,int value)
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
void insertionAtHead(Node *&head,int value)
{
     Node *newNode = new Node(value);
     newNode->Next = head;
     head = newNode;
}
void insertAtSpecificPosition(Node *&head,int pos,int val)
{
     int i = 0;
     Node *newNode = new Node(val);
     Node *temp = head;
     while (i < pos-2)
     {
          temp = temp->Next;
          i++;
     }
     newNode->Next = temp->Next;
     temp->Next = newNode;
     
}
int searchPositionFromUniqueList(Node *&head,int value)
{
     int count = 1;
     Node *temp = head;
     if (head == NULL)
     {
          return -1;
     }
     while (temp->value != value)
     {
          if (temp->Next == NULL)
          {
               return -1;
          }
          temp = temp->Next;
          count++;
     }
     return count;
}
Test searchPositionFromDuplicateListReturn(Node *& head,int value)
{
     int count = 1;
     int k = 1;
     Node *temp = head;
     Test T;
     while (temp != NULL)
     {
          if (temp->value == value)
          {
               T.position[k] = count;
               k++;
               
          }
          temp = temp->Next;
          count++;
     }
     T.position[0] = k;
     return T;

}
void insertionAfterSpecificValueForUniqueList(Node *&head,int searchValue,int value)
{
     int position;
     position = searchPositionFromUniqueList(head,searchValue);
     insertAtSpecificPosition(head,position+1,value);
}
void deletionAtHead(Node *&head)
{
     Node *temp = head;
     if (temp != NULL)
     {
          head = temp->Next;
          delete temp;
     }
     else
     {
          cout<<"There is no value in the linked list yet!"<<endl;
     }
    
}
void deletionAtTail(Node *&head)
{
     Node *temp = head;
     if (temp != NULL && temp->Next != NULL)
     {
          while (temp->Next->Next != NULL)
          {
               temp = temp->Next;
          }
          Node *delNode = temp->Next;
          temp->Next = NULL;
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
void deletionAtSpecificPosition(Node *&head,int position)
{    
     
     
     Node *temp = head;
     if (temp != NULL && position <= countLinkedList(head))
     {
          if (position == 1)
          {
               deletionAtHead(head);
          }
          else if (position == countLinkedList(head))
          {
               deletionAtTail(head);
          }
          else
          {
               int i = 1;
               while (i < position - 1)
               {
                    temp = temp->Next;
                    i++;
               }
               Node *delNode = temp->Next;
               temp->Next = delNode->Next;
               delete delNode;
          }
     }
     else
     {
         cout<<"Position is out of bound!"<<endl;
     }
}
void deletionByValueUnique(Node *&head,int value)
{
     int position;
     position = searchPositionFromUniqueList(head,value);
     if (position == -1)
     {
          cout<<"Value not found!"<<endl;
     }
     else
     {
          deletionAtSpecificPosition(head,position);
     }
}
Node* reverseNonRecursive(Node *&head)
{
     Node *prev = NULL;
     Node *current = head;
     if (head == NULL)
     {    
          cout<<"There is no value in the list yet!"<<endl;
          return head;
     }
     Node *next = head->Next;
     while (true)
     {
          current->Next = prev;
          prev = current;
          current = next;
          if (current == NULL) break;
          next = next->Next;
     }
     return prev;
     
}
Node* reverseRecursive(Node *&head)
{
     if (head == NULL || head->Next == NULL)
     {
          return head;
     }
     Node *newHead = reverseRecursive(head->Next);
     head->Next->Next = head;
     head->Next = NULL;
     return newHead;
}
int findMidTowPointer(Node* &head)
{    
     if (head == NULL)
     {
          return -1;
     }
     Node *fast = head;
     Node *slow = head;
     while (fast != NULL && fast->Next != NULL)
     {
          fast = fast->Next->Next;
          slow = slow->Next;
     }
     return slow->value;
     
}
void makeCycle(Node* &head,int pos)
{
     Node *temp = head;
     Node *startNode;
     int count = 1;
     while (temp->Next != NULL)
     {
          
          if (count == pos)
          {
               startNode = temp;
          }
          temp = temp->Next;
          count++;
     }
     temp->Next = startNode;
     
}
bool detectCycle(Node* &head)
{
     Node *slow = head;
     Node *fast = head;
     while (fast != NULL && fast->Next != NULL)
     {
          slow = slow->Next;
          fast = fast->Next->Next;
          if (slow->Next == fast->Next)
          {
               return true;
          }
     }
     return false;
     
}
void removeCycle(Node* &head)
{
     Node *slow = head;
     Node *fast = head;
     do
     {
          slow = slow->Next;
          fast = fast->Next->Next;
     } while (slow != fast);
     fast = head;
     while (slow->Next != fast->Next)
     {
          slow = slow->Next;
          fast = fast->Next;
     }
     slow->Next = NULL;
     
     
}
void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->Next != NULL)
        {
            cout << "-> ";
        }
        n = n->Next;
    }
}

int main()
{
     Node *head = NULL;
     int n;
     int position;
     cout<<"Choice 1:Insertion at Tail"<<endl;
     cout<<"Choice 2:Insertion at Head"<<endl;
     cout<<"Choice 3:Insertion at specific position"<<endl;
     cout<<"Choice 4:Search the position of value from unique list"<<endl;
     cout<<"Choice 5:Search the position of value from duplicate list"<<endl;
     cout<<"Choice 6:Insertion after a specific value(Unique List)"<<endl;
     cout<<"Choice 7:Deletion at head"<<endl;
     cout<<"Choice 8:Deletion at Tail"<<endl;
     cout<<"Choice 9:Deletion at specific position"<<endl;
     cout<<"Choice 10:Deletion by value (Unique list)"<<endl;
     cout<<"Choice 11:Reverse linked list (Non recursive)"<<endl;
     cout<<"Choice 12:Reverse linked list (Recursive)"<<endl;
     cout<<"Choice 13:Find mid using tow pointer"<<endl;
     cout<<"Choice 14:Make cycle at kth position in the list"<<endl;
     cout<<"Choice 15:Detect cycle in the list"<<endl;
     cout<<"Choice 16:Remove cycle from the list"<<endl;
     cout<<"Choice 0:To exit"<<endl;
     int choice;
     cout<<"Choice:";
     cin>>choice;
     while (choice != 0)
     {
          switch (choice)
          {
          case 1:
               cout<<"Enter the value to insert at Tail:";
               cin>>n;
               insertionAtTail(head,n);
               break;
          case 2:
               cout<<"Enter the value to insert at Head:";
               cin>>n;
               insertionAtHead(head,n);
               break;
          case 3:
               cout<<"Enter the desired position to insert:";
               cin>>position;
               cout<<"Enter the value to insert:";
               cin>>n;
               insertAtSpecificPosition(head,position,n);
               break;
          case 4:
               cout<<"Enter the value to search:";
               cin>>n;
               position = searchPositionFromUniqueList(head,n);
               if (position != -1)
               {
                    cout<<"The value is position at:"<<position<<endl;
               }
               else
               {
                    cout<<"The value is not in the list yet"<<endl;
               }
               break;
          case 5:
               cout<<"Enter the value to search the position:";
               cin>>n;
               Test T;
               T = searchPositionFromDuplicateListReturn(head,n);
               if (T.position[0] == 1)
               {
                    cout<<"The searched value is not in the linked list yet!"<<endl;
               }
               else
               {    
                    int size = T.position[0];
                    cout<<"The searched value is position at:";
                    for (int i = 1;i < size;i++)
                    {
                         cout<<T.position[i];
                         if (i < size-1)
                         {
                              cout<<",";
                         }
                    }
                    cout<<endl;
               }
               break;
          case 6:
               int searchValue;
               cout<<"Enter the value to search:";
               cin>>searchValue;
               cout<<"Enter the value to insert:";
               cin>>n;
               insertionAfterSpecificValueForUniqueList(head,searchValue,n);
               break;
          case 7:
               deletionAtHead(head);
               cout<<"After deletion:";
               display(head);
               cout<<endl;
               break;
          case 8:
               deletionAtTail(head);
               cout<<"After deletion:";
               display(head);
               cout<<endl;
               break;
          case 9:
               if (head == NULL)
               {
                    cout<<"There is no value in the list yet!"<<endl;
               }
               else
               {
                    cout<<"Enter the position of value to delet:";
                    cin>>position;
                    deletionAtSpecificPosition(head,position);
                    cout<<"After deletion:";
                    display(head);
                    cout<<endl;

               }
               break;
          case 10:
               if (head == NULL)
               {
                    cout<<"There is no value in the list yet!"<<endl;
               }
               else
               {
                    cout<<"Enter the value to delete:";
                    cin>>n;
                    deletionByValueUnique(head,n);
                    cout<<"After deletion:";
                    display(head);
                    cout<<endl;
               }
               break;
          case 11:
               head = reverseNonRecursive(head);
               break;
          case 12:
               head = reverseRecursive(head);
               break;
          case 13:
               int mid;
               mid = findMidTowPointer(head);
               if (mid == -1)
               {
                    cout<<"There is no value in the list yet!"<<endl;
               }
               else
               {
                    cout<<"The mid is:"<<mid<<endl;
               }
               break;
          case 14:
               cout<<"Enter the position to creat cycle:";
               cin>>position;
               makeCycle(head,position);
               break;
          case 15:
               bool cycleStatus;
               cycleStatus = detectCycle(head);
               if (cycleStatus == true)
               {
                    cout<<"There is a cycle in the list"<<endl;
               }
               else
               {
                    cout<<"There is no cycle in the list"<<endl;
               }
               break;
          case 16:
               cycleStatus = detectCycle(head);
               if (cycleStatus == true)
               {
                    removeCycle(head);
               }
               else
               {
                    cout<<"There is no cycle in the list"<<endl;
               }
               break;
          default:
               break;
          }
          cout<<"Next choice:";
          cin>>choice;

     }
     cout<<"Linked list:";
     display(head);
     cout<<endl;
     cout<<"Length of liked list:"<<countLinkedList(head);
  
     return 0;
}