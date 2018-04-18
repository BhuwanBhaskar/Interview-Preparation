#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stack>
#include<iostream>

using namespace std;

struct Stack{
	int top;
	int capacity;
	char *st;
};

void initialize(struct Stack **stack, int capacity){
	*stack = (struct Stack*)malloc(sizeof(struct Stack));
	((*stack)->st ) = (char*)malloc(sizeof(char)*capacity);
	(*stack)->capacity = capacity;
	(*stack)->top = -1;
	return;
}

void push(struct Stack **stack, char item){
	if((*stack)->capacity <= (*stack)->top + 1){
		printf("\nStack Overflow");
		return;
	}
	(*stack)->st[++((*stack)->top)] = item;
	//printf("\nStack : Pushed item %d at %d",item,((*stack)->top));
	return ;
}

void display(struct Stack *stack){
	
	printf("\nContents of Stack : ");
	for(int i = 0; i <= stack->top; i++){
		printf("%c  ",stack->st[i]);
	}
}

char pop(struct Stack **stack){
	
	if((*stack)->top == -1){
		printf("\nStack Underflow");
		return '#';
	}
	return (*stack)->st[((*stack)->top)--];
}

char peek(struct Stack *stack){
	if((stack)->top == -1){
		printf("\nStack Underflow");
		return '#';
	}
	return (stack)->st[((stack)->top)];
}

bool isEmpty(struct Stack *stack){
	return (stack->top == -1);
}

bool isOperator(char c){
	if(c == '+' || c == '-' || c == '^' || c == '*' || c == '%' || c == '/' || c == '(' || c == ')')
		return true;
		
	return false;
}

int precedence(char op){
	if(op == '+' || op == '-'){
		return 1;
	}else if(op == '*' || op == '/'){
		return 2;
	}else if(op == '^' || op == '%'){
		return 3;
	}else if(op == '('){
		return 0;
	}
}

char* infixToPostfix(char exp[]){
	
	int len = strlen(exp);
	char postfix[len+1];
	char *result;
	struct Stack *opcodes = NULL;
	initialize(&opcodes, (len/2)+1);
	
	int k = 0;
	for(int i = 0; i < len; i++){
		
		if(!isOperator(exp[i])){
			postfix[k++] = exp[i];
			continue;
		}
		//below code will be reachable if character is an operator
		if(isEmpty(opcodes)){
			push(&opcodes, exp[i]);
			continue;
		}
		if(exp[i] == '('){
			push(&opcodes, exp[i]);
		}else if(exp[i] == ')'){
			while(!isEmpty(opcodes) && peek(opcodes) != '('){
				postfix[k++] = pop(&opcodes);
			}
			if(isEmpty(opcodes) && peek(opcodes) != '('){
				return NULL;   // invalid : parenthesis mismatch
			}
			pop(&opcodes);
		}else{
			//this is for normal operators
			while(!isEmpty(opcodes) && precedence(peek(opcodes)) >= precedence(exp[i])){
				postfix[k++] = pop(&opcodes);
			}
			push(&opcodes, exp[i]);
		}
	}
	while(!isEmpty(opcodes)){
		postfix[k++] = pop(&opcodes);
	}
	postfix[k] = '\0';
	
	result = (char*)malloc(sizeof(char)*len + 1);
	strcpy(result, postfix);
	
	return result;
}

double operation(int op1, int op2, char opcode){
	
	switch(opcode){
		case '+' : return op1+op2;
		case '-' : return op2-op1;
		case '*' : return op2*op1;
		case '/' : return op2/op1;
		default  : return -1;
	}
}

double evaluatePostfix(char exp[]){
	int len = strlen(exp);
	double result = 0.00;
	
	struct Stack *operands = NULL;
	initialize(&operands, (len/2)+1);
	
	for(int i = 0; i < len; i++){
		if(isdigit(exp[i])){
			push(&operands, exp[i] - '0');
		}else{
			int op1 = pop(&operands);
			int op2 = pop(&operands);
			result = operation(op1, op2, exp[i]);
			push(&operands, result);
		}
	}
	
	return result;
}

bool isPrenthesis(char c){
	if(c == '(' || c == '{' || c == '[' || c == ')' || c == '}' || c == ']'){
		return true;
	}
	return false;
}

bool isBalancedParenthesis(char exp[]){
	int len = strlen(exp);
	struct Stack *paren = NULL;
	initialize(&paren, len);
	
	int i = 0;
	while(exp[i] != '\0'){
		if(isPrenthesis(exp[i])){
			
			if(isEmpty(paren) && (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')){
				return false;
			}
			
			if(exp[i] == ')' && peek(paren) == '(' || 
			   exp[i] == '}' && peek(paren) == '{' || 
			   exp[i] == ']' && peek(paren) == '['){
				pop(&paren);
			}
			
			else if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
				push(&paren,exp[i]);
			}
				
			else{
					display(paren);
					return false;
			}
		}
		i++;
	}
	
	if(isEmpty(paren)){
		return true;
	}
	
	display(paren);
	return false;
}

