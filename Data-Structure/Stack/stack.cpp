#include<iostream>
using namespace std;
#define capacity 10

class Stack
{
  int top;//top of stack
public:
  int arr[capacity];//intialize the array for store and delete element of stack

  Stack()
  {
      top=-1;//initailize top of stack
  }

  //check whether stack is empty
  bool isEmpty()
  {
    return (top==-1);
  }

  //check whether stack is full
  bool isFull()
  {
    return (top==capacity-1);
  }

  //peek the element from the top of stack without removing it
  int peek()
  {
    if(isEmpty())
    {
      cout<<"stack is empty";
      return -1;
    }
    cout<<"top of the stack is: "<<arr[top]<<endl;
    return 1;
  }

  //current size of Stack
  int size()
  {
    return top;
  }

  //implementation of push operation
  int push(int i)
  {
    if(isFull())
    {
      cout<<"stack is overflow";
      return -1;
    }
    ++top;  //increment top to set position of top 0 when first element is insert
    arr[top] = i;
    return 1;
  }

  //implementation of pop operaation
  int pop()
  {
    if(isEmpty())//check stack is empty
    {
      cout<<"stack is empty";
      return -1;
    }
    cout<<"deleted element is: "<<arr[top]<<endl;
    top--;
    return 1;
  }
};

int main()
{
  Stack s1;
  s1.push(32);
  s1.peek();
  s1.push(40);
  s1.peek();
  s1.push(15);
  s1.peek();
  s1.pop();
  s1.pop();
  s1.pop();
}
