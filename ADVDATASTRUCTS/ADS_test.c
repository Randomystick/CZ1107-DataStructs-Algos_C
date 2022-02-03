//#include <stdio.h>
//#include <stdlib.h>
//
//#define SIZE 80 //The size of the array
//
//enum ExpType {OPT,OPERAND};
//
//typedef struct _stackNode{
//    char item;
//    struct _stackNode *next;
//}StackNode;
//
//typedef struct _stack{
//   int size;
//   StackNode *head;
//}Stack;
//
//void push(Stack *sPtr, char item);
//int pop(Stack *sPtr);
//char peek(Stack s);
//int isEmptyStack(Stack s);
//
//typedef struct _listnode
//{
//    int  item;
//    enum ExpType type;
//	struct _listnode *next;
//} ListNode;
//
//typedef struct _linkedlist{
//   int size;
//   ListNode *head;
//} LinkedList;
//
//void insertNode(LinkedList *llPtr, int item,enum ExpType type);
//int deleteNode(LinkedList *llPtr);
//void removeAllNodes(LinkedList *llPtr);
//int isEmptyLinkedList (LinkedList ll);
//
//void in2PreLL(char* infix, LinkedList *inExpLL);
//
//void printExpLL(LinkedList inExpLL);
//
//// For Assignment
//#include <ctype.h>
//#include <string.h>
//int IsOperator(char _c);
//int GetPrecedence(char _c);
//
//int main()
//{
//    char infix[SIZE];
//
//    //printf("Enter an infix expression:\n");
//    gets(infix);
//
//    LinkedList inExpLL;
//    inExpLL.head = NULL;
//    inExpLL.size = 0;
//
//    in2PreLL(infix, &inExpLL);
//
//    printExpLL(inExpLL);
//
//    removeAllNodes(&inExpLL);
//    return 0;
//}
//
//void in2PreLL(char* infix, LinkedList *inExpLL)
//{
//    char* revInfix = infix + strlen(infix) - 1;
//
//    Stack s;
//    s.size = 0;
//    s.head = NULL;
//
//    while (revInfix >= infix)
//    {
//        if(IsOperator((*revInfix)))
//        {
//            while(!isEmptyStack(s) && peek(s) != ')' && GetPrecedence(peek(s)) > GetPrecedence((*revInfix)))
//            {
//                insertNode(inExpLL, peek(s), OPT);
//                pop(&s);
//            }
//
//            push(&s, (*revInfix));
//        }
//        else if((*revInfix) == '(')
//        {
//            while(!isEmptyStack(s))
//            {
//                if(peek(s) == ')')
//                {
//                    pop(&s);
//                    break;
//                }
//                insertNode(inExpLL, peek(s), OPT);
//                pop(&s);
//            }
//        }
//        else if((*revInfix) == ')')
//        {
//            push(&s,(*revInfix));
//        }
//        else
//        {
//            if(isdigit((*revInfix)))
//            {
//                int numDigit = 1;
//                int digitToAdd = 0;
//
//                while(isdigit((*revInfix)))
//                {
//                    digitToAdd += numDigit * ((*revInfix) - '0');
//                    numDigit *= 10;
//                    --revInfix;
//                }
//
//                insertNode(inExpLL, digitToAdd, OPERAND);
//                continue;
//            }
//            else
//            {
//                insertNode(inExpLL, (*revInfix), OPERAND);
//            }
//        }
//
//        --revInfix;
//
//    }
//
//    while (!isEmptyStack(s))
//    {
//          insertNode(inExpLL, peek(s), OPT);
//          pop(&s);
//    }
//}
//
//int IsOperator(char _c)
//{
//    return (!isalpha(_c) && !isdigit(_c) && _c != '(' && _c != ')');
//}
//
//int GetPrecedence(char _c)
//{
//    // Highest precedence
//    if(_c == '*' || _c == '/')
//        return 2;
//    else if (_c == '+' || _c == '-')
//        return 1;
//
//    return 0;
//}
//
//void printExpLL(LinkedList inExpLL)
//{
//    ListNode* temp = NULL;
//    temp = inExpLL.head;
//    while(temp!= NULL){
//        if(temp->type == OPERAND)
//            printf(" %d ",temp->item);
//        else
//            printf(" %c ",(char)(temp->item));
//        temp = temp->next;
//    }
//    printf("\n");
//}
//
//void insertNode(LinkedList *LLPtr, int item, enum ExpType type) {
//    ListNode *newNode;
//    newNode = malloc(sizeof(ListNode));
//    if(newNode==NULL) exit(0);
//
//    newNode->item = item;
//    newNode->type = type;
//    newNode->next = LLPtr->head;
//    LLPtr->head=newNode;
//    LLPtr->size++;
//}
//
//int deleteNode(LinkedList *LLPtr) {
//    if(LLPtr==NULL || LLPtr->size==0){
//        return 0;
//    }
//    else{
//       ListNode *temp = LLPtr->head;
//       LLPtr->head = LLPtr->head->next;
//
//       free(temp);
//       LLPtr->size--;
//       return 1;
//    }
//}
//
//int isEmptyLinkedList (LinkedList ll) {
//    if(ll.size==0) return 1;
//    else return 0;
//}
//
//void removeAllNodes(LinkedList *LLPtr)
//{
//	while(deleteNode(LLPtr));
//}
//
//void push(Stack *sPtr, char item){
//    StackNode *newNode;
//    newNode = malloc(sizeof(StackNode));
//    newNode->item = item;
//    newNode->next = sPtr->head;
//    sPtr->head = newNode;
//    sPtr->size++;
//}
//
//int pop(Stack *sPtr){
//    if(sPtr == NULL || sPtr->head == NULL){
//        return 0;
//    }
//    else{
//       StackNode *temp = sPtr->head;
//       sPtr->head = sPtr->head->next;
//       free(temp);
//       sPtr->size--;
//       return 1;
//    }
//}
//
//char peek(Stack s){
//    return s.head->item;
//}
//
//int isEmptyStack(Stack s){
//     if(s.size == 0) return 1;
//     else return 0;
//}
//
