//#include <stdio.h>
//#include <stdlib.h>
//
//#define SIZE 80 //The limit of expression length
//
//typedef struct _stackNode{
//    double item;
//    struct _stackNode *next;
//}StackNode;
//
//typedef struct _stack{
//   int size;
//   StackNode *head;
//}Stack;
//
//void push(Stack *sPtr, double item);
//int pop(Stack *sPtr);
//double peek(Stack s);
//int isEmptyStack(Stack s);
//
//double exePostfix(char*);
//
//int main()
//{
//    char postfix[SIZE];
//
//    printf("Enter a postfix expression:\n");
//    gets(postfix);
//
//    printf("The answer is %.2lf.\n",exePostfix(postfix));
//
//    return 0;
//}
//
//
//double exePostfix(char* postfix)
//{
//    //987-654-/3+*+
//
//    //postfix-->result
//    //read left to right
//    //stack store operand
//    //evaluate result
//    Stack s; s.head = NULL; s.size = 0;
//
//    char c;
//    int i = 0;
//    while (postfix[i] != '\0')
//    {
//        c = postfix[i++];
//        if (c != '*' && c != '/' && c != '+' && c != '-')
//        {
//            push(&s, c-'0');
//        }
//
//        else
//        {
//            double lol1 = peek(s); pop(&s);
//            double lol2 = peek(s); pop(&s);
//            double result = 0;
//            if (c == '*')
//            {
//                result = lol2 * lol1;
//            }
//            else if (c == '/')
//            {
//                result = lol2 / lol1;
//            }
//            else if (c == '+')
//            {
//                result = lol2 + lol1;
//            }
//            else if (c == '-')
//            {
//                result = lol2 - lol1;
//            }
//            push(&s, result);
//        }
//    }
//
//    return peek(s);
//
//}
//
//void push(Stack *sPtr, double item){
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
//double peek(Stack s){
//    return s.head->item;
//}
//
//int isEmptyStack(Stack s){
//     if(s.size == 0) return 1;
//     else return 0;
//}
//
