#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
}node;

Node* getNewNode(int data){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->next = NULL;
	temp->data = data;
	
	return temp;
}

void printIt(struct Node* curr){
	
	printf("\n");
	while(curr != NULL){
		printf("%d\t", curr->data);
		curr = curr->next;
	}
}

void insertAtPos(struct Node** ll, int data, int pos){
	
	if(*ll == NULL){
		*ll = getNewNode(data);
	}
	else{
		struct Node* temp = getNewNode(data);
		if(pos == 0){
			//insert At head of ll
			temp->next = (*ll);
			*ll = temp;
			return;
		}
		
		struct Node* prevNode = NULL;
		struct Node* nextNode = *ll;
		while(pos >= 1 && nextNode != NULL){
			--pos;
			prevNode = nextNode;
			nextNode = nextNode->next;
		}
		if(nextNode != NULL){
			temp->next = prevNode->next;
			prevNode->next = temp;
		}else if(nextNode == NULL && pos >= 0){
			//insert at end of ll
			prevNode->next = temp;
		}
		//printf("\nInsert : ");
		//printIt(*ll);
	}
	return;
}

int deleteAtPos(struct Node** ll, int pos){
	int del;
	
	if(*ll == NULL){
		printf("\nNothing to delete from !!!");
	}
	
	struct Node* curr = *ll;
	struct Node* prevNode = NULL;
	
	if(pos == 0){
		//delete head node
		*ll = curr->next;
		del = curr->data;
		printf("\nDeleting : %d",del);
		free(curr);
		printIt(*ll);
		return del;
	}
	while(pos >= 1 && curr->next != NULL){
		prevNode = curr;
		curr = curr->next;
		--pos;
	}
	if(pos > 0){
		printf("\nKey does not exist : %d \n",pos);
		return -1;
	}
	del = curr->data;
	printf("\nDeleting : %d",del);
	if(curr->next == NULL && pos <= 1){
		//Deleting last node
		prevNode->next = NULL;	
		free(curr);
		printIt(*ll);
		return del;
	}
	prevNode->next = curr->next;
	free(curr);
	printf("\nDelete : ");
	printIt(*ll);
	return del;
}

void swapNodes(struct Node** ll, int key1, int key2){
	
	if(*ll == NULL){
		printf("\nEmpty linked list..key not found!!");
		return;
	}else if(key1 == key2){
		printf("\nNothing to swap...keys are same!!!");
		return;
	}
	//find key1 and key2...no duplicates should be present
	struct Node *prevKey1 = NULL, *prevKey2 = NULL, *curr = *ll, *prev = NULL, *temp;
	struct Node *currKey1 = *ll, *currKey2 = *ll;
	
	while(curr != NULL){
		if(curr->data == key1){
			currKey1 = curr;
			prevKey1 = prev;
		}else if(curr->data == key2){
			currKey2 = curr;
			prevKey2 = prev;
		}
		prev = curr;
		curr = curr->next;
	}
	
	if(currKey1->data != key1 || currKey2->data != key2){
		printf("\nKey(s) is/are not present");
		return;
	}
	
	//what if one of key is head of ll ?
	//we need  to make another key as head
	
	//prevKey1 is not head
	if(prevKey1 != NULL){
		prevKey1->next = currKey2;
	}else{
		//currKey1 is head ...
		(*ll) = currKey2;
	}
	
	if(prevKey2 != NULL){
		prevKey2->next = currKey1;
	}else{
		(*ll) = currKey1;
	}
	
	temp = currKey2->next;
	currKey2->next = currKey1->next;
	currKey1->next = temp;
	
	 printf("\nSwapped : ");
	 printIt(*ll);
	 return;
}

void reverseList(struct Node** ll){
	
	struct Node *curr = *ll, *prev = NULL, *temp;
	
	while(curr != NULL){
		temp = prev;
		prev = curr;
		curr = curr->next;
		prev->next = temp;
	}
	
	*ll = prev;
	printIt(*ll);
}

void recReverseList(struct Node** ll){
	
	if(*ll == NULL)
		return;
		
	struct Node *first = *ll, *rest = (*ll)->next;
	if(rest == NULL)
		return;
		
	recReverseList(&rest);
	
	first->next->next = first;
	first->next = NULL;
	
	*ll = rest;
}

int lengthOfList(struct Node* ll){
	
	int len = 0;
	while(ll != NULL){
		len++;
		ll = ll->next;
	}
	
	printf("\nLength of list is : %d",len);
	return len;
}

