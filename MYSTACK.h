#include<bits/stdc++.h>
using namespace std;
template<typename N> class Node
{
    public:
        N value;
        Node* next;
        Node* prev;

        Node(N val)
        {
            value = val;
            next = NULL;
            prev = NULL;
        }
};

template<typename S> class Stack
{
    
    Node<S>  *head;
    Node<S> *top;   
    int count = 0;
    public:
        Stack()
        {
            head = NULL;
            top = NULL;
      
        }
        //PUSH
        void push(S val)
        {
            Node<S> *newNode = new Node<S>(val);
            if (head == NULL)
            {
                head = top = newNode;
                count++;
                return;
            }
            top->next = newNode;
            newNode->prev = top;
            top = newNode;
            count++;
        }
        //POP
        S pop()
        {
            Node<S> *delNode;
            delNode = top;
            S checkValue;
            if (head == NULL)
            {
                cout<<"Stack Underflow!"<<endl;
                return checkValue;
            }
            if (head == top)
            {
                head = top = NULL;
            }
            else
            {
                top = delNode->prev;
                top->next = NULL;
            }
            checkValue = delNode->value;
            delete delNode;
            count--;
            return checkValue;  
        }
        //EMPTY
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
        //TOP
            S Top()
            {   
                S check;
                if (top == NULL)
                {
                    cout<<"Stack Underflow | There is no element in the stack!"<<endl;
                    
                }
                else
                {
                    check = top->value;
                }
                return check;
            }
        //SIZE
        int size()
        {
            return count;
        }
        

};

