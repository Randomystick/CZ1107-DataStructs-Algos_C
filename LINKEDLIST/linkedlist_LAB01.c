////////////////////////////////////////////
//////////////// QUESTION 1 ////////////////
////////////////////////////////////////////
/* Implement the removeNode() function for a
 * linked list, using the lecture diagrams and
 * pseudo-code as a reference.
 * The prototype for the removeNode() function is given below:
 * int removeNode(ListNode **ptrHead, int index);
 * The function should return 0 if the delete operation is
 * successful and -1 otherwise. Recall that the function
 * requires a pointer to the head pointer in order to
 * correctly delete the first node.
 */
 /*

#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
    int item;
    struct _listnode *next;
} ListNode;


void printList(ListNode *cur);
ListNode * findNode(ListNode *cur, int index);
int insertNode(ListNode **ptrHead, int index, int item);

int removeNode(ListNode **ptrHead,int index);

int main()
{
    ListNode *head=NULL;
    int size =0;
    int item;
    int index;

    printf("Enter a list of numbers, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
        if(insertNode(&head,size, item)) size++;
    scanf("%*s");

    printList(head);

    while(1){
        printf("Enter the index of the node to be removed: ");
        scanf("%d",&index);

        if(removeNode(&head,index))
            size--;
        else{
            printf("The node cannot be removed.\n");
            break;
        }

        printf("After the removal operation,\n");
        printList(head);
    }

    printList(head);
    return 0;
}

void printList(ListNode *cur){
    printf("Current List: ");
    while (cur != NULL){
        printf("%d ", cur->item);
        cur = cur->next;
    }
    printf("\n");
}

ListNode *findNode(ListNode* cur, int index)
{
   if (cur==NULL || index<0)
      return NULL;
   while(index>0){
      cur=cur->next;
      if (cur==NULL)
         return NULL;
      index--;
   }
   return cur;
}

int insertNode(ListNode **ptrHead, int index, int item){
    ListNode  *pre, *newNode;
    // If empty list or inserting first node, update head pointer
    if (index == 0){
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = *ptrHead;
        *ptrHead = newNode;
        return 1;
    }
    // Find the nodes before and at the target position
    // Create a new node and reconnect the links
    else if ((pre = findNode(*ptrHead, index-1)) != NULL){
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = pre->next;
        pre->next = newNode;
        return 1;
    }
    return 0;
}

int removeNode(ListNode **ptrHead,int index)
{
////////////////////////////////////////////
/////////////////// TODO ///////////////////
////////////////////////////////////////////
    ListNode* pre;

    // If linked list is empty, return -1
    if (*ptrHead == NULL)
    {
        printf("linked list empty lol\n");
        return 0;
    }

    // If removing first node, update head pointer
    else if (index == 0)
    {
        *ptrHead = (*ptrHead)->next;
        return 1;
    }

    // If not removing first node, take the pre and next and link them
    else if ((pre = findNode(*ptrHead, index-1)) != NULL)
    {
        // If the index provided is 1 greater than the max index, pre will be the last node, i.e. pre->next is NULL.
        if(pre->next != NULL)
        {
            pre->next = pre->next->next;
            return 1;
        }
        else return 0;
    }
    return 0;
}
//*/