int recLengthOfList(struct Node* ll){
	
	if(ll != NULL){
		return 1 + recLengthOfList(ll->next);
	}
	
}

struct Node* sortedMerge(struct Node* ll1, struct Node* ll2){
	
	if(ll1 == NULL && ll2 == NULL){
		return NULL;
	}
	else if(ll1 == NULL){
		return ll2;
	}else if(ll2 == NULL){
		return ll1;
	}
	
	int pos = 0;
	struct Node *mergedList = NULL;
	struct Node *mv_ll1 = ll1, *mv_ll2 = ll2;
	
	while(mv_ll1 != NULL && mv_ll2 != NULL){
		
		if(mv_ll1->data < mv_ll2->data){
			insertAtPos(&mergedList, mv_ll1->data, pos++);
			mv_ll1 = mv_ll1 -> next;
		}else{
			insertAtPos(&mergedList, mv_ll2->data, pos++);
			mv_ll2 = mv_ll2->next;
		}
	}
	
	while(mv_ll1 != NULL){
		insertAtPos(&mergedList, mv_ll1->data, pos++);
		mv_ll1 = mv_ll1->next;
	}
	while(mv_ll2 != NULL){
		insertAtPos(&mergedList, mv_ll2->data, pos++);
		mv_ll2 = mv_ll2->next;
	}
	
	printf("\nMerged List is : length : %d" , pos);
	printIt(mergedList);
	return mergedList;
}

void bisectList(struct Node *ll, struct Node **fh, struct Node **sh){
	//using fast and slow pointer
	
	if(ll == NULL || ll->next == NULL){
		*fh = ll;
		*sh = NULL;
		return;
	}
		
	struct Node *fast = ll->next;
	struct Node *slow = ll;
	
	while(fast != NULL){
		fast = fast->next;
		
		if(fast != NULL){
			slow = slow->next;
			fast = fast->next;
		}
	}
	
	*sh = slow->next;
	*fh = ll;
	slow->next = NULL;
	
}

void mergeSort(struct Node** ll){
	
	if(*ll == NULL || ((*ll)->next == NULL)){
		return;
	}
	
	struct Node *first_half, *second_half;
	bisectList(*ll, &first_half, &second_half);
	
	printIt(first_half);
	printIt(second_half);
	mergeSort(&first_half);
	mergeSort(&second_half);
	
	*ll = sortedMerge(first_half,second_half);
	printIt(*ll);
}

void mergeLists(){
	
	printf("\nChecking merging of two lists : ");
	struct Node *ll1 = NULL, *ll2 = NULL;
	printIt(sortedMerge(ll1,ll2));
	
	insertAtPos(&ll1, 1, 0);
	insertAtPos(&ll1, 8, 1);
	insertAtPos(&ll1, 12, 2);
	insertAtPos(&ll1, 14, 3);
	printIt(sortedMerge(ll1,ll2));
	
	insertAtPos(&ll2, 3, 0);
	insertAtPos(&ll2, 6, 1);
	insertAtPos(&ll2, 10, 2);
	sortedMerge(ll1,ll2);
	
}

void reverseInGroup(struct Node **ll, int k){
	
	struct Node *curr = *ll,*tail = NULL;
	
	while(curr != NULL){
		
		struct Node *temp = curr;
		for(int i = 1; temp->next != NULL && i < k; i++){
			temp = temp->next;
		}
		
		struct Node *saveNext = temp->next;
		temp->next = NULL;
		
		reverseList(&curr);    //it reverses from curr till temp (after that list ends (null).
		
		if(tail == NULL){
			//update head of list first time...
			*ll = curr;
		}else{
			//link previous list's tail node to head node of current list..increasing size
			tail->next = curr;
		}
		
		//find tail of current list so that it can be linked to head of upcoming lists
		struct Node *tcurr = curr;
		while(tcurr->next != NULL){
			tcurr = tcurr->next;
		}
		tail = tcurr;		
		curr = saveNext;
	}
	
	printf("\nReversing in groups : ");
	printIt(*ll);
}

int removeLoop(struct Node **ll, struct Node* loop){
	
	struct Node *curr = *ll, *tempLoop;
	
	while(true){
		
		tempLoop = loop;
		if(tempLoop->next != loop && tempLoop != curr){
			printf("\n Loop elmts : %d",tempLoop->data);
			tempLoop = tempLoop->next;
		}
		
		if(tempLoop == curr){
			printf("\n Head of Loop : %d", curr->data);
			break;
		}
		
		curr = curr->next;
	}
	
	tempLoop->next = NULL;
}

