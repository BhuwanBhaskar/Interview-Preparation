#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *left, *right;
};

struct Node *newNode(int key){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = key;
	temp->left = temp->right = NULL;
	
	return temp;
}
//BST insert : duplicates not allowed
struct Node* insert(struct Node *root, int key){
	
	if(root == NULL){
		return newNode(key);
	}
	if(key < root->data){
		root->left = insert(root->left,key);
	}else{
		root->right = insert(root->right,key);
	}
	
	return root;
}

void inorder(struct Node *root){
	if(root){
		inorder(root->left);
		printf(" %d ",root->data);
		inorder(root->right);
	}
}

struct Node* search(struct Node *root, int key){
	
	if(root){
		if(root->data == key){
			return root;
		}else if(key < root->data){
			return search(root->left,key);
		}else if(root->data < key){
			return search(root->right,key);
		}
		return NULL;
	}
	return NULL;
}

bool isLeaf(struct Node *node){
	return node->left == NULL && node->right == NULL;
}

struct Node* minValue(struct Node *root){
	
	struct Node *temp = root;
	while(temp->left){
		temp = temp->left;
	}
	return temp;
}

//inorder successor is leftmost node in right subtree
//if right subtree is not present then succ is one of the ancestors of node
//precisely : from Cormen book Similarly for predecessor
/*
succ = node.parent
while(succ != NULL && succ->right == node){
node = succ;
succ = succ.parent;
}
return succ;

*/


struct Node* inorder_successor(struct Node *root, int item){
	
	//If right subtree of node is not null 
	struct Node *key = search(root,item);
	if(key->right){
		return minValue(key->right);
	}
	//if right subtree is null..start from root and search succ
	struct Node *succ = NULL;
	while(root){
		if(key->data < root->data){
			succ = root;
			root = root->left; //succ will be only in left subtree..
		}else if(key->data > root->data){
			root = root->right;
		}else{
			break;
		}
	}
	return succ;
}

struct Node* delete_key(struct Node *root, int key){
	
	if(root == NULL){
		return root;
	}
	if(key < root->data){
		root->left = delete_key(root->left,key);
	}else if(root->data < key){
		root->right = delete_key(root->right,key);
	}else{
		//delete node with 0 or 1 child
		if(root->left == NULL){
			struct Node *temp = root->right;
			free(root);
			printf("\nproblem : %d",temp->data);
			return temp;
		}else if(root->right == NULL){
			struct Node *temp = root->left;
			free(root);
			return temp;
		}
	    //delete node with 2 child
	    struct Node *temp = minValue(root->right);
	    root->data = temp->data;
	    root->right = delete_key(root->right,temp->data);
	}
	return root;
}

bool isBst(struct Node *root){
	static struct Node *prev = NULL;
	
	if(root){
		if(!isBst(root->left)){
		 	return false;
		 }
		if(prev && root->data <= prev->data){
			printf("\nComparing root : %d and prev: %d",root->data,prev->data);
			return false;
		}
		prev = root;
		return isBst(root->right);
	}
	return true;
}

struct Node* lowestCommonAncestor(struct Node *root, int key1, int key2){
	
	if(root == NULL){
		return NULL;
	}
	
	if(root->data < key1 && root->data < key2){
		return lowestCommonAncestor(root->right,key1,key2);
	}else if(key2 < root->data && key1 < root->data){
		return lowestCommonAncestor(root->left,key1,key2);
	}	
	return root;
}
//Given an array that stores a complete Binary Search Tree,
// write a function that efficiently prints the given array in ascending order.
//array is organized lie heap so a[i] has children at a[2i+1] and a[2i+2]
void printSorted(int a[], int beg, int end){
	
	if(beg < end){
		printSorted(a,2*beg+1,end);
		printf(" %d ",a[beg]);
		printSorted(a,2*beg+2,end);
	}
}

