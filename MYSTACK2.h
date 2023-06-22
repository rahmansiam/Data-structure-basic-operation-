#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int value;
        Node *Next;
        Node *prev;
        Node(int val)
        {
            value = val;
            Next = NULL;
            prev = NULL;
        }
};

class Stack
{
    Node *head;
    Node *top;
    int count = 0;
    public:
        void push(int val)
        {
            Node *newNode = new Node(val);
            if (head == NULL)
            {
                head = top = newNode;
                count++;
                return;
            }
            else
            {
                top->Next = newNode;
                newNode->prev = top;
                top = newNode;
                count++;
            }
        }

        int pop()
        {
            Node *delNode;
            delNode = top;
            int check;
            if (head == NULL)
            {
                cout<<"Stack is underflow"<<endl;
                return -1;
            }
            if (head == top)
            {
                head = top = NULL;
            }
            else
            {
                top = delNode->prev;
                top->Next = NULL;
            }
            check = delNode->value;
            delete delNode;
            count--;
            return check;
            
        }
        bool empty()
        {
            if (head == NULL)
            {
                return true;
            }
            else 
            {
                return false;
            }
        }
        int Top()
        {   
            int chk;
            if (top == NULL)
            {
                cout<<"There is no vlaue in list!"<<endl;
                return -1;
            }
            else
            {
                chk = top->value;
            }
            return chk;
        }
        int size()
        {
            return count;
        }
        int findMid()
        {   
            Node *temp = head;
            int countMid = 0;
            while (temp != NULL)
            {   

                if (countMid == (count/2))
                {
                    return temp->value;
                    break;
                }
                countMid++;
                temp = temp->Next;
            }  
        }

};