int isLoopPresent(struct Node* ll){
	//will use fast and slow pointer
	struct Node *fast, *slow;
	slow = ll, fast = ll;
	
	while(fast != NULL){
		fast = fast->next;
		if(fast != NULL){
			slow = slow->next;
			fast = fast->next;
		}
		
		if(fast == slow){
			printf("\nLoop is present in Linked List\n");
			removeLoop(&ll, fast);
			return 1;
		}
	}
	printf("\nLoop is not present in Linked List\n");
	return 0;
}

void testLoop(){
	
	struct Node *ll = NULL;
	insertAtPos(&ll,1,4);
	insertAtPos(&ll,2,4);
	insertAtPos(&ll,3,4);
	insertAtPos(&ll,4,4);
	insertAtPos(&ll,5,4);
	insertAtPos(&ll,6,4);
	
	printIt(ll);
	isLoopPresent(ll);
	ll->next->next->next->next = ll->next->next;
	isLoopPresent(ll);
	printIt(ll);
}

void deleteLeadingZeroes(struct Node **ll){
	struct Node *temp = *ll;
	while(temp->data == 0){
		deleteAtPos(ll, 0);
		//printf("del");
	}
}

struct Node* sum(struct Node *fl, struct Node *sl){
	struct Node *summed = NULL;
	
	//before reversing ..we need to remove leading zero nodes occurring at beginning of list.
	deleteLeadingZeroes(&fl);
	deleteLeadingZeroes(&sl);
	
	reverseList(&fl);
	reverseList(&sl);
	
	int carry = 0;
	struct Node *ftemp = fl, *stemp = sl;
	while(ftemp || stemp){
		if(ftemp && stemp){
			int val = (ftemp->data + stemp->data + carry)%10;
			carry = (ftemp->data + stemp->data + carry)/10;
			
			insertAtPos(&summed, val, 0);
			
			ftemp = ftemp->next;
			stemp = stemp->next;
		}
		else if(ftemp){
			int val = (ftemp->data + carry)%10;
			carry = (ftemp->data + carry)/10;
			
			insertAtPos(&summed, val, 0);
			ftemp = ftemp->next;
		}
		else{
			int val = (stemp->data + carry)%10;
			carry = (stemp->data + carry)/10;
			
			insertAtPos(&summed, val, 0);
			stemp = stemp->next;
		}
	}
	//reverseList(&summed);
	
	return summed;
}

//we have assumed that number will be presented as : ex 765 (normal decimal form) ==> 7=>6=>5=>null (linked list)
void sumLists(){
	printf("\nChecking Sum of two lists : ");
	struct Node *ll1 = NULL, *ll2 = NULL;
	int i = -1;
	insertAtPos(&ll1, 7, ++i);
	insertAtPos(&ll1, 5, ++i);
	insertAtPos(&ll1, 9, ++i);
	insertAtPos(&ll1, 4, ++i);
	insertAtPos(&ll1, 6, ++i);
	printIt(ll1);
	
	int j = -1;
	insertAtPos(&ll2, 8, ++j);
	insertAtPos(&ll2, 4, ++j);
	printIt(ll2);
	
	struct Node *result = sum(ll1, ll2);
	printIt(result);
}

//ex : 10=>20=>30=>40 then if k = 2 , 30=>40=>10=>20
void rotateCounterClock(struct Node **ll, int k){
	
	struct Node *spart = *ll, *temp = *ll, *ptemp = NULL;
	while(temp != NULL && k != 0){
		k--;
		ptemp = temp;
		temp = temp->next;
	}
	if(temp == NULL){
		if(k == 0){
			reverseList(ll);
		}
		printIt(*ll);
		return;
	}
	
	ptemp->next = NULL;
	spart = temp;
	while(temp->next != NULL)
		temp = temp->next;
		
	temp->next = (*ll);
	(*ll) = spart;
	
	printIt(*ll);
	return;
}

void deleteList(struct Node **ll){
	
	struct Node *Next = (*ll);
	
	printf("\nDeleting List : ");
	while(*ll != NULL ){
		Next = (*ll)->next;
		printf("%d ", (*ll)->data);
		free(*ll);
		*ll = Next;
	}
	*ll = NULL;
}

