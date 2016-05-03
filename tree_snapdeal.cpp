/****************************************/
/**********BHUWAN BHASKAR MISHRA********/
/*Date :                        *******/

/*Program Name :  A tree is represented in the form of array.
Where index(i) of the array represent value of a node and the value inside(A[i])
represent the parent index of the tree.
Value corresponding to root is -1. Construct the tree.
For Eg: 1,-1,1,2,3,1 index 1 is root, with three children at indexes
(0, 2 and 5) and index 3 is a child of 2, index 4 is a child of index 3
  *******/

#include<iostream>

struct node
{
  int val;
  struct node * next;
};

void construct_tree(struct node ** tree , int arr[] , int size)
{
  if(size == 0)
    return;

  struct node * new_node = (struct node *)new(struct node);
  new_node -> val = arr[0];
  new_node -> next = NULL;

  *tree = new_node;

  for(int i = 1; i < size; i++)
  {



  }
}
int main()
{
  struct node * tree = NULL;
  int arr[] = {-1 , 0 , 0 , 2 , 1 , 4 , 2};
  int size = sizeof(arr)/sizeof(arr[0]);

  construct_tree(&tree , arr , size);

//  display_tree(tree);

  return 0;
}