int kth_smallest_bst(struct Node *root, int k){
	static int in = 0;
	static int found = 0;
	
	if(root){
		
		if(found > 0){
			return found;
		}
		
		kth_smallest_bst(root->left,k);
		
		in++;
		if(k == in){
			found = root->data;
			return root->data;
		}
		else{
			return kth_smallest_bst(root->right,k);
		}
	}
	return -1;
}

void printKeysInRange(struct Node *root, int key1, int key2){
	
	if(root == NULL){
		return;
	}
	
	if(key1 < root->data){
		printKeysInRange(root->left,key1,key2);
	}
	
	if(key1 <= root->data && root->data <= key2){
		printf(" %d ",root->data);
	}
	
	if(root->data < key2){
		printKeysInRange(root->right,key1,key2);
	}
}

struct Node* sortedArrayToBalancedBst(int a[], int beg, int end){
	
	if(beg > end){
		return NULL;
	}
	
	int mid = beg + (end-beg)/2;
	struct Node *root = newNode(a[mid]);
	
	if(beg == end){
		return root;
	}
	
	root->left = sortedArrayToBalancedBst(a,beg,mid-1);
	root->right = sortedArrayToBalancedBst(a,mid+1,end);
	
	return root;
}

//delete nodes which falls outside [min,max]...traverse in postorder
struct Node* removeKeysOutsideRange(struct Node *root, int min, int max){
	
	if(root == NULL){
		return NULL;
	}
	
	root->left = removeKeysOutsideRange(root->left,min,max);
	root->right = removeKeysOutsideRange(root->right,min,max);
	
	if(root->data < min){
		struct Node *temp = root->right;
		free(root);
		return temp;
	}
	if(max < root->data){
		struct Node *temp = root->left;
		free(root);
		return temp;
	}
	
	return root;
}

int main(){
	struct Node *root = NULL;
	root = insert(root,10);
	insert(root,7);
	insert(root,16);
	insert(root,9);
	insert(root,8);
	insert(root,5);
	insert(root,22);
	
	printf("\nInorder : ");
	inorder(root);
	
	int key = 10;
	struct Node *keyNode = search(root,key);
	printf("\nSearch for %d : %d and parent: %d",key, keyNode == NULL ? -1 : keyNode->data);
	
	//printf("\nDeleting key %d : %d",key,delete_key(root,key)->data);
	printf("\nInorder : ");
	inorder(root);
	
	printf("\nIs tree BST : %d",isBst(root));
	int key1 = 8;
	int key2 = 22;
	struct Node  *lca = lowestCommonAncestor(root,key1,key2);
	printf("\nLowest Common Ancestor for %d and %d is : %d",key1,key2,lca == NULL ? -1 : lca->data);
	
	int a[] = {4, 2, 5, 1, 3};
	int sa = sizeof(a)/sizeof(a[0]);
	printf("\nArray is printed in ascending order : ");
	printSorted(a,0,sa);
	
	int item = 5;
	struct Node* succ = inorder_successor(root,item);
	printf("\nInorder Successor for %d is : %d",item,succ == NULL ? -1 : succ->data);
	
	int k = 5;
	printf("\n%d smallest key in BST is %d",k,kth_smallest_bst(root,k));
	
	{
		int key1 = 9,key2 = 22;
		printf("\nPrinting keys in range of %d and %d : ",key1,key2);
		printKeysInRange(root,key1,key2);
	}
	
	{
		int a[] = {1, 2, 3, 4, 5, 6, 7};
		int sa = sizeof(a)/sizeof(a[0]);
		struct Node *root = sortedArrayToBalancedBst(a,0,sa-1);
		printf("\nInorder : ");
		inorder(root);
	}
	
	{
		Node* root = NULL;
    	root = insert(root, 6);
    	root = insert(root, -13);
    	root = insert(root, 14);
    	root = insert(root, -8);
    	root = insert(root, 15);
    	root = insert(root, 13);
    	root = insert(root, 7);
 
    	printf("\nInorder traversal of the given tree is: ");
    	inorder(root);
 
    	root = removeKeysOutsideRange(root, -10, 13);
 
    	printf("\nInorder traversal of the modified tree is: ");
    	inorder(root);
	}
	return 0;
}
