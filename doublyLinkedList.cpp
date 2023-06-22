#include <bits/stdc++.h>
using namespace std;

class doublyNode
{
public:
    int value;
    doublyNode *prev;
    doublyNode *next;
    doublyNode(int val)
    {
        this->value = val;
        prev = NULL;
        next = NULL;
    }
};
void display(doublyNode *&n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->next != NULL)
        {
            cout << "-> ";
        }
        n = n->next;
    }
}
int countLinkedList(doublyNode *&node)
{
    int res = 0;
    while (node != NULL)
    {
        res++;
        node = node->next;
    }
    return res;
}
void insertAtHead(doublyNode *&head, int value)
{
    doublyNode *newNode = new doublyNode(value);
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(doublyNode *&head, int value)
{
    doublyNode *newNode = new doublyNode(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    doublyNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void reverseDoublyLinkedList(doublyNode *&head)
{
    doublyNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->value;
        if (temp->prev != NULL)
        {
            cout << "--->";
        }
        temp = temp->prev;
    }
}
void insertionAtSpecificPosition(doublyNode *&head, int position, int value)
{
    int i = 0;
    doublyNode *temp = head;
    doublyNode *newNode = new doublyNode(value);
    while (i < position - 2)
    {
        temp = temp->next;
        i++;
    }
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;
    temp->next->prev = newNode;
}
int searchValueUniqueList(doublyNode *&head, int searchValue)
{
    int count = 1;
    doublyNode *temp = head;
    if (head == NULL)
    {
        return -1;
    }
    while (temp->value != searchValue)
    {
        if (temp->next == NULL)
        {
            return -1;
        }
        temp = temp->next;
        count++;
    }
    return count;
}
void searchValueDuplicate(doublyNode *&head, int key)
{
    int count = 1;
    doublyNode *temp = head;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            cout << count << " ";
            flag = 1;
        }
        count++;
        temp = temp->next;
    }
    if (flag == 0)
    {
        cout << "The value is not yet in the list!" << endl;
    }
    cout << endl;
}
void insertionAfterSpecificValue(doublyNode *&head, int searchValue, int value)
{
    int position;
    position = searchValueUniqueList(head, searchValue);
    insertionAtSpecificPosition(head, position + 1, value);
}
void deletionAtHead(doublyNode *&head)
{
    doublyNode *temp = head;
    if (temp != NULL)
    {
        head = temp->next;
        delete temp;
    }
    else
    {
        cout << "There is no value in the linked list!" << endl;
    }
}
void deletionAtTail(doublyNode *&head)
{
    doublyNode *temp = head;
    if (temp != NULL && temp->next != NULL)
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        doublyNode *delNode = temp->next;
        temp->next = NULL;
        delete delNode;
    }
    else
    {
        if (temp == NULL)
        {
            cout << "There is no value in the list yet!" << endl;
        }
        else
        {
            deletionAtHead(head);
        }
    }
}
void deletionAtSpecificPosition(doublyNode *&head, int position)
{
    int i = 1;
    doublyNode *temp = head;
    if (position == 1)
    {
        deletionAtHead(head);
    }
    else
    {
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        doublyNode *delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }
}
void deletionByValueUniqueList(doublyNode *&head,int searchValue)
{
    int position;
    if (head == NULL)
    position = searchValueUniqueList(head,searchValue);
    if (position == -1)
    {
        cout<<"There is no value in the linked list yet!"<<endl;
    }
    else
    {
        deletionAtSpecificPosition(head,position);
    }

}
int main()
{
    doublyNode *head = NULL;
    int value, position;
    cout << "Choice 1:Insert at tail" << endl;
    cout << "Choice 2:Insert at head" << endl;
    cout << "Choice 3:Display linked list in reverse order" << endl;
    cout << "Choice 4:Insertion at specific position" << endl;
    cout << "Choice 5:Search value in unique list" << endl;
    cout << "Choice 6:Search value from duplicate list" << endl;
    cout << "Choice 7:Insertion after specinfic value" << endl;
    cout << "Choice 8:Deletion at head" << endl;
    cout << "Choice 9:Deletion at tail" << endl;
    cout << "Choice 10:Deletion at specific position" << endl;
    cout<<"Choice 11:Deletion by value from unique list"<<endl;
    cout << "Choice 0:To exit" << endl;
    cout << "Choice:";
    int choice;
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert at tail:";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 2:
            cout << "Enter the value to insert at head:";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 3:
            reverseDoublyLinkedList(head);
            cout << endl;
            break;
        case 4:
            cout << "Enter the desired position:";
            cin >> position;
            cout << "Enter the value to insert:";
            cin >> value;
            insertionAtSpecificPosition(head, position, value);
            break;
        case 5:
            cout << "Enter the value to search the position:";
            int searchValue;
            cin >> searchValue;
            cout << "The position of value is:" << searchValueUniqueList(head, searchValue) << endl;
            break;
        case 6:
            cout << "Enter the value to search the position:";
            cin >> value;
            searchValueDuplicate(head, value);
            break;
        case 7:
            cout << "Enter the value to search the position:";
            int searchVal;
            cin >> searchVal;
            cout << "Enter the value to insert spefically:";
            cin >> value;
            insertionAfterSpecificValue(head, searchVal, value);
            break;
        case 8:
            deletionAtHead(head);
            break;
        case 9:
            deletionAtTail(head);
            break;
        case 10:
            cout << "Enter the position of value to delete:";
            cin >> position;
            deletionAtSpecificPosition(head, position);
            break;
        case 11:
            cout<<"Enter the value to delete:";
            cin>>value;
            deletionByValueUniqueList(head,value);
            break;
        default:
            break;
        }
        cout << "Next choice:";
        cin >> choice;
    }

    cout << "Linked list:";
    display(head);
    cout << endl;
    cout << "Length of linked list:" << countLinkedList(head);
    return 0;
}