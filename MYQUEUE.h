#include<bits/stdc++.h>
using namespace std;

template<typename N>class Nodequeue
{
    public:
        N value;
        Nodequeue *Next;
        Nodequeue(N val)
        {
            this->value = val;
            this->Next = NULL;
        }
};
template<typename Q>class Queue
{
    Nodequeue<Q> *front;
    Nodequeue<Q> *rear;
    int count = 0;
    public:
        Queue()
        {
            front = NULL;
            rear = NULL;
        }

        //enqueue or push(val)
        void push(Q val)
        {
            Nodequeue<Q> *newNode = new Nodequeue<Q>(val);
            if (front == NULL)
            {
                front = newNode;
                rear = newNode;
                count++;
                return;
            }
            rear->Next = newNode;
            rear = rear->Next;
            count++;
            
        }
        //dequeue or pop()
        Q pop()
        {       
            Nodequeue<Q> *delValue;
            Q chk;
            if (front == NULL)
            {
                cout<<"Queue Underflow!"<<endl;
                return chk;
            }
            delValue = front;
            front = front->Next;
            if (front == NULL)
            {
                rear = NULL;
            }
            chk = delValue->value;
            count--;
            delete delValue;
            return chk;
        }
        //peak operation
        Q Front()
        {
            Q chk;
            chk = front->value;
            return chk;
        }
        Q Back()
        {
            Q chk;
            chk = rear->value;
            return chk;
        }
        bool empty()
        {
            if (front == NULL && rear == NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        int size()
        {
            return count;
        }

};