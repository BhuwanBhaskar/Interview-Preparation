/****************************************/
/**********BHUWAN BHASKAR MISHRA********/
/*Date :                        *******/
/*Program Name :                *******/

#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left , *right;
};

struct node * new_node(int data)
{
  struct node* temp = (struct node*)malloc(sizeof(int));
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


int main()
{
  struct node *root = NULL;
  root = new_node(5);
  root->left = new_node(7);
  root->right = new_node(9);

  inorder(&root);

  return 0;
}