void nextGreatestElmt(int arr[], int size){
	stack<int> st;
	
	int next,elmt;
	st.push(arr[0]);
	
	for(int i = 1; i < size; i++){
		next = arr[i];
		
		if(!st.empty()){
			elmt = st.top();
			st.pop();
			while(elmt < next){
				printf("\n%d -> %d",elmt,next);
				if(!st.empty()){
					elmt = st.top();
					st.pop();
				}else if(st.empty()){
					break;
				}
			}
			
			if(elmt > next){
				st.push(elmt);
			}
		}
		
		st.push(next);
	}
	
	while(!st.empty()){
		printf("\n%d -> -1",st.top());
		st.pop();
	}
}

//sortedInsert is same
void insertAtBottom(struct Stack **stack, char temp){
	
	//for sorted insert put a check ( !! peek(*stack) < temp)
	if(isEmpty(*stack)){
		push(stack,temp);
	}else{
		char item = pop(stack);
		insertAtBottom(stack,temp);
		push(stack,item);
	}
}

//reverse stack without using any other stack or loop
//use function call to store item in stack
void reverse(struct Stack **stack){
	char top;
	if(!isEmpty(*stack))
	{
		top = pop(stack);
		reverse(stack);
		
		insertAtBottom(stack,top);
	}
}

void stockSpan(int price[], int n, int span[]){
	stack<int> st;
	//for first item span is 0
	st.push(0);
	span[0] = 0;
	
	for(int i = 1; i < n; i++){
		
		while(!st.empty() && price[i] >= price[st.top()]){
			st.pop();
		}
		
		span[i] = st.empty() ? i+1 : i-st.top();
		
		st.push(i);
	}
}

//Queue using two stack
struct Queue{
	struct Stack *stack1 = NULL;
	struct Stack *stack2 = NULL;
};

void initialize(struct Queue **qu, int capacity){
	*qu = (struct Queue*)malloc(sizeof(struct Queue));
	initialize(&((*qu)->stack1), capacity);
	initialize(&((*qu)->stack2), capacity);
}

//insert item on top of stack..top of stack represents rear of stack
void enqueue(struct Queue **qu, char item){
	push(&((*qu)->stack1),item);
	
	printf("\nPushed !!!");
}

//since top of stack1 is rear...so pop stack1 and push in stack2 then pop from stack2
char dequeue(struct Queue **qu){
	
	if(!isEmpty((*qu)->stack2)){
		return pop(&((*qu)->stack2));
	}
	
	while(!isEmpty((*qu)->stack1)){
		push(&((*qu)->stack2),pop(&((*qu)->stack1)));
	}
	
	return pop(&((*qu)->stack2));
}

char front(struct Queue *qu){
	if(!isEmpty(qu->stack2)){
		return peek(qu->stack2);
	}
	
	while(!isEmpty(qu->stack1)){
		push(&(qu->stack2),pop(&(qu->stack1)));
	}
	
	return peek(qu->stack2);
}

bool isEmpty(struct Queue *qu){
	return isEmpty(qu->stack1);
}

void display(struct Queue *qu){
	display(qu->stack1);
	display(qu->stack2);
}

int main(){
	
	struct Stack *stack= NULL;
	/*
	initialize(&stack, 10);
	
	for(int i = 0; i < 13; i++){
		if(i%2 == 0)
			push(&stack, i);
		else
			printf("popped : %d ",pop(&stack));
		
		printf("\npeeked : %d ",peek(stack));
	}
	
	display(stack);
	*/
	//char *postfix = infixToPostfix("a+b*(c^d-e)^(f+g*h)-i");
	//printf("\nPostfix : %s",postfix);
	//printf("\nPostfix result : %lf", evaluatePostfix("231*+9-"));
	
	//printf("\nParenthesis Balanced : %d",isBalancedParenthesis("{()[]}"));
	
	//int arr[] = {11, 13, 21, 3};
	//nextGreatestElmt(arr,4);
	/*
	initialize(&stack,6);
	
	push(&stack,'b');
	push(&stack,'a');
	push(&stack,'e');
	push(&stack,'d');
	push(&stack,'c');
	
	display(stack);
	
	reverse(&stack);
	
	display(stack);
	*/
	struct Queue *qu = NULL;
	initialize(&qu,4);
	enqueue(&qu,'a');
	enqueue(&qu,'e');
	enqueue(&qu,'f');
	enqueue(&qu,'g');
	enqueue(&qu,'b');
	
	display(qu);
	
	printf("\nDequeued : %c",dequeue(&qu));
	printf("\nDequeued : %c",dequeue(&qu));
	printf("\nDequeued : %c",dequeue(&qu));
	
	printf("\nDequeued : %c",front(qu));
	printf("\nDequeued : %c",dequeue(&qu));
	printf("\nDequeued : %c",dequeue(&qu));
	printf("\nDequeued : %c",dequeue(&qu));
	
	display(qu);
	
	return 0;
}