void insertSorted(struct Node **ll, int item){
	
	struct Node *newNode = getNewNode(item);
	if(*ll == NULL){
		printf("\nList is empty..inserting at head");
		*ll = newNode;
		return;
	}
	//if head is to be changed ?
	if(item < (*ll)->data){
		newNode->next = (*ll);
		*ll = newNode;
		return;
	}
	
	struct Node *currNode = *ll, *prevNode = NULL;
	while(currNode && currNode->data <= item){
		prevNode = currNode;
		currNode =currNode->next;
	}
	
	if(prevNode){
		newNode->next = prevNode->next;
		prevNode->next = newNode;
	}
}

int deletePointer(struct Node *ptr){
	
	// we don't have any info about head of list or previous pointer of given node
	// so we copy data from next of given ptr to ptr and delete next of ptr
	//won't be able to delete last node :)
	if(ptr && ptr->next){
		struct Node *temp = ptr->next;
		int del = ptr->data;
		ptr->data = temp->data;
		ptr->next = temp->next;
		free(temp);
		
		return del;
	}
}

//this will mutate list : list will be first half after end of this function
bool isPalindrome(struct Node *ll){
	struct Node *first_half, *second_half;
	bisectList(ll, &first_half, &second_half);
	reverseList(&second_half);
	
	//if list is even then while loop will execute and return correct result
	while(first_half && second_half ){
		
		if(first_half->data == second_half->data){
			first_half = first_half->next;
			second_half = second_half->next;
		}
		else{
			printf("\nDidn't match : %d and %d",first_half->data, second_half->data);
			return false;
		}
	}
	//list is odd...one elmt remain in either first half or second half
	//if extra elmt is in first half then list becomes palindrome else no
	if(lengthOfList(first_half) < lengthOfList(second_half))
		return false;
	return true;
}

int findIntersecionPoint(struct Node *list1, struct Node *list2){
	
	int n1 = lengthOfList(list1);
	int n2 = lengthOfList(list2);
	
	int diff = n1-n2;
	
	struct Node *large,*small;
	if(diff >= 0){
		large = list1;
		small = list2;
	}else{
		large = list2;
		small = list1;
	}
	
	while(diff){
		large = large->next;
		diff--;
	}
	
	while(small->data != large->data){
		small = small->next;
		large = large->next;
	}
	
	return small->data;
}

void printReverseOfList(struct Node *list){
	
	if(list == NULL){
		return;
	}
	printReverseOfList(list->next);
	printf(" %d ",list->data);
}

void removeDupsInSorted(struct Node *list){
	
	struct Node *curr = list;
	while(curr != NULL){
		if(curr->data == curr->next->data){
			struct Node *temp = curr->next;
			curr->next = temp->next;
			printf("\nDeleting Dups : %d",temp->data);
			free(temp);
		}
		curr = curr->next;
	}
}

void swapPairWise(struct Node **list){
	//swap nodes of list in pair ex 10->20->30->40->50  ==> 20->10->40->30->50
	struct Node *curr = *list,*nextCurr, *prevCurr = *list;
	
	while(curr !=  NULL && curr->next != NULL){
		//swap curr and curr->next	
		nextCurr = curr->next;
		printf("\nSwapping : %d and %d",curr->data,nextCurr->data);
		
		if(*list == curr){
			*list = nextCurr;
		}
		
		prevCurr->next = nextCurr;
		curr->next = nextCurr->next;
		nextCurr->next = curr;
		
		prevCurr = curr;
		curr = curr->next;
	}
}

void move_last_to_first(struct Node **list){
	
	struct Node *temp = *list,*prev;
	while(temp->next){
		prev = temp;
		temp = temp->next;
	}
	printf("\nSwapping first with last : %d and %d",temp->data,(*list)->data);
	temp->next = (*list)->next;
	prev->next = *list;
	prev->next->next = NULL;
	*list = temp;
	
}

struct Node* intersection_two_lists(struct Node *list1, struct Node *list2){
	
	struct Node *curr1 = list1, *curr2 = list2, *curr3 = NULL;
	struct Node *result = NULL;
	while(curr1 != NULL && curr2 != NULL){
	
		//printf("\ncurr1 : %d and curr2 : %d",curr1->data,curr2->data);
		if(curr1->data == curr2->data){
			struct Node *newNode = getNewNode(curr1->data);
			if(result == NULL){
				//printf("\nadding first node : %d",newNode->data);
				result = newNode;
				curr3 = result;
			}else{
				curr3->next = newNode;
				curr3 = newNode;
				//printf("\nadding  node : %d",curr3->data);
			}
			curr1 = curr1->next;
			curr2 = curr2->next;
		}else if(curr1->data < curr2->data){
			curr1 = curr1->next;
		}else{
			curr2 = curr2->next;
		}
	}
	//printIt(result);
	return result;
}

