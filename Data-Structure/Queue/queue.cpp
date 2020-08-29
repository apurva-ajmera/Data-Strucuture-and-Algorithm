#include<iostream>
using namespace std;

class Queue
{
  int front,rear;

public:
  int a[10];
  Queue()
  {
    front=rear=-1;
  }

  bool isFull()
  {
    if(rear==9)// if rear is 9(size-1) queue is full
        return true;
    else
        return false;
  }

  bool isEmpty()
  {
    if(front==-1 && rear==-1)
        return true;
    else
        return false;
  }

  //inserting an element into queue
  int enqueue(int data)
  {
    if(isFull())
    {
      cout<<"queue is full";
      return -1;
    }
    else if(front==-1 && rear==-1)//inserting first element
    {
      front=rear=0;
      a[rear]=data;
    }
    else
    {
      rear = rear+1;
      a[rear] =  data;
    }
    return 1;
  }

  //deleting an element from the queue
  int dequeue()
  {
    int element;
    if(isEmpty())
    {
      cout<<"queue is empty";
      return -1;
    }
    else if(front==rear)
    {
      element = a[front];
      front=rear=-1;
      return element;
    }
    else
    {
      element = a[front];
      front = front+1;
      return element;
    }
  }
};

int main()
{
    Queue q1;
    int x;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    x = q1.dequeue();
    cout<<x<<" ";
    x = q1.dequeue();
    cout<<x<<" ";
    x = q1.dequeue();
    cout<<x<<" ";
}
