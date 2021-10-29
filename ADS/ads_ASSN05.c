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
//
//int deleteNode(LinkedList *llPtr);
//void removeAllNodes(LinkedList *llPtr);
//int isEmptyLinkedList (LinkedList ll);
//
//
//void in2PreLL(char* infix, LinkedList *inExpLL);
//
//void printExpLL(LinkedList inExp);
//
//int main()
//{
//    char infix[SIZE];
//
//    printf("Enter an infix expression:\n");
//    scanf("%s",infix);
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
//int operatorCheck(char lol)
//{
////////////////////////////////
////////////// TODO ////////////
////////////////////////////////
//    if (lol == '*' || lol == '/' || lol == '%')
//    {
//        return 2;
//    }
//    else if (lol == '+' || lol == '-')
//    {
//        return 1;
//    }
//    else //is operand
//    {
//        return 0;
//    }
//}
//
//void in2PreLL(char* infix, LinkedList *inExpLL)
//{
////////////////////////////////
////////////// TODO ////////////
////////////////////////////////
//    // CONVERT FROM INFIX TO PREFIX // right to left, stack store operator (*precedence has > instead of >=),
//    // Stack s stores the input, already read from right to left.
//    // output string is inExpLL.
//    // s_number is the tempStack to store the operators
//
//    Stack s_number;
//    s_number.head = NULL; s_number.size = 0;
//
//    int loop = strlen(infix);
//    for (int i = loop-1; i > -1; i--)
//    {
//        char c = infix[i];
//        if (isdigit(c)) //if c is operand, put it into output string
//        {
//            //insertNode(inExpLL, c, OPERAND);
//            int numDigit = 1;
//            int digitToAdd = 0;
//
//            while (isdigit(c))
//            {
//                digitToAdd += numDigit*(infix[i] - 48);
//                numDigit = numDigit*10;
//                c = infix[--i];
//            }
//            insertNode(inExpLL, digitToAdd, OPERAND);
//        }
//
//
//        else if (c == ')') //if c is opening brace, push it into tempStack
//        {
//            push(&s_number, c);
//        }
//
//
//        else if (c == '(') //if c is closing brace
//        {
//            while (!isEmptyStack(s_number) && peek(s_number) != ')')
//            {
//                //move all operators from tempStack into output string
//                insertNode(inExpLL, peek(s_number), OPT);
//                pop(&s_number);
//            }
//            pop(&s_number); //remove opening brace
//        }
//
//
//        else if (operatorCheck(c))//an operator
//        {
//            while ( !isEmptyStack(s_number) && peek(s_number)!=')' && operatorCheck(peek(s_number))>operatorCheck(c) )
//            {
//                insertNode(inExpLL, peek(s_number), OPT);
//                pop(&s_number);
//            }
//            push(&s_number, c);
//        }
//
//
//        while (!isEmptyStack(s_number))
//        {
//            insertNode(inExpLL, peek(s_number), OPT);
//            pop(&s_number);
//        }
//    } //END FOR LOOP
//
//    while (!isEmptyStack(s_number))
//    {
//        insertNode(inExpLL, peek(s_number), OPT);
//        pop(&s_number);
//    }
//
//} //END OF HELL
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
