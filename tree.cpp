/****************************************/
/**********BHUWAN BHASKAR MISHRA********/
/*Date :                        *******/
/*Program Name :                *******/

#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *left ;
  struct node *right;
};

struct node * new_node(int data)
{
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

void inorder(struct node *tree)
{
  if(tree != NULL)
  {
    inorder(tree->left);
    printf(" %d ", tree->data);
    inorder(tree->right);
  }
}

int height(struct node *tree)
{
  if(tree == NULL)
    return 0;

  return 1+max(height(tree->left) , height(tree->right));
}

int main()
{
  struct node *root = new_node(5);
  root->left = new_node(7);
  root->right = new_node(9);

  inorder(root);

  return 0;
}
