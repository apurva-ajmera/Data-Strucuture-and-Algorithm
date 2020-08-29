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

//print doubly linked list
void printDLL()
{
  struct node* p = (struct node*)malloc(sizeof(struct node));
  p = head;
  while(p!=NULL)
  {
    cout<<p->data<<endl;
    p = p->next;
  }
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
  printDLL();
}
