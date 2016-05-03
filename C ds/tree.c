/****************************************/
/**********BHUWAN BHASKAR MISHRA********/
/*Date :                        *******/
/*Program Name :                *******/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

int max(int a , int b)
{
  return a > b ? a : b;
}

int height(struct node *tree)
{
  if(tree == NULL)
    return 0;

  return 1+max(height(tree->left) , height(tree->right));
}

int count(struct node *tree)
{
  if(tree == NULL)
    return 0;

  return 1 + count(tree->left) + count(tree->right);
}

void clear(struct node *tree)
{
  if(tree == NULL)
    return;

  /*if(tree->left)*/
    clear(tree->left);
  /*if(tree->right)*/
    clear(tree->right);

  /*if(tree->left == NULL && tree->right == NULL)*/
  {
    printf("\nDeleting : %d",tree->data);
    free(tree);
  }
}

void mirror(struct node * tree , struct node ** mir)
{
  if(tree == NULL)
    return;

  *mir = new_node(tree->data);

  mirror(tree->left , &((*mir)->right));
  mirror(tree->right , &((*mir)->left));

}

bool is_identical(struct node * tree1 , struct node *tree2)
{
  if(tree1 == NULL && tree2 == NULL)
    return true;
  if(tree1 == NULL && tree2 != NULL)
    return false;
  if(tree1 != NULL && tree2 == NULL)
    return false;

  printf("\nComparing\n");

  return (tree1->data == tree2->data)&&
         is_identical(tree1->left,tree2->left) &&
         is_identical(tree1->right,tree2->right);

}

int count_leaves(struct node *tree)
{
  if(tree == NULL)
    return 0;

  if(tree->left == NULL && tree->right == NULL)
    return 1;

  return count_leaves(tree->left) + count_leaves(tree->right);
}

bool find(struct node* tree , struct node *who)
{
  if(tree == NULL || who == NULL)
    return false;

  if(tree->data = who->data)
    return true;

  return (find(tree->left , who) ||
         find(tree->right , who) );
}

struct node* left_subtree(struct node *tree , struct node *who)
{
  struct node* which;

  while(find(tree , who))
  {
    which = tree;
    tree = tree->left;
  }

  return which;
}

struct node* inorder_succ(struct node *tree , struct node whom)
{
  if(tree == NULL)
    return NULL;

  if(whom->right == NULL)
  {

  }
}
int main()
{
  struct node *root = new_node(5);
  root->left = new_node(7);
  root->right = new_node(9);
  root->left->right = new_node(11);
  root->right->left = new_node(10);
  root->left->right->left = new_node(13);
  root->right->right = new_node(15);

  printf("\nHeight : %d",height(root));
  printf("\nCount : %d\n",count(root));
  inorder(root);

  struct node *mir = NULL;
  mirror(root , &mir);
  printf("\n");
  inorder(mir);

  if(is_identical(root , mir))
    printf("\nSame\n");
  else
    printf("\nNope\n");

  printf("\nCount Leaves org : %d" , count_leaves(root));
  printf("\nCount Leaves mir : %d" , count_leaves(mir));
  return 0;
}