void testing(){
		/*
	struct Node* ll = NULL;
	
	insertAtPos(&ll, 1, 3);
	printf("\nrec Length of List : %d",recLengthOfList(ll));
	insertAtPos(&ll, 4, 0);
	insertAtPos(&ll, 2, 1);
	insertAtPos(&ll, 3, 1);
	deleteAtPos(&ll, 0);
	printf("\nrec Length of List : %d",recLengthOfList(ll));
	insertAtPos(&ll, 6, 2);
	insertAtPos(&ll, 5, 1);
	deleteAtPos(&ll, 4);
	insertAtPos(&ll, 7, 3);
	insertAtPos(&ll, 8, 2);
	deleteAtPos(&ll, 2);
	insertAtPos(&ll, 88, 7);
	deleteAtPos(&ll, 6);
	printIt(ll);
	swapNodes(&ll, 5,7);
	swapNodes(&ll, 3,88);
	swapNodes(&ll, 7,88);
	reverseList(&ll);
	recReverseList(&ll);
	lengthOfList(ll);
	printf("\nrec Length of List : %d",recLengthOfList(ll));
	printIt(ll);
	
	mergeSort(&ll);
	
	//mergeLists();
	
	reverseInGroup(&ll,2);
	testLoop();
	
	sumLists();
	
	printIt(ll);
	rotateCounterClock(&ll, 6);
	
	deleteList(&ll);
	*/
	
	/*
	struct Node *sorted = NULL;
	insertSorted(&sorted, 5);
	insertSorted(&sorted, 1);
	insertSorted(&sorted, 4);
	insertSorted(&sorted, 6);
	insertSorted(&sorted, 3);
	insertSorted(&sorted, 2);
	printIt(sorted);
	
	printf("\nPointer deleted : %d",deletePointer(sorted->next->next));
	printIt(sorted);
	*/
	
	/*
	struct Node *palindrome = NULL;
	insertAtPos(&palindrome, 3, 1);
	insertAtPos(&palindrome, 2, 2);
	insertAtPos(&palindrome, 1, 3);
	insertAtPos(&palindrome, 1, 5);
	insertAtPos(&palindrome, 2, 6);
	insertAtPos(&palindrome, 3, 7);
	insertAtPos(&palindrome, 4, 4);
	printIt(palindrome);
	printf("\nPalindrome : %d",isPalindrome(palindrome));
	printIt(palindrome);
	*/
}

int main(){
	

	//intersection of two list
	struct Node *list1 = NULL;
	struct Node *list2 = NULL;
	insertAtPos(&list1, 1, 1);
	insertAtPos(&list1, 3, 2);
	insertAtPos(&list1, 5, 3);
	insertAtPos(&list1, 7, 4);
	insertAtPos(&list1, 9, 5);
	insertAtPos(&list1, 11,6);
	insertAtPos(&list1, 13,7);
	insertAtPos(&list1, 15,8);
	insertAtPos(&list1, 17,9);
	insertAtPos(&list1, 19,10);
	insertAtPos(&list1, 21,11);
	insertAtPos(&list1, 23,12);
	insertAtPos(&list1, 25,13);
	printIt(list1);
	
	insertAtPos(&list2, 1, 1);
	insertAtPos(&list2, 3, 2);
	insertAtPos(&list2, 5, 3);
	insertAtPos(&list2, 7, 5);
	insertAtPos(&list2, 11, 6);
	insertAtPos(&list2, 13, 7);
	insertAtPos(&list2, 17, 8);
	insertAtPos(&list2, 19, 9);
	insertAtPos(&list2, 23, 10);
	insertAtPos(&list2, 29, 11);

	
	printIt(list2);
	
	/*
	list2->next->next->next->next = list1->next->next->next->next->next;
	printIt(list2);
	
	
	printf("\nIntersection Point of two list : %d",findIntersecionPoint(list1,list2));
	
	printf("\nPrinting Reverse of List : ");
	printReverseOfList(list1);
	
	insertAtPos(&list1, 9,5);
	insertAtPos(&list1, 3,2);
	insertAtPos(&list1, 1,1);
	insertAtPos(&list1, 17,20);
	
	printIt(list1);
	removeDupsInSorted(list1);
	printIt(list1);
	
	swapPairWise(&list2);
	printIt(list2);
	
	printf("\n\n");
	printIt(list2);
	move_last_to_first(&list2);
	printIt(list2);
	*/
	//intersection_two_lists(list1,list2);
	printIt(intersection_two_lists(list1,list2));
	return 0;
}
