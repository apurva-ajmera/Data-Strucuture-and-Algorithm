#include<iostream>
#include<algorithm>
using namespace std;

struct node{
  int value;
  node* prev;
  node* next;
};

//left-left unbalanced binary search tree
struct node* right_rotation(struct node* temp)
{
  struct node* newNode = new struct node;
  newNode = temp->prev;
  temp->prev = newNode->next;
  newNode->next = temp;
  return newNode;
}

//right-right unbalanced search tree
struct node* left_rotation(struct node* temp)
{
  struct node* newNode = new struct node;
  newNode = temp->next;
  temp->next = newNode->prev;
  newNode->prev = temp;
  return newNode;
}

//left-right unbalanced binary search tree
struct node* left_right_rotation(struct node* temp)
{
  struct node* newNode = new struct node;
  newNode = temp->prev;
  temp->prev = left_rotation(newNode);
  return right_rotation(temp);
}

//right-left unbalanced search tree
struct node* right_left_rotation(struct node* temp)
{
  struct node* newNode =  new struct node;
  newNode = temp->next;
  temp->next = right_rotation(newNode);
  return left_rotation(temp);
}

//return height of node
int height(struct node* temp)
{
  int h=0;
  if(temp!=NULL)
  {
    int leftSubTree_height = height(temp->prev);
    int rightSubTree_height = height(temp->next);
    int max_height = max(leftSubTree_height,rightSubTree_height);
    h = max_height+1;
  }
  return h;
}

int difference(node* temp)
{
  //calculate balance factor of node
  int bal_factor = height(temp->prev)-height(temp->next);
  return bal_factor;
}

//balance the node
struct node* balance(struct node* temp)
{
  //get balance factor
  int balance_factor = difference(temp);
  if(balance_factor>1)
  {
    if(difference(temp->prev)>0)
    {
      temp =  right_rotation(temp);
    }
    else
    {
      temp = left_right_rotation(temp);
    }
  }
  if(balance_factor<-1)
  {
    if(difference(temp->next)<0)
    {
      temp = left_rotation(temp);
    }
    else
    {
      temp = right_left_rotation(temp);
    }
  }
  return temp;
}

 node* makeTree(struct node* root, int value)
{
  if(root==NULL)
  {
    node* root = new struct node;
    root->value = value;
    root->prev = NULL;
    root->next = NULL;
    return root;
  }

  else if(value<root->value)
  {
        root->prev = makeTree(root->prev,value);
        root = balance(root);
  }
  else if(value>root->value)
  {
      root->next = makeTree(root->next,value);
      root = balance(root);
  }
  return root;
}

//PostOrder Traversal of tree
void preOrder(struct node* k)
{
  if(k!=NULL)
  {
    cout<<k->value;
    preOrder(k->prev);
    preOrder(k->next);
  }
}

//postOrder traversal of tree
void postOrder(struct node* k)
{
  if(k!=NULL)
  {
    postOrder(k->prev);
    postOrder(k->next);
    cout<<k->value;
  }
}

//InOrder traversal of tree
void inOrder(struct node* k)
{
  if(k!=NULL)
  {
    inOrder(k->prev);
    cout<<k->value;
    inOrder(k->next);
  }
}

int main()
{
  int n,num;
  cout<<"how many numbers you want to insert: ";
  cin>>n;
  struct node* root = new struct node;
  root = NULL;
  for(int i=0;i<n;i++)
  {
    cout<<"enter an element: ";
    cin>>num;
    root = makeTree(root,num);
  }
  cout<<(height(root))<<endl;
  cout<<"PreOrder Traversal: ";
  preOrder(root);
  cout<<endl;
  cout<<"PostOrder Traversal: ";
  postOrder(root);
  cout<<endl;
  cout<<"Inorder Traversal: ";
  inOrder(root);
}
