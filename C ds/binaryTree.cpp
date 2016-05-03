#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <queue>
#include<stack>
#include<strings.h>
#include<map>
using namespace std;
struct Node{
	int data;
	struct Node *left, *right;
};

struct Node* getNewNode(int data){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

void displayPreorder(struct Node *root){
	
	if(root != NULL){
		printf("%d ",root->data);
		displayPreorder(root->left);
		displayPreorder(root->right);
	}
}

void displayInorder(struct Node *root){
	
	if(root != NULL){
		displayInorder(root->left);
		printf("%d ",root->data);
		displayInorder(root->right);
	}
}

void displayPostorder(struct Node *root){
	
	if(root != NULL){
		displayPostorder(root->left);
		displayPostorder(root->right);
		printf("%d ",root->data);
	}
}

int countNodes(struct Node *root){
	if(root == NULL){
		return 0;
	}
	return countNodes(root->left) + countNodes(root->right) + 1;
}

int height(struct Node *root){
	if(root == NULL){
		return 0;
	}
	
	int lheight = height(root->left);
	int rheight = height(root->right);
	
	return lheight > rheight ? lheight+1 : rheight+1;
}

int iterativeHeight(struct Node *root){
	if(root == NULL){
		return 0;
	}
	queue<struct Node*> qu;
	qu.push(root);
	
	int h = 0;
	while(true){
		int nc = qu.size();
		if(nc == 0){
			return h;
		}
		++h;
		
		while(nc > 0){
			struct Node *temp = qu.front();
			qu.pop();
			if(temp->left)
				qu.push(temp->left);
			if(temp->right)
				qu.push(temp->right);
			
			--nc;
		}
	}
}

void iterativeLOT(struct Node *root){
	
	if(root == NULL){
		return ;
	}
	queue<struct Node*> qu;
	qu.push(root);
	
	int h = 0;
	while(true){
		int nc = qu.size();
		if(nc == 0){
			return ;
		}
		++h;
		printf("\nNodes at Level%d : ",h);
		while(nc > 0){
			struct Node *temp = qu.front();
			printf(" %d ",temp->data);
			qu.pop();		
			if(temp->left)
				qu.push(temp->left);
			if(temp->right)
				qu.push(temp->right);
			--nc;	
		}
	}
}
void displayGivenLevel(struct Node *root, int l){
	
	if(root != NULL){
		displayGivenLevel(root->left, l-1);
		displayGivenLevel(root->right, l-1);
		
		if(l == 1){
			printf("%d ", root->data);
		}
	}
}

void displayLevelOrder(struct Node *root){
	
	int h = iterativeHeight(root);
	printf("\nLevel Order Traversal : ");
	for(int i = 1; i <= h; i++){
		displayGivenLevel(root, i);
	}
}
//left root right
void iterativeInorder(struct Node *root){
	
	printf("\nIterative Inorder : ");
	if(root){
		stack<struct Node*> st;
		struct Node *curr = root;
		
		while(true){
			//push all leftmost nodes of tree in stack
			if(curr != NULL){
				st.push(curr);
				curr = curr->left;
			}
			else{ //curr == null..when no leftmost nodes present..pop,print,go to right
				if(!st.empty()){
					curr = st.top();
					st.pop();
					printf("%d ",curr->data);
					curr = curr->right;
				}else{
					//stack is empty and curr == null
					break;
				}
			}
		}
	}
}

//inorder traversal without stack and recursion using morris traversal (making threaded binary tree)
//setting right child of a node with its inorder predecessor => node->right = inorder_predecessor
void morrisTraversal(struct Node *root){
	struct Node *curr = root, *predecessor;
	
	if(root){
		printf("\nInorder Traversal using Morris :");
		while(curr){
			
			if(curr->left == NULL){
				//if a node doesn't have left child then inorder=>node,node->right
				//no predessor exists right now..print it
				printf(" %d ",curr->data);
				curr = curr->right;
			}else{
				//if left child is present..then print it first.Find inorder predessor of curr in tree
				//predessor is in left subtree...find rightmost node in left subtree
				//ex : 2 1 3 here predecssor of 3 is 1 and predessor(3) = 1 and right_child(1) = 3
				predecessor = curr->left;
				while(predecessor->right != NULL && predecessor->right != curr)
					predecessor = predecessor->right;
					
				if(predecessor->right == NULL){
					predecessor->right = curr;
					curr = curr->left;
				}else{
					//revert changes made in above if condition
					predecessor->right = NULL;
					printf(" %d ",curr->data);
					curr = curr->right;
				}
			}
		}
	}
}

bool areTreesIdentical(struct Node *root1, struct Node *root2){
	if(root1 == NULL && root2 == NULL){
		return true;
	}else if(root1 && root2)
	return (root1->data == root2->data) && 
		   areTreesIdentical(root1->left, root2->left) &&
		   areTreesIdentical(root1->right, root2->right);
	else//one tree empty and another non-empty
		return false;
}

void _deleteTree(struct Node *root){
	if(root){
		_deleteTree(root->left);
		_deleteTree(root->right);
		
		printf("\nDeleting Node : %d", (root)->data);
		free(root);
	}
}

void deleteTree(struct Node **root){
	_deleteTree(*root);
	*root = NULL;
}

bool isLeaf(struct Node *node){
	return (node->left == NULL && node->right == NULL);
}

void mirror(struct Node *root){
	
	if(root){
		if(root->left){
			mirror(root->left);
		}
		if(root->right){
			mirror(root->right);
		}
		
		struct Node *temp = root->left;
		root->left = root->right;
		root->right = temp;
	
	}
}

void print_root_leaf_path(struct Node *root, int path[], int no){

	if(root == NULL){
		return;
	}
	
	path[no++] = root->data;
	
	if(isLeaf(root)){
		printf("\nPath from Root to %d : ",root->data);
		for(int i = 0; i < no; i++){
			printf(" %d ",path[i]);
		}
	}else{
		print_root_leaf_path(root->left, path, no);
		print_root_leaf_path(root->right, path, no);
	}
}

int countLeaves(struct Node *root){

	if(root){		
		if(isLeaf(root))
			 return 1;
		return countLeaves(root->left) + countLeaves(root->right);	
	}else{
		return 0;
	}
}

//we can't use queue becoz nodes will be enqueued in same order in which their parent are dequeued meaning no spiral possible
void print_lot_spiral(struct Node *root){
	
	stack<struct Node*> left_right;
	stack<struct Node*> right_left;
	
	printf("\nSpiral Level Order Traversal : ");
	left_right.push(root);
	
	while(!left_right.empty() || ! right_left.empty()){
		
		printf("\n");
		while(!left_right.empty()){
			struct Node *item = left_right.top();
			left_right.pop();
			
			if(item->right){
				right_left.push(item->right);
			}
			if(item->left){
				right_left.push(item->left);
			}
			
			printf(" %d ",item->data);
		}
		
		printf("\n");
		while(!right_left.empty()){
			struct Node *item = right_left.top();
			right_left.pop();
			
			if(item->left){
				left_right.push(item->left);
			}
			
			if(item->right){
				left_right.push(item->right);
			}
			
			printf(" %d ",item->data);
		}
	}
}

void printRootToLeafPath(struct Node *root){

	if(root){
		int n = height(root);
		int arr[n] = {0};
		print_root_leaf_path(root,arr,0);
	}
	
}

int check_children_sum(struct Node *root){
	
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return 1;
		
	if(root){
		int left_d = 0, right_d = 0;
		if(root->left){
			left_d = root->left->data;
		}
		if(root->right){
			right_d = root->right->data;
		}
		
		if(root->data == left_d + right_d &&
		  check_children_sum(root->left)  &&
		  check_children_sum(root->right)){
		  	
		  	return 1;
		  }else{
		  	printf("\nNo CS : %d + %d != %d",left_d,right_d,root->data);
		  	return 0;
		  }
	}
	else
		return -1;
}

void increment(struct Node *root, int add){
	
	//since we have incremented root so we have to increment its child also
	root->data += add;
	
	if(root->left){
		increment(root->left,add);
	}else if(root->right){
		increment(root->right,add);
	}
}

void convert_to_children_sum(struct Node *root){
	
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return;
		
	if(root){
		convert_to_children_sum(root->left);
		convert_to_children_sum(root->right);
		
		int left_d = 0, right_d = 0;
		if(root->left){
			left_d = root->left->data;
		}
		if(root->right){
			right_d = root->right->data;
		}
		
		int diff = root->data - (left_d + right_d);
		
		if(diff < 0){
			//since diff < 0 so subtract will be adding
			root->data -= diff;
		}else if(diff > 0){
			if(root->left){
				increment(root->left,diff);
			}else if(root->right){
				printf("\nRoot Right fixed");
				increment(root->right,diff);
			}
		}
	}
}

int _diameter(struct Node *root, int *height){
	
	if(root == NULL){
		*height = 0;
		return 0;
	}
	int lh = 0, rh = 0,ld = 0, rd = 0;
	
	ld = _diameter(root->left,&lh);
	rd = _diameter(root->right,&rh);
	
	*height = max(lh,rh) + 1;
	
	return max(max(ld,rd),lh+rh+1);
}

//Diameter of tree is maximum of three components 
int diameter(struct Node *root){
	
	if(root == NULL){
		return 0;
	}
	int h = 0;
	return _diameter(root,&h);
	//return max(max(diameter(root->left), diameter(root->right)),height(root->left)+height(root->right)+1);
}

bool isHeightBalanced(struct Node *root){
	
	if(root == NULL){
		return true;
	}
	
	int lh = 0,rh = 0;
	if(root->left){
		lh = height(root->left);
	}
	if(root->right){
		rh = height(root->right);
	}
	
	if(abs(lh-rh) <= 1 && isHeightBalanced(root->left) && isHeightBalanced(root->right)){
		return true;
	}else{
		return false;
	}
}

bool isRootLeafPathSum(struct Node *root, int value){
	
	if(root == NULL){
		return value == 0;
	}
	
	if(isLeaf(root)){
		if(value == root->data){
			printf("\nRoot to leaf %d ",root->data);
			return true;
		}else{
			return false;
		}
	}else{
		if(isRootLeafPathSum(root->left, value - (root->data)) || 
		   isRootLeafPathSum(root->right,value - (root->data))){
			return true;
		}else {
			return false;
		}
	}
}

//given preorder and inorder traversals build binary tree
struct Node* _buildTree_inPre(int inorder[], int preorder[], int beg, int end){
	
