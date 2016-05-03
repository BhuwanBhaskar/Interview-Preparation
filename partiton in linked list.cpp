#include<iostream>
#include<cstdlib>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
void display(ListNode *A)
{
  ListNode *temp = A;
  while(temp)
  {
    cout<<temp->val<<" ";
    temp = temp->next;
  }
  cout<<"\n";
}

 ListNode* partition(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode *left = A;
    
    if(A == NULL || A->next == NULL)
        return A;
    
    ListNode *inb = NULL,*ina = A;
    
    /*ListNode* equal = A;
    while(equal->next != NULL)
    {
        if(equal->val == B)
            break;
        equal = equal->next;
    }
    
    if(equal->val  == B)
        left = equal;
    */
    while(left->next != NULL)
    {
        //cout<<"going on\n";
        if(left->val > B)
            break;
        left = left->next;
        inb = ina;
        ina = ina->next;   
    }
    //cout<<"2going on\n";
    //if(left->next == NULL || left == NULL)
    //    return A;
        
    ListNode *temp = left->next;
    //ina = left->next;
    //cout<<"3going on\n";
    while(temp != NULL)
    {
      //cout<<"leafing\n";
      cout<<"!!going on\n";
        if(temp->val < B)
        {
            //insertAtPos(A,temp->val,pos);
            ////pos++;
            //cout<<"leafing\n";
            ListNode *newNode = new ListNode(temp->val);
            if(inb == NULL)
            {
               // cout<<"ahha\n";
                //inb = newNode;
                newNode->next = ina;
                A = newNode;
                //cout<<"Inserting : "<<ina->val<<ina->next->val<<endl;
            }
            else
            {
               // cout<<"in\n";
                newNode->next = ina;
                inb->next = newNode;
            }
            inb = newNode;
           // cout<<"inb : "<<inb->val<<endl;
            ina = inb->next;
            //cout<<"ina : "<<ina->val<<endl;
            left->next = temp->next;
            free(temp);
            temp = left->next;
           // cout<<"2inb : "<<inb->val<<endl;
        }
        else if(temp->val >= B)
        {
            left = temp;
            temp = temp->next;
            cout<<"!!!leafing\n";
        }
    }
    display(A);
    return A;
}

void insertAtPos(ListNode **A, int val,int pos)
{
    ListNode *newNode = new ListNode(val);
    ListNode *temp = *A,*prev;
    
    if(*A == NULL)
    {
      *A = newNode;
      return;
    }
    
    while(pos-- && temp != NULL)
     {
          prev = temp;
          temp = temp->next;
     }
     newNode->next = temp;
     prev->next = newNode;
}

void swap(ListNode *A)
{
    ListNode *temp1,*temp2,*temp,*prev;
    temp1 = A;
    temp2 = A->next;
    
    if(A == NULL || A->next == NULL)
      return ;
    if(temp2->next == NULL)
    {
          A->next->next = A;
          temp = A->next;
          A->next = NULL;
          A = temp;
          display(A);
          return;
    }
        
    //swap first two elements and change head pointer :)
    
    temp1 = A->next->next;
    A->next->next = A;
    temp = A->next;
    A->next = temp1;
    A = temp;
    
    temp1 = A->next->next;
    temp2 = temp1->next;
    
    prev = A->next; 
    
    while(temp2 != NULL)
    {
        temp = temp2->next;
        {
          temp2->next = prev->next;
          prev->next = temp1->next;
          temp1->next = temp;
        }
        
        cout<<temp1->next<<endl;
        
        prev = temp1;
        temp1 = temp1->next;
        if(temp1 == NULL)
          break;
        temp2 = temp1->next;
    }
    display(A);
}

 int main()
 {
   ListNode *A = NULL;
   insertAtPos(&A,192,0);
   //insertAtPos(&A,186,1);
   //insertAtPos(&A,2,2);
   //insertAtPos(&A,4,3);
//   insertAtPos(&A,130,4);
//   insertAtPos(&A,7,5);
//   insertAtPos(&A,133,6);
   display(A);
   
   //partition(A,7);
   swap(A);
   return 0;
 }
