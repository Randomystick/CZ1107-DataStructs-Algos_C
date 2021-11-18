#include <stdio.h>
#include <stdlib.h>

#define SIZE 80 //The size of the array

enum ExpType {OPT,OPERAND};

typedef struct _stackNode{
    char item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

typedef struct _listnode
{
    int  item;
    enum ExpType type;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} LinkedList;

void insertNode(LinkedList *llPtr, int item,enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList (LinkedList ll);

void in2PreLL(char* infix, LinkedList *inExpLL);

void printExpLL(LinkedList inExpLL);

// For Assignment
#include <ctype.h>
#include <string.h>
int IsOperator(char _c);
int operatorCheck(char _c);

int main()
{
    char infix[SIZE];

    printf("Enter an infix expression:\n");
    gets(infix);

    LinkedList inExpLL;
    inExpLL.head = NULL;
    inExpLL.size = 0;

    in2PreLL(infix, &inExpLL);

    printExpLL(inExpLL);

    removeAllNodes(&inExpLL);
    return 0;
}

void in2PreLL(char* infix, LinkedList *inExpLL)
{
    Stack s;
    s.size = 0;
    s.head = NULL;

    char* infixIndex = infix + strlen(infix) - 1; //the last char

    while (infixIndex >= infix) //iterate through all the chars, starting from back
    {
        if(isdigit((*infixIndex))) //if c is operand, put it into output string
        {
            int numDigit = 1;
            int digitToAdd = 0;

            while(isdigit((*infixIndex)))
            {
                digitToAdd += numDigit * ((*infixIndex) - '0');
                numDigit *= 10;
                --infixIndex;
            }

            insertNode(inExpLL, digitToAdd, OPERAND);
            continue;
        }

        else if((*infixIndex) == ')') //if c is opening (closing cuz reading in reverse) brace, push it into tempStack
        {
            push(&s,(*infixIndex));
        }

        else if((*infixIndex) == '(')  //if c is closing brace (again opening cuz reversed)
        {
            while(!isEmptyStack(s) && peek(s) != ')')
            {
                //move all operators from tempStack into output string
                insertNode(inExpLL, peek(s), OPT);
                pop(&s);
            }
            pop(&s); //remove opening brace (closing)
        }

        else //an operator
        {
            while(!isEmptyStack(s) && operatorCheck(peek(s)) != 61 && operatorCheck(peek(s)) > operatorCheck((*infixIndex)))
            {
                insertNode(inExpLL, peek(s), OPT);
                pop(&s);
            }
            push(&s, (*infixIndex));
        }

        --infixIndex;
    }

    while (!isEmptyStack(s))
    {
          insertNode(inExpLL, peek(s), OPT);
          pop(&s);
    }
}

int operatorCheck(char lol)
{
    if( lol == '*' || lol == '/') return 2;

    if (lol == '+' || lol == '-') return 1;

    if (lol == '(') return 16; //this is the number of hours spent on this fking assignment

    if (lol == ')') return 61; //this is that number but reversed cuz closing brace xd

    return 0;
}

void printExpLL(LinkedList inExpLL)
{
    ListNode* temp = NULL;
    temp = inExpLL.head;
    while(temp!= NULL){
        if(temp->type == OPERAND)
            printf(" %d ",temp->item);
        else
            printf(" %c ",(char)(temp->item));
        temp = temp->next;
    }
    printf("\n");
}

void insertNode(LinkedList *LLPtr, int item, enum ExpType type) {
    ListNode *newNode;
    newNode = malloc(sizeof(ListNode));
    if(newNode==NULL) exit(0);

    newNode->item = item;
    newNode->type = type;
    newNode->next = LLPtr->head;
    LLPtr->head=newNode;
    LLPtr->size++;
}

int deleteNode(LinkedList *LLPtr) {
    if(LLPtr==NULL || LLPtr->size==0){
        return 0;
    }
    else{
       ListNode *temp = LLPtr->head;
       LLPtr->head = LLPtr->head->next;

       free(temp);
       LLPtr->size--;
       return 1;
    }
}

int isEmptyLinkedList (LinkedList ll) {
    if(ll.size==0) return 1;
    else return 0;
}

void removeAllNodes(LinkedList *LLPtr)
{
	while(deleteNode(LLPtr));
}

void push(Stack *sPtr, char item){
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

char peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}
