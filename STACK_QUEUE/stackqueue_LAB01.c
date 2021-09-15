//////////////////////////////////////////////////////////////////////////////////////////////
/*
#include "stdio.h"
#include <stdlib.h>

//////////////////////////////////   linked list //////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
	int size;
	ListNode *head;
	ListNode *tail;
} LinkedList;

////////////////////////////////// stack    //////////////////////////////////////////////
typedef struct stack{
	LinkedList ll;
} Stack;

//////////////////////////////////// queue ////////////////////////////////////////////

typedef struct _queue{
	LinkedList ll;
} Queue;

////////////////////////////////////////////////////////////////////////////////
void printList(ListNode *head);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

//////////////////////////////////////////////////

void push(Stack *s, int item);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

//////////////////////////////////////////////////

void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int isEmptyQueue(Queue *s);

///////////////////////////////////////////////////////////////
// four questions
void removeUntil(Stack *s, int value);
void recursiveReverse(Queue *q);
int palindrome(char *word);
int balanced(char *expression);

//////////////////////////////////////////////////////////////////
/////

int main()
{
	Stack s;
	Queue q;
	int item[] = { 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1 };
	int i;
	char *word1 = "A man a plan a canal Panama";
	char *word2 = "Superman in the sky";

	//for question 1
	//initialize the stack
	s.ll.head = NULL;
	s.ll.size = 0;
	s.ll.tail = NULL;

	for (i = 0; i<11; i++)
		push(&s, item[i]);

	printList(s.ll.head);
	removeUntil(&s, 5);
	printList(s.ll.head);

	//for question 2
	//initialize the queue
	q.ll.head = NULL;
	q.ll.size = 0;
	q.ll.tail = NULL;

	for (i = 0; i<10; i++)
		enqueue(&q, i);
	printList(q.ll.head);
	recursiveReverse(&q);
	printList(q.ll.head);

	//for question 3
	if (palindrome(word1))
    {
        printf("%s is a palindrome\n", word1);
    }
    else
    {
        printf("%s is not a palindrome\n", word1);
    } //*word1="A man a plan a canal Panama";
    if (palindrome(word2))
    {
        printf("%s is a palindrome\n", word2);
    }
    else
    {
        printf("%s is not a palindrome\n", word2);
    }// *word2="Superman in the sky";

	//for question 4
	if (balanced("()")) printf("not balanced!\n");
	else
		printf("balanced!\n");

	if (balanced("[()]")) printf("not balanced!\n");
	else
		printf("balanced!\n");

	if (balanced("{[]()[]}")) printf("not balanced!\n");
	else
		printf("balanced!\n");

	if (balanced("[({{)])")) printf("not balanced!\n");
	else
		printf("balanced!\n");

	return 0;
}

////////////////////////////////////////////////////////////////
//Question 1

void removeUntil(Stack *s, int value)
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
// Write a function removeUntil() that pops all values off a stack of integers down to but not
// including the first occurrence of the chosen value. The prototype for the removeUntil()
// function is given below:
// void removeUntil(Stack *s, int value);
// Given a stack [1 2 3 4 5 6 5 4 3 2 1] with the topmost number displayed on the left, calling
// removeUntil() with value = 5 will produce the stack [5 6 5 4 3 2 1].
////////////////////////////////
    //ListNode* cur;
    //cur = s->ll.head;
    ////printf("%d\n\n", cur->item); //this works
    //while (cur->item != value)
    //{
    //    cur = cur->next; //IMPT // NEED cur to point to next first before popping else cur will point to nothing
    //    pop(s);
    //    //printf("%d\n", cur->item);
    //    if (cur->item == value)
    //    {
    //        break;
    //    }
    //}
////////////////////////////////
    while(!isEmptyStack(s) && peek(s) != value)
    {
        pop(s);
    }
}

////////////////////////////////////////////////////////////
//Question 2

void recursiveReverse(Queue *q)
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
// Write a recursive function recursiveReverse() that
// reverses the order of items stored in a queue of integers.
// The prototype for the recursiveReverse() function is given below:
// void recursiveReverse(Queue *q);
    //printf("head is %d\n", q->ll.head->item);
    // QUEUE
    // 0 1 2 3 4 5 6 7 8 9
    // ^
    // HEAD

////////////////////////////////
    //create a stack to store the numbers
    Stack stackk;
    stackk.ll.head = NULL;
    stackk.ll.size = 0;

    //for every element in the queue starting from 0...
    ListNode* queuePtr = q->ll.head;
    while (queuePtr != NULL)
    {
        push(&stackk, queuePtr->item);
        queuePtr = queuePtr->next;
        dequeue(q);
    }
    //printf("lmao");
    //printList(stackk.ll.head);
    //printf("lolol");
    //printList(q->ll.head);
    //printf("\nend\n");

    //now, the stack contains 9 at the top, then 8,7,6...
    //for every element in the stack starting from 9...
    ListNode* stackkPtr = stackk.ll.head;
    while (stackkPtr != NULL)
    {
        //printf("%d", stackkPtr->item);
        enqueue(q, stackkPtr->item);
        stackkPtr = stackkPtr->next;
    }

    //delete the created stack
    while (!isEmptyStack(&stackk))
    {
        pop(&stackk);
    }
////////////////////////////////
	int i;

	if (isEmptyQueue(q))
		return;

	 i = dequeue(q);
	 recursiveReverse(q);
	 enqueue(q, i);
}

////////////////////////////////////////////////////////////
//Question 3

int palindrome(char *word)
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
// Write a function palindrome() that determines whether a given string is a palindrome.
// The prototype for the palindrome() function is given below:
// int palindrome(char *word);
// The function should return 0 if the string is a palindrome and -1 otherwise. You should ignore
// the null terminator. Ignore the case of each letter.
// Sample output:
// Enter a string: A man a plan a canal Panama
// The string is a palindrome.
// Enter a string: Superman in the sky
// The string is not a palindrome.

    //parse the string to only small alphabets and put into a queue
    Stack s_parsedWord;
    s_parsedWord.ll.head = NULL;
    s_parsedWord.ll.size = 0;

    for (int i = 0; i<strlen(word); i++)
    {
        if ( isalpha(word[i]) || isdigit(word[i]) )
        {
            //printf("%d ", tolower(word[i]));
            push(&s_parsedWord, tolower(word[i]));
        }
    }
    //parsedWord now contains the alphabets (as numbers) in a queue.

    // r a c e c a r --> take the first half and put into a stack to get r a c
    //create a stack to store the first half
    Stack s_firstHalf;
    s_firstHalf.ll.head = NULL;
    s_firstHalf.ll.size = 0;

    ListNode* cur = s_parsedWord.ll.head;
    printf("full q_parsedWord");printList(cur);printf("\n");
    int wordLen = s_parsedWord.ll.size;
    for (int i = 0; i < wordLen/2; i++)
    {
        push(&s_firstHalf, pop(&s_parsedWord));
    }

    // c a c    --> if length is odd, ignore the centre
    // c o o c  --> if length is even, make sure first half == second half
    if (wordLen % 2 != 0)
    {
        pop(&s_parsedWord);
    }

    //printf("s_firstHalf ");printList(s_firstHalf.ll.head);printf("\n");
    //printf("q_parsedWord ");printList(q_parsedWord.ll.head);printf("\n");

    //pop the s_firstHalf and dequeue the q_parsedWord and compare char-by-char
    for (int i = 0; i< wordLen/2; i++)
    {
        if (pop(&s_firstHalf) != pop(&s_parsedWord))
        {
            return 0;
        }
    }
    return 1;
}

////////////////////////////////////////////////////////////
//Question 4

int balanced(char *expression)
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
// Write a function balanced() that determines if an expression
// comprised of the characters ()[]{} is balanced.
// The prototype for the balanced() function is given below:
// int balanced(char *expression);
// The following expressions are balanced because the order and
// quantity of the parentheses match:
// ()
// ([])
// {[]()[]}
// The following expressions are not balanced:
// {{)]
// [({{)])
///////////////////////////
    char* wordd = malloc(sizeof(strlen(expression)));
    wordd[strlen(expression)] = '\0';

    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] == '(' || expression[i] == ')')
        {
            wordd[i] = 'A';
        }

        else if (expression[i] == '[' || expression[i] == ']')
        {
            wordd[i] = 'B';
        }

        else if (expression[i] == '{' || expression[i] == '}')
        {
            wordd[i] = 'C';
        }
    }
    return !palindrome(wordd);
/////////////////////////////////
    //Stack s;
    //s.ll.head = NULL;
    //s.ll.tail = NULL;
    //s.ll.size = 0;

    //printf("%s\n", expression);

    //while (*expression)
    //{
    //    if (*expression == '(' || *expression == '[' || *expression == '{')
    //    {
    //        push(&s, *expression);
    //    }
    //    else if (*expression == ')')
    //    {
    //        if (isEmptyStack(&s) || pop(&s) != '(')
    //        return -1;
    //    }
    //    else if (*expression == ']')
    //    {
    //        if (isEmptyStack(&s) || pop(&s) != '[')
    //        return -1;
    //    }
    //    else if (*expression == '}')
    //    {
    //        if (isEmptyStack(&s) || pop(&s) != '{')
    //        return -1 ;
    //    }
    //    expression++;
	//}

	//if (isEmptyStack(&s)) return 0;
	//else return -1;
/////////////////////////////////
}

////////////////////////////////////////////////////////////////////////////////

void push(Stack *s, int item){
	insertNode(&(s->ll), 0, item);
}

int pop(Stack *s){
	int item;

	item = ((s->ll).head)->item;
	removeNode(&(s->ll), 0);
	return item;
}

int peek(Stack *s){
	return ((s->ll).head)->item;
}

int isEmptyStack(Stack *s){
	if ((s->ll).size == 0)
		return 1;
	return 0;
}


////////////////////////////////////////////////////////////////////////////////

void enqueue(Queue *q, int item){
	insertNode(&(q->ll), q->ll.size, item);
}

int dequeue(Queue *q){
	int item;
	item = ((q->ll).head)->item;
	removeNode(&(q->ll), 0);
	return item;
}

int isEmptyQueue(Queue *q){
	if ((q->ll).size == 0)
		return 1;
	return 0;
}



////////////////////////////////////////////////////////////////////////////////

void printList(ListNode *head){

	ListNode *temp = head;

	if (temp == NULL)
		return;

	while (temp != NULL){
		printf("%d ", temp->item);
		temp = temp->next;
	}
	printf("\n");
}

ListNode * findNode(LinkedList *ll, int index){

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->tail = ll->head;
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}

	// Inserting as new last node
	if (index == ll->size){
		pre = ll->tail;
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		ll->tail = pre->next;
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));

		if (index == ll->size)
			ll->tail = pre->next;

		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}

int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		if (ll->size == 0)
			ll->tail = 0;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){

		// Removing the last node, update the tail pointer
		if (index == ll->size - 1){
			ll->tail = pre;
			free(pre->next);
			pre->next = NULL;
		}
		else{
			cur = pre->next->next;
			free(pre->next);
			pre->next = cur;
		}
		ll->size--;
		return 0;
	}

	return -1;
}
//*/
