///*
#include <stdio.h>
#include <stdlib.h>

#define SIZE 80 //The size of the array

enum ExpType {OPT,OPERAND};

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

void insertNode(LinkedList *llPtr, int item, enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList (LinkedList ll);

void expressionLL(char* infix, LinkedList *inExpLL);

void printExpLL(LinkedList inExpQ, int seed);

int main()
{
    char infix[SIZE];

    //printf("Enter an infix expression:\n");
    scanf("%s",infix);

    LinkedList inExpLL;
    inExpLL.head = NULL;
    inExpLL.size = 0;

    expressionLL(infix, &inExpLL);

    int seed;
    //printf("Enter a seed: \n");
    scanf("%d",&seed);
    printExpLL(inExpLL,seed);

    removeAllNodes(&inExpLL);
    return 0;
}


void expressionLL(char* infix, LinkedList *inExpLL)
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////

    // ANSWER REVERSED //
    LinkedList inExpLL_rev;
    inExpLL_rev.head = NULL; inExpLL_rev.size = 0;

    // TEMP STACK //
    LinkedList ll_number;
    ll_number.head = NULL; ll_number.size = 0;

    // PROCESS THE STRING //
    int len = strlen(infix);
    for (int i = 0; i<len; i++)
    {
        //printf("%c ", infix[i]);}
        if (infix[i] == '*' || infix[i] == '(' || infix[i] == '+' || infix[i] == '-' || infix[i] == ')' || infix[i] == '/')
        {
            // if we meet an operator, we may have reached the end of the previous number. add that to the linked list if it exists.
            if (!isEmptyLinkedList(ll_number))
            {
                int intToAdd = 0;
                int index = 0;
                int thisNumber = 0;
                while (!isEmptyLinkedList(ll_number))
                {
                    thisNumber = (int)(ll_number.head->item);
                    for (int i = 0; i<index; i++)
                    {
                        thisNumber = thisNumber*10;
                    }
                    intToAdd = intToAdd + thisNumber;
                    deleteNode(&ll_number);
                    index++;
                }
                //printf("adding numberr %i\n", intToAdd);
                insertNode(&inExpLL_rev, intToAdd, OPERAND);
            }

            // it is an operator
            //printf("adding operatorr %c\n", infix[i]);
            insertNode(&inExpLL_rev, infix[i], OPT);
        }
        else
        {
            // it is a number
            insertNode(&ll_number, infix[i]-48, OPERAND);
        }
    }
    // we may have reached the end of the expression, but there's still a number in ll_number. add that to the stack.
    if (!isEmptyLinkedList(ll_number))
    {
        int intToAdd = 0;
        int index = 0;
        int thisNumber = 0;
        while (!isEmptyLinkedList(ll_number))
        {
            thisNumber = (int)(ll_number.head->item);
            for (int i = 0; i<index; i++)
            {
                thisNumber = thisNumber*10;
            }
            intToAdd = intToAdd + thisNumber;
            deleteNode(&ll_number);
            index++;
        }
        //printf("adding numberr %i\n", intToAdd);
        insertNode(&inExpLL_rev, intToAdd, OPERAND);
    }


    while (!isEmptyLinkedList(inExpLL_rev))
    {
        insertNode(inExpLL, inExpLL_rev.head->item, inExpLL_rev.head->type);
        deleteNode(&inExpLL_rev);
    }

} //endddd

void printExpLL(LinkedList inExpLL, int seed)
{
    ListNode* temp = NULL;
    temp = inExpLL.head;
    while(temp!= NULL){
        if(temp->type == OPERAND)
            printf(" %d ",temp->item+ seed);
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
    if(LLPtr==NULL || LLPtr->size==0){ //Queue is empty or NULL pointer
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
//*/
