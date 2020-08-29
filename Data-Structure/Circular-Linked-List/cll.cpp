#include<iostream>
#include<cstdlib>
using namespace std;

//declare circular linked list
struct node
{
  int data;
  struct node* next;
};

//declare head as global pointer
struct node* head = NULL;

//insert node at front of circular linked list
int insertAtFront(int data)
{
  //create a new node
  struct node* newNode = (struct node*)malloc(sizeof(struct node));

  //create a local pointer for finding last node
  struct node* temp = head;

  //check circular linked list is empty or not
  if(head == NULL)
  {
    newNode->data = data;
    newNode->next = newNode;
    head = newNode;
  }

  else
  {
    while(temp->next!=head)
    {
      temp = temp->next;
    }
    newNode->data = data;
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
  }
  return 1;
}

//insert a node at last of circular linked list
int insertAtLast(int data)
{
  //create a new node
  struct node* newNode = (struct node*)malloc(sizeof(struct node));

  //create a local pointer for finding last node
  struct node* temp = head;

  //check circular linked list is empty or not
  if(head == NULL)
  {
    newNode->data = data;
    newNode->next = newNode;
    head = newNode;
  }

  else
  {
    while(temp->next!=head)
    {
      temp = temp->next;
    }
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
  }
  return 1;
}

//delete a node at front
int deleteAtFront(struct node *p)
{
  //initialize two local pointer
  struct node* temp = (struct node*)malloc(sizeof(struct node));

  //check circular linked list is empty
  if(p == NULL)
  {
    cout<<"circular linked list is empty"<<endl;
    return -1;
  }
  else
  {
    temp = head;
    //first find out last node of list
    while(temp->next!=head)
    {
      temp = temp->next;
    }
    head = head->next;
    temp->next = head;
    free(p);
    p = NULL;
    return 1;
  }
}

//delete the last node
int deleteAtLast(struct node *p)
{
  //initialize one local pointer
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  struct node* temp1 = (struct node*)malloc(sizeof(struct node));

  if(p == NULL)
  {
    cout<<"circular linked list is empty";
    return -1;
  }
  else
  {
    //first set temp to first node
    temp = p;

    //find out previous node of last node
    while(temp->next->next != p)
    {
      temp = temp->next;
    }
    temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
    return 1;
  }
}

int printCLL(struct node* temp)
{
  //check circular linked list is empty or not
  if(temp == NULL)
  {
    cout<<"circular linked list is empty: ";
  }

  else
  {
    do
    {
      cout<<temp->data<<" ";
      temp = temp->next;
    }while(temp!=head);
  }
  return 1;
}

int main()
{
  insertAtFront(40);  //insert at front
  insertAtFront(30);  //insert at front
  insertAtFront(20);  //insert at front
  insertAtFront(10);  //insert at front
  insertAtLast(50);  //insert at last
  deleteAtFront(head);  //delete first node
  deleteAtLast(head);  //delete last node
  printCLL(head);    //printing content of circular linked list
}