	if(beg > end){
		return NULL;
	}
	
	static int index = 0;
	struct Node *root = getNewNode(preorder[index++]);
	
	if(beg == end){
		return root;
	}
	
	int i;
	for(i = beg; i <= end; i++){
		if(inorder[i] == root->data){
			break;
		}
	}
	
	root->left = _buildTree_inPre(inorder,preorder,beg,i-1);
	root->right = _buildTree_inPre(inorder,preorder,i+1,end);
	
	return root;
}

struct Node* buildTree_inPre(int inorder[], int preorder[], int size){
	return _buildTree_inPre(inorder,preorder,0,size-1);
}

int countGivenLevel(struct Node *root, int h){
	
	if(root == NULL){
		return 0;
	}
	if(h == 0){
		return 1;
	}	
	return countGivenLevel(root->left,h-1) + countGivenLevel(root->right,h-1);	
}

int getMax(int a[], int size){
	int max = a[0];
	
	for(int i = 1; i < size; i++){
		if(max < a[i]){
			max = a[i];
		}
	}
	return max;
}

void preorder(struct Node *root, int cnt[], int level){
	
	if(root){
		cnt[level]++;
		preorder(root->left,cnt,level+1);
		preorder(root->right,cnt,level+1);
	}
}
//width of tree is maximum no of nodes in any level
int width(struct Node *root){
	
	//Using level order traversal..worst case complexity O(n^2)
	int h = height(root);
	int width = 0;
	/*
	int cnt;
	for(int i = 0; i <= h; i++){
		
		cnt = countGivenLevel(root,i);
		if(width < cnt){
			width = cnt;
		}
	}
	*/
	
	//using preorder traversal...O(n)
	int cnt[h] = {0};
	int level = 0;
	
	preorder(root,cnt,level);
	width = getMax(cnt,h);
	return width;
}

int findLevelOfNode(struct Node *root, int key, int level = 0){
	
	if(root == NULL){
		return 0;
	}
	if(root->data == key){
		return level;
	}
	//out is used to break recursive call and return immediately
	//if we don't use out then it will return 0 even if level of node is greater than 0
	int out = findLevelOfNode(root->left,key,level+1);
	if(out != 0){
		return out;
	}
	out = findLevelOfNode(root->right,key,level+1);
		
	return out;
}

//print ancestors of node : starting from root to key..excluding key..like root to leaf
bool printAncestors(struct Node *root, int key){
	
	if(root == NULL){
		return false;
	}
	
	if(root->data == key){
		return true;
	}
	
	if(printAncestors(root->left,key) || printAncestors(root->right,key)){
		printf(" %d ",root->data);
		return true;
	}
	
	return false;
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

int _largestBstInBT(struct Node* root, int *max, int *min, int *size, bool *isBst){
	
	if(root == NULL){
		*isBst = true;
		return 0 ;
	}
	
	bool isLeftBst = false;
	bool isRightBst = false;
	int cmin = INT_MAX;
	int leftSize,rightSize;
	
	*max = INT_MIN;
	leftSize = _largestBstInBT(root->left,max,min,size,isBst);
	if(isBst && *max < root->data){
		isLeftBst = true;
	}
	
	cmin = *min;
	
	*min = INT_MAX;
	rightSize = _largestBstInBT(root->right,max,min,size,isBst);
	if(isBst && root->data < *min){
		isRightBst = true;
	}
	
	if(cmin < *min){
		*min = cmin;
	}
	if(root->data < *min){
		*min = root->data;
	}
	if(*max < root->data){
		*max = root->data;
	}
	
	if(isLeftBst && isRightBst){
		int temp = leftSize + rightSize + 1;
		if(*size < temp){
			*size = temp;
		}
		return temp;
	}else{
		*isBst = false;
		return 0;
	}
}

int largestBstInBT(struct Node *root){
	
	int max = INT_MIN;
	int min = INT_MAX;
	int size;
	bool isBst = false;
    _largestBstInBT(root,&max,&min,&size,&isBst);
    
    return size;
}

//check if root->data == root->left subtree + root->right subtree
bool isSumTree(struct Node* root){
	
	if(root == NULL || isLeaf(root)){
		return true;
	}
	
	if(isSumTree(root->left) && isSumTree(root->right)){
		
		int lsum = 0;
		if(root->left){
			if(isLeaf(root->left)){
				lsum = root->left->data;
			}else{
				lsum = 2*root->left->data; //Assuming root>left is sum tree..its left subtree will be half of its root's data
			}
		}
		
		int rsum = 0;
		if(root->right){
			if(isLeaf(root->right)){
				rsum = root->right->data;
			}else{
				rsum = 2*root->right->data;
			}
		}
		return root->data == lsum + rsum;
	}
	return false;
}

//connect all the adjacent nodes at the same level in a binary tree
struct SiblingNode{
	int data;
	struct SiblingNode *left,*right,*nextRight;
};

//we will traverse tree in root,nextRight,left order..so that nextRight of nodes at same level is set before setting
//nextRight of left child

struct SiblingNode* newNode(int data){
	struct SiblingNode *temp = (struct SiblingNode*)malloc(sizeof(struct SiblingNode));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}
void connectSiblingsLevel(struct SiblingNode*);
void connectSiblings(struct SiblingNode *root){
	if(root){
		root->nextRight = NULL;
		connectSiblingsLevel(root);
	}
}

struct SiblingNode* getNextRight(struct SiblingNode* root){
	
	struct SiblingNode* temp = root->nextRight;	
	while(temp != NULL){
		if(temp->left){
			return temp->left;
		}else if(temp->right){
			return temp->right;
		}else{
			temp = temp->nextRight;
		}
	}
	return NULL; //if all nodes are leaf nodes..return null
}

void connectSiblingsLevel(struct SiblingNode *root){
	
	if(!root){
		return;
	}
	
	if(root->nextRight != NULL){
		connectSiblingsLevel(root->nextRight);
	}
	
	if(root->left){
		if(root->right){
			root->left->nextRight = root->right;
			root->right->nextRight = getNextRight(root);
		}else{
			root->left->nextRight = getNextRight(root);
		}
		
		connectSiblingsLevel(root->left);
	}else if(root->right){
		root->right->nextRight = getNextRight(root);
		connectSiblingsLevel(root->right);
	}else{
		connectSiblingsLevel(getNextRight(root));
	}
}

//check if small tree is subtree of big tree
bool isSubtree(struct Node *big, struct Node *small){
	
	if(small == NULL){
		return true;
	}
	
	if(big == NULL){
		return false;
	}
	
	if(areTreesIdentical(big,small)){
		return true;
	}
	
	return isSubtree(big->left, small) || isSubtree(big->right, small);	
}

struct InorderNode{
	int data;
	struct InorderNode *left, *right, *inorderSucc;
};

struct InorderNode* newInorderNode(int data){
	struct InorderNode *temp = (struct InorderNode*)malloc(sizeof(struct InorderNode));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

//traverse in reverse inroder fashion...so that all rightmost nodes's succ will be set to null
void populateInorderSucc(struct InorderNode *root){
	static struct InorderNode* nextSucc = NULL;
	
	if(root){
		populateInorderSucc(root->right);
		root->inorderSucc = nextSucc;
		nextSucc = root;
		populateInorderSucc(root->left);
	}
}

//convert a given tree to sum tree..
//resultant tree won't be sum tree....as leaves will be changed to 0
int convertToSumTree(struct Node *root){
	
	if(root == NULL){
		return 0;
	}
	
	int old = root->data;
	root->data = convertToSumTree(root->left) + convertToSumTree(root->right);
	
	return root->data + old; //works for leaves
}

void _verticalSum(struct Node *root, int dist, map<int,int> &hd){
	
	if(root == NULL){
		return;
	}
	
	_verticalSum(root->left,dist-1,hd);
	if(hd.find(dist) == hd.end()){
		hd[dist] = root->data;
	}else{
		hd[dist] += root->data;
	}
	_verticalSum(root->right,dist+1,hd);
}

void printVerticalSum(struct Node *root){
	
	std::map<int,int> hd;
	
	_verticalSum(root, 0 ,hd);
	
	printf("\nPrinting Vertial Sum : ");
	for(std::map<int,int>::iterator it = hd.begin(); it != hd.end(); it++){
		printf(" %d ",it->second);
	}
}

bool isCompleteBT(struct Node *root){
	
	std::queue<struct Node*> qu;
	qu.push(root);
	
	while(!qu.empty()){
		
		struct Node *front = qu.front();
		qu.pop();
		if(front == NULL){
			//Once you have encountered NULL then all following entry in qu should be NULL..if not 
			//then tree is not binary
			break;
		}
		qu.push(front->left);
		qu.push(front->right);
	}
	
	while(!qu.empty()){
		struct Node *front = qu.front();
		qu.pop();
		if(front != NULL){
			return false;
		}
	}
	return true;
}

bool isFullBT(struct Node *root){
	
	if(root == NULL){
		return true;
	}
	
	int cnt = (root->left == NULL ? 0 : 1) + (root->right ==  NULL ? 0 : 1);
	//children should be either 0 or 2
	return cnt != 1 && isFullBT(root->left) && isFullBT(root->right);
}

void printLeaves(struct Node *root){
	
	if(root == NULL){
		return;
	}
	
	printLeaves(root->left);
	if(isLeaf(root)){
		printf(" %d ",root->data);
	}
	printLeaves(root->right);
}

void printBoundaryNodesRight(struct Node *root){
	
	if(root == NULL){
		return;
	}
	
	if(root->right){
		printBoundaryNodesRight(root->right);
		printf(" %d ",root->data);
	}else if(root->left){
		printBoundaryNodesRight(root->left);
		printf(" %d ",root->data);
	}
}
void printBoundaryNodesLeft(struct Node *root){
	
	if(root == NULL){
		return;
	}
	
	if(root->left){
		printf(" %d ",root->data);
		printBoundaryNodesLeft(root->left);
		
	}else if(root->right){
		printf(" %d ",root->data);
		printBoundaryNodesLeft(root->right);
	}
}

//Printing boundary nodes of tree in anti clockwise direction
//print left nodes in top down manner
//print right nodes in bottom up manner
//preint leaves from left to right
void printBoundaryNodes(struct Node *root){
	
	if(root == NULL){
		return;
	}
	
	printf(" %d ",root->data);
	printBoundaryNodesLeft(root->left);
	printLeaves(root->left);
	printLeaves(root->right);
	printBoundaryNodesRight(root->right);
}

void iterativePreorder(struct Node *root){
	
	stack<struct Node*> st;
	st.push(root);
	
	printf("\nIterative Preorder : ");
	while(!st.empty()){
		
		struct Node *temp = st.top();
		printf(" %d ",temp->data);
		st.pop();
		
		if(temp->right){
			st.push(temp->right);
		}
		if(temp->left){
			st.push(temp->left);
		}
	}
}

//Given a a Binary Tree, find the difference between 
//the sum of nodes at odd level and the sum of nodes at even level
int diffOddEvenLevel(struct Node *root){
	
	if(root == NULL){
		return 0;
	}
	
	return root->data - (diffOddEvenLevel(root->left) + diffOddEvenLevel(root->right));
}
//Given Inorder and Preorder traversals of a binary tree, print Postorder traversal.
void postOrderFromInAndPre(int inorder[], int preorder[], int size){
	
	int ind = 0;
	for(ind = 0; ind < size; ind++){
		if(preorder[0] == inorder[ind]){
			break;
		}
	}
	
	if(ind != 0){
		//traverse left subtree
		postOrderFromInAndPre(inorder,preorder+1,ind);
	}
	if(ind != size-1){
		//traverse right subtree
		postOrderFromInAndPre(inorder+ind+1,preorder+ind+1,size-1-ind);
	}
	
	printf(" %d ",preorder[0]);
}

int depthOfDeepestOddLevelLeaf(struct Node *root, int level = 1){
	
	if(root == NULL){
		return 0;
	}
	
	if(isLeaf(root) && (level & 1)){
		return level;
	}
	
	return max(depthOfDeepestOddLevelLeaf(root->left,level+1), depthOfDeepestOddLevelLeaf(root->right,level+1));
}

bool leafLevelSame(struct Node *root, int level = 0){
	
	static int leaflevel = 0;
	if(root == NULL){
		return true;
	}
	if(isLeaf(root)){
		if(leaflevel == 0){
			leaflevel = level;
			return true;
		}else{
			return leaflevel == level;
		}
	}
	
	return leafLevelSame(root->left,level+1) && leafLevelSame(root->right,level+1);
}

void printLeftView(struct Node *root, int level = 1){
	
	static int printedView = 0;
	if(root == NULL){
		return;
	}
	
	if(printedView < level){
		printedView = level;
		printf(" %d ",root->data);
	}
	printLeftView(root->left, level+1);
	printLeftView(root->right, level+1);
}

//Given a binary tree, a complete path is defined as a path from root to a leaf. 
//The sum of all nodes on that path is defined as 
//the sum of that path. Given a number K, you have to remove 
//(prune the tree) all nodes which don’t lie in any path with sum>=k.
struct Node* pruneTree(struct Node *root, int k){
	
	if(root == NULL){
		return NULL;
	}
	
	root->left = pruneTree(root->left, k - root->data);
	root->right = pruneTree(root->right, k - root->data);
	
	if(isLeaf(root) && root->data < k){
		free(root);
		return NULL;
	}
	
	return root;
}

void iterativePostorder(struct Node *root){
	
	stack<struct Node*> st1;
	stack<struct Node*> st2;
	st1.push(root);
	
	while(!st1.empty()){
		struct Node *temp = st1.top();
		st1.pop();
		st2.push(temp);
		
		if(temp->left){
			st1.push(temp->left);
		}
		if(temp->right){
			st1.push(temp->right);
		}
	}
	
	printf("\nIterative Postorder : ");
	while(!st2.empty()){
		printf(" %d ",st2.top()->data);
		st2.pop();
	}
}

void iterativePostorder2(struct Node *root){
	
	stack<struct Node*> st;
	
	printf("\nIterative Postorder using one stack : ");
	do{
		while(root){
			if(root->right){
				st.push(root->right);
			}
			st.push(root);
			
			root = root->left;
		}
		
		root = st.top();
		st.pop();
		
		if(!st.empty() && root->right && st.top() == root->right){
			st.pop();
			st.push(root);
			root = root->right;
		}else{
			printf(" %d ",root->data);
			root = NULL;
		}
	}while(!st.empty());
}

struct Node* deepestLeftLeaf(struct Node *root, int level = 0,bool isLeft = false){
	
	static int max_level = 0;
	static struct Node *result = NULL;
	if(root == NULL){
		return NULL;
	}
	
	if(isLeft && isLeaf(root) && max_level < level){
		max_level = level;
		result = root;
	}
	deepestLeftLeaf(root->left, level+1,true);
	deepestLeftLeaf(root->right,level+1,false);
	
	return result;
}

//Sum of all the numbers that are formed from root to leaf paths
int treeSum(struct Node *root, int val = 0){
	
	if(root == NULL){
		return 0;
	}
	
	val = val*10 + root->data;
	
	if(isLeaf(root)){
		return val;
	}
	
	return treeSum(root->left,val) + treeSum(root->right,val);
}

int main(){
	
	struct Node *root = NULL;
	root = getNewNode(5);
	root->left = getNewNode(4);
	root->right = getNewNode(3);;
	root->left->left = getNewNode(2);
	root->right->left = getNewNode(1);
	
	
	struct Node *root2 = NULL;
	root2 = getNewNode(5);
	root2->left = getNewNode(4);
	root2->right = getNewNode(3);;
	root2->left->left = getNewNode(2);
	root2->right->left = getNewNode(1);
	
	
	printf("\nPostorder : ");
	displayPostorder(root);
	iterativePostorder(root);
	iterativePostorder2(root);
	printf("\nPreorder : ");
	displayPreorder(root);
	printf("\nInorder : ");
	displayInorder(root);
	
	displayLevelOrder(root);
	iterativeLOT(root);
	print_lot_spiral(root);
	iterativeInorder(root);
	morrisTraversal(root);
	
	printf("\nAre trees identical : %d\n", areTreesIdentical(root,root2));
	//deleteTree(&root2);
	mirror(root);
	displayInorder(root);
	
	printRootToLeafPath(root2);
	
	printf("\n#Leaves : %d\n",countLeaves(root));
	
	struct Node *root3 = NULL;
	root3 = getNewNode(10);
	root3->left = getNewNode(8);
	root3->right = getNewNode(1);;
	root3->left->left = getNewNode(3);
	root3->left->right = getNewNode(4);
	root3->right->left = getNewNode(6);
	root3->left->right->left = getNewNode(9);
	root3->left->right->left->right = getNewNode(15);
	
	displayInorder(root3);
	printf("\nChildren Sum Property : %d\n",check_children_sum(root3));
	
	//convert_to_children_sum(root3);
	printf("\nChildren Sum Property : %d\n",check_children_sum(root3));
	displayInorder(root3);
	
	printf("\nDiameter of tree : %d",diameter(root3));
	
	printf("\nHeight Balanced tree : %d",isHeightBalanced(root3));
	
	int sum = 30;
	printf("\nRoot to Leaf path sum %d is %d",sum,isRootLeafPathSum(root3,sum));
	
	int inorder[] = {2,4,5,1,3};
	int preorder[] = {5,4,2,3,1};
	int size = sizeof(inorder)/sizeof(inorder[0]);
	
	struct Node *built = buildTree_inPre(inorder,preorder,size);
	printf("\nInorder for Newly built tree : ");
	displayInorder(built);
	printf("\nPreorder : ");
	displayPreorder(built);
	printf("\nPostorder : ");
	displayPostorder(built);
	displayLevelOrder(built);
	printf("\nAre trees identical : %d\n", areTreesIdentical(root,built));
	
	printf("\nWidth of tree : %d",width(root3));
	
	int key = 15;
	printf("\nLevel of Node %d is %d",key,findLevelOfNode(root3,key));
	
	printf("\nAncestors of %d are : ",key);
	printAncestors(root3,key);
	
	printf("\nIs tree BST : %d",isBst(root3));
	
	{
		printf("\nLrgest BST size : %d",largestBstInBT(root3));
	}
	
	{
		struct Node *root  = getNewNode(26);
    	root->left         = getNewNode(10);
    	root->right        = getNewNode(3);
    	root->left->left   = getNewNode(4);
   		root->left->right  = getNewNode(6);
    	root->right->right = getNewNode(3);
		printf("\nBinary tree is sum tree : %d",isSumTree(root));
		
		convertToSumTree(root3);
		printf("\nBinary tree is sum tree : %d",isSumTree(root));
		displayLevelOrder(root3);
	}
	
	{
		//connect siblings at same level
		struct SiblingNode *root = newNode(10);;
    	root->left        = newNode(8);
    	root->right       = newNode(2);
    	root->left->left  = newNode(3);
    	root->right->right  = newNode(90);
    	
    	connectSiblings(root);
    	printf("\nFollowing are populated nextRight pointers in the tree "
           "(-1 is printed if there is no nextRight) \n");
    	printf("nextRight of %d is %d \n", root->data,
           		root->nextRight? root->nextRight->data: -1);
    	printf("nextRight of %d is %d \n", root->left->data,
           		root->left->nextRight? root->left->nextRight->data: -1);
    	printf("nextRight of %d is %d \n", root->right->data,
           		root->right->nextRight? root->right->nextRight->data: -1);
    	printf("nextRight of %d is %d \n", root->left->left->data,
        	   root->left->left->nextRight? root->left->left->nextRight->data: -1);
    	printf("nextRight of %d is %d \n", root->right->right->data,
        	   root->right->right->nextRight? root->right->right->nextRight->data: -1);
	}
	
	{
		//check if small tree is subtree of big tree
		struct Node *root = NULL;
		root = getNewNode(15);
		root->right = getNewNode(12);
		root->left = getNewNode(1);
		root->right->left = getNewNode(18);
		root->right->left->left = getNewNode(5);
		root->right->left->left->left = getNewNode(4);
		root->right->left->left->right = getNewNode(3);;
		root->right->left->left->left->left = getNewNode(2);
		root->right->left->left->right->left = getNewNode(1);
	
		struct Node *root2 = NULL;
		root2 = getNewNode(5);
		root2->left = getNewNode(4);
		root2->right = getNewNode(3);;
		root2->left->left = getNewNode(2);
		root2->right->left = getNewNode(1);
		
		printf("\nSmall tree is subtree of  big tree : %d",isSubtree(root,root2));
	}
	
	{
		//populate inorder successor of nodes in node's field
		struct InorderNode *root = newInorderNode(10);
		root->left        = newInorderNode(8);
    	root->right       = newInorderNode(12);
    	root->left->left  = newInorderNode(3);
		populateInorderSucc(root);
		
		struct InorderNode *ptr = root->left->left;
    	while(ptr)
    	{
        	// -1 is printed if there is no successor
        	printf("\nNext of %d is %d \n", ptr->data, ptr->inorderSucc? ptr->inorderSucc->data: -1);
        	ptr = ptr->inorderSucc;
    	}
	}
	
	{
		struct Node *root2 = NULL;
		root2 = getNewNode(5);
		root2->left = getNewNode(4);
		root2->right = getNewNode(3);;
		root2->left->left = getNewNode(2);
		root2->right->left = getNewNode(1);
		
		printVerticalSum(root3);
	}
	
	{
		//check whether tree is complete binary tree or not
		struct Node *root2 = NULL;
		root2 = getNewNode(5);
		root2->left = getNewNode(4);
		root2->right = getNewNode(3);;
		//root2->left->left = getNewNode(2);
		root2->right->right = getNewNode(1);
		printf("\nComplete binary tree : %d",isCompleteBT(root2));
	}
	
	{
		struct Node *root2 = NULL;
		root2 = getNewNode(5);
		root2->left = getNewNode(4);
		root2->right = getNewNode(3);;
		//root2->left->left = getNewNode(2);
		//root2->right->right = getNewNode(1);
		printf("\nFull binary tree : %d",isFullBT(root2));
	}
	
	{
		struct Node *root2 = NULL;
		root2 = getNewNode(5);
		root2->left = getNewNode(4);
		root2->left->right = getNewNode(8);
		root2->right = getNewNode(3);;
		root2->left->left = getNewNode(2);
		root2->right->right = getNewNode(1);
		
		printf("\nPrinting Boundary Nodes in anti-clockwise direction : ");
		printBoundaryNodes(root2);
	}
	
	{
		struct Node *root2 = NULL;
		root2 = getNewNode(5);
		root2->left = getNewNode(4);
		root2->left->right = getNewNode(8);
		root2->right = getNewNode(3);;
		root2->left->left = getNewNode(2);
		//root2->right->right = getNewNode(1);
		
		iterativePreorder(root2);
		printf("\nDifference between sum of Odd Level nodes and Even Level nodes : %d",diffOddEvenLevel(root2));
		
		printf("\nDepth of deepest odd level leaf : %d",depthOfDeepestOddLevelLeaf(root2));
		
		printf("\nAll leaf at same level : %d",leafLevelSame(root2));
		
		printf("\nPrinting left View of tree : ");
		printLeftView(root2);
		
	}
	
	{
		int in[] = {4, 2, 5, 1, 3, 6};
		int pre[] = {1, 2, 4, 5, 3, 6};
		int n = sizeof(in)/sizeof(in[0]);
		printf("\nConstructing Postorder : ");
		postOrderFromInAndPre(in,pre,n);
		
	}
	
	{
		int k = 45;
    	struct Node *root = getNewNode(1);
    	root->left = getNewNode(2);
    	root->right = getNewNode(3);
    	root->left->left = getNewNode(4);
    	root->left->right = getNewNode(5);
    	root->right->left = getNewNode(6);
    	root->right->right = getNewNode(7);
    	root->left->left->left = getNewNode(8);
    	root->left->left->right = getNewNode(9);
    	root->left->right->left = getNewNode(12);
    	root->right->right->left = getNewNode(10);
    	root->right->right->left->right = getNewNode(11);
    	root->left->left->right->left = getNewNode(13);
    	root->left->left->right->right = getNewNode(14);
    	root->left->left->right->right->left = getNewNode(15);
 
    	printf("Tree before truncation\n");
    	iterativePreorder(root);
 
    	root = pruneTree(root, k); // k is 45
 
    	printf("\n\nTree after truncation\n");
    	iterativePreorder(root);
	}
	
	{
		Node* root = getNewNode(1);
    	root->left = getNewNode(2);
    	root->right = getNewNode(3);
    	root->left->left = getNewNode(4);
    	root->right->left = getNewNode(5);
    	root->right->right = getNewNode(6);
    	root->right->left->right = getNewNode(7);
    	root->right->right->right = getNewNode(8);
    	root->right->left->right->left = getNewNode(9);
    	root->right->right->right->right = getNewNode(10);
    	
    	struct Node *temp = deepestLeftLeaf(root);
    	printf("\nDeepest left leaf node : %d",temp == NULL ? -1 : temp->data);
	}
	
	{
		struct Node *root = getNewNode(6);
    	root->left        = getNewNode(3);
    	root->right       = getNewNode(5);
    	root->left->left  = getNewNode(2);
    	root->left->right = getNewNode(5);
    	root->right->right = getNewNode(4);
    	root->left->right->left = getNewNode(7);
    	root->left->right->right = getNewNode(4);
    	printf("Sum of all paths is : %d", treeSum(root));
	}
	return 0;
}
