//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define SIZE 80 //The limit of expression length
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
//int precedence(char c);
//
//void in2Post(char*, char*);
//
//int main()
//{
//    char infix[SIZE];
//    char postfix[SIZE];
//
//    printf("Enter an infix expression:\n");
//    gets(infix);
//
//    in2Post(infix,postfix);
//    printf("The postfix expression is \n");
//    printf("%s\n",postfix);
//    return 0;
//}
//
//void in2Post(char* infix, char* postfix)
//{
//    Stack s;
//    s.head = NULL;
//    s.size = 0;
//
//    int i = 0;
//    int j = 0;
//    char c;
//
//    while(infix[i]!='\0')
//    {
//        c = infix[i++];
//        switch(c)
//        {
//            case '(':
//                push(&s,c);
//                break;
//
//            case ')':
//                while(!isEmptyStack(s))
//                {
//                    if(peek(s) != '(')
//                    {
//                        postfix[j++] = peek(s);
//                        pop(&s);
//                    }
//                    else
//                    {
//                        pop(&s);
//                        break;
//                    }
//                }
//                break;
//
//            case '*': //operators
//            case '/':
//            case '+':
//            case '-':
//                while(!isEmptyStack(s) && peek(s) != '(' && precedence(peek(s)) >= precedence(c) )
//                {
//                    postfix[j++] = peek(s);
//                    pop(&s);
//                }
//                push(&s,c);
//                break;
//
//            default: //operand
//                postfix[j++] = c;
//        }
//    }
//
//    while(isEmptyStack(s)==0)
//    {
//        postfix[j++] = peek(s);
//        pop(&s);
//    }
//    postfix[j] = '\0';
//}
//
//int precedence(char c)
//{
//    if (c == '*' || c == '/')
//    {
//        return 2;
//    }
//
//    if (c == '+' || c == '-')
//    {
//        return 1;
//    }
//
//    return 0;
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
