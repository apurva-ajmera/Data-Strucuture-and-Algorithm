#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
  int data;
  struct node* next;
};

struct node* head = NULL;  //initially declare one pointer

struct node* makeLL(int data)
{
  if(head == NULL) //check list is empty
  {
    struct node *k = (struct node*)malloc(sizeof(struct node)); //dynamic memory allocaation
    k->data = data;  //inserting data
    k->next = NULL;
    head = k;
    return head;  //return head pointer
  }
  struct node* k = (struct node*)malloc(sizeof(struct node));   //dynamic memory allocaation
  k->data = data;  //inserting data
  k->next = head;
  head = k;
  return head;   //return head pointer
}

int printLL()
{
  //create a temporary pointer for traversing linked list
  struct node* p = (struct node*)malloc(sizeof(struct node));
  p=head;
  while(p!=NULL)  //continues untill address is not null
  {
    cout<<p->data<<endl;
    p = p->next;
  }
  return 0;
}

//delete a node at front from linked list
int del_front()
{
  if(head==NULL)  //check linked list is empty or not
  {
    cout<<"linked list is empty"<<endl;
    return -1;
  }
  else if(head->next==NULL) //check linked list contain only one node
  {
    cout<<"deleted node's data is: "<<head->data<<endl;
    free(head);
    head = NULL;
  }
  else
  {
    struct node* p = (struct node*)malloc(sizeof(struct node)); //initialize a new pointer
    p = head;
    head = head->next;
    cout<<"deleted node's data is: "<<p->data<<endl;
    free(p);
  }
  return 1;
}

//delete a node at end of linked list
int del_end()
{
  //check linked list is empty or not
  if(head==NULL)
  {
    cout<<"linked list is empty"<<endl;
    return -1;
  }
  //linked list contain only one element
  else if(head->next==NULL)
  {
    cout<<"deleted node's data is: "<<head->data<<endl;
    free(head);  //delete a node
    head = NULL;
  }
  else
  {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p=head;
    while(p->next->next!=NULL)
    {
      p = p->next;
    }
    cout<<"deleted node's data is: "<<p->next->data;
    free(p->next);
    p->next = NULL;
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
    makeLL(d);
  }
  printLL();
  del_front();
  del_end();
}
