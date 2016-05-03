#include<iostream>

using namespace std;

template<typename type>
class Node
{
  public :

  type data;
  Node *left;
  Node *right;

  Node();
  Node(const type& value) : data(value),left(NULL),right(NULL)
  {

  }

};

template<typename type>
class Bt
{

  Node<type> *org;
  int size;

  public :

  Bt()
  {
    org = NULL;
    size = 0;
  }

  inline bool is_empty() const
  {
    return size == 0;
  }

  void inorder(Node<type> root) const;
  void insert(Bt<type> *root , type data);
  int height(Bt<type>) const;
};

template<typename type>
int Bt<type> :: height(Bt<type> root) const
{
  if(root == NULL)
    return 0;

  int left_ht = height(root->org->left)+1;
  int right_ht = height(root->org->right)+1;

  return left_ht > right_ht ? left_ht : right_ht;
}

template<typename type>
void Bt<type> :: inorder(Node<type> root) const
{
  if(root)
  {
    inorder(root->left);
    cout<<" "<<root->data<<" ";
    inorder(root->right);
  }
}

template<typename type>
void Bt<type> :: insert(Bt<type> *root , type data)
{
  if(root == NULL)
  {
    org = new Node<type>(data);
  }

  int left_ht = height(root->org->left);
  int right_ht = height(root->org->right);
  if(left_ht > right_ht)
  {
    insert(root->right , data);
  }
  else if(left_ht <= right_ht)
    insert(root->left , data);
}


int main()
{
  Bt<int> *bt;
  bt->insert(bt , 5);
  return 0;
}
