#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
  int data;  //store data of a node
  struct node* prev;   //storing address of next node
  struct node* next;   //storing address of previous node
};

struct node* head = NULL;  //initislize one pointer

//insertion in doubly linked list
struct node* makeDLL(int data)
{
  //check whether doubly linked list is empty or not
  if(head == NULL)
  {
    //initislize one local pointer
    struct node* k = (struct node*)malloc(sizeof(struct node));
    k->next = NULL;
    k->prev = NULL;
    k->data = data;
    head = k;
    return head;
  }
  struct node* k = (struct node*)malloc(sizeof(struct node));
  k->data = data;
  k->next = head;
  head->prev = k;
  k->prev = NULL;
  head = k;
  return head;
}

//deleting a first node of doubly linked list
int Delete_front()
{
  //check whether doubly linked list is empty or not
  if(head == NULL)
  {
    cout<<"Doubly linked list is empty";
    return -1;
  }

  //doubly linked list contain only one element
  else if(head->next == NULL)
  {
    //delete a node
    cout<<"deleted node contain value: "<<head->data<<endl;
    free(head);
    head = NULL;
  }

  else
  {
    //initialize local pointer
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    head = head->next;
    cout<<"deleted node contain value: "<<temp->data<<endl;
    free(temp); //delete a node
  }
  return 1;
}

//for deleting a last node
int Delete_last()
{
  //check whether doubly linked list is empty or not
  if(head == NULL)
  {
    cout<<"Doubly linked list is empty";
    return -1;
  }

  //doubly linked list contain only one element
  else if(head->next == NULL)
  {
    //delete a node
    cout<<"deleted node contain value: "<<head->data<<endl;
    free(head);
    head = NULL;
  }

  else
  {
    //initialize two local pointer
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    temp = head;

    //find out last node
    while(temp->next != NULL)
    {
      temp = temp->next;
    }
    temp1 = temp->prev; //set temp1 to previous node of last node
    temp1->next = NULL;
    cout<<"deleted node contain value: "<<temp->data<<endl;
    free(temp); //delete last node
    temp = NULL;
  }
  return 1;
}

//delete intermediate node
int Delete_inter(int data)
{
  //check whether doubly linked list is empty or not
  if(head == NULL)
  {
    cout<<"Doubly linked list is empty"<<endl;
    return -1;
  }

  //doubly linked list contain only one element
  else if(head->next == NULL)
  {
    //delete a node
    cout<<"deleted node contain value: "<<head->data<<endl;
    free(head);
    head = NULL;
  }

  else
  {
    //initialize two local pointer
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    temp = head;

    //find out desire node
    while(temp->data != data)
    {
      temp = temp->next;

      //in case of any node does not contain value as data
      if(temp->next == NULL)
      {
        cout<<"any node does not contain value: "<<data<<endl;
        return -1;
      }
    }

    temp1 = temp->prev;
    temp1->next = temp->next;
    temp->next->prev = temp1;
    cout<<"deleted node contain value: "<<temp->data<<endl;
    free(temp);
    temp = NULL;
  }
  return 1;
}

int main()
{
  int n,d;
  cout<<"how many numbers you want to insert: ";
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>d;
    makeDLL(d);
  }
  Delete_front();  //delete first node
  Delete_last();   //delete last node
  Delete_inter(20);  //delete intermediate node
}
