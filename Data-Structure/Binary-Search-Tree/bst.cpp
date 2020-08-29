#include<iostream>
using namespace std;

struct node
{
  int data;
  struct node* left;
  struct node* right;
};

node* createNode(int key)
{
  struct node* k = new struct node;
  k->data = key;
  k->left = NULL;
  k->right = NULL;
  return k;
}

//inserting a key on the binary search tree
node* makeBST(struct node* root,int key)
{
  if(key<root->data)
  {
    if(root->left == NULL)

      root->left = createNode(key);
    else
      makeBST(root->left,key);
    return root;
  }
  else if(key>root->data)
  {
    if(root->right == NULL)

      root->right = createNode(key);
    else
      makeBST(root->right,key);
    return root;
  }
}

//implementation of inorder traversal
void Inorder(struct node* root)
{
  struct node* k =  new struct node;
  k= root;
  if(k!=NULL)
  {
    Inorder(k->left);
    cout<<k->data;
    Inorder(k->right);
  }
}

//implementation of preorder traversal
void Preorder(struct node* root)
{
  struct node* k= new struct node;
  k= root;
  if(k!=NULL)
  {
    cout<<k->data;
    Preorder(root->left);
    Preorder(root->right);
  }
}

//immplementation of postorder traversal
void Postorder(struct node* root)
{
  struct node* k= new struct node;
  k=root;
  if(k!=NULL)
  {
    Postorder(k->left);
    Postorder(k->right);
    cout<<k->data;
  }
}

//finding an element
/*int find(struct node *root,int data)
{
  if(root == NULL)
  {
    return 1;
  }
  else if(data == root->data)
  {
    cout<<"element is found"<<endl;
    return 1;
  }
  else
  {
    if(data < root->data)
    {
      find(root->left,data);
    }
    else
    {
      find(root->right,data);
    }
  }
  return 1;
}*/

//find maximum element in binary search tree
int max_element(struct node* k)
{
  while(k->right)
  {
    k = k->right;
  }
  return k->data;
}

//find minimum element in binary search tree
int min_element(struct node* k)
{
  while(k->left)
  {
    k = k->left;
  }
  return k->data;
}

int main()
{
  int n,key,maximum,minimum;
  cout<<"how many numbers you want to insert: ";
  cin>>n;
  cout<<"enter a number: ";
  cin>>key;
  struct node* root = new struct node;
  root = createNode(key);

  for(int i=0;i<n-1;i++)
  {
    cin>>key;
    makeBST(root,key);
  }
  cout<<"Inorder Traversal:"<<endl;
  Inorder(root);
  cout<<endl;
  cout<<"Preorder Traversal:"<<endl;
  Preorder(root);
  cout<<endl;
  cout<<"Postorder Traversal:"<<endl;
  Postorder(root);
  //find(root,5);
  maximum = max_element(root);
  cout<<"maximum element in binary search tree: "<<maximum;
  minimum = min_element(root);
  cout<<"minimum element in binary search tree: "<<minimum;
}
