/*
#include <stdlib.h>
#include <stdio.h>


/////////////////////////// STRUCT
typedef struct _listnode
{
    int item;
    struct _listnode* next;
} ListNode;


/////////////////////////// PRINTLIST
void printList(ListNode *head)
{
    if (head == NULL)
    return;
    while (head != NULL)
    {
        printf("%d ", head->item);
        head = head->next;
    }
    printf("\n");
}


////////////////////////// SIZELIST
int sizeList(ListNode *head)
{
	int count = 0;
	if (head == NULL) return count;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}


////////////////////////// FINDNODE
ListNode * findNode(ListNode *head, int index)
{
    if (head == NULL || index < 0) return NULL;

    while (index > 0)
    {
        head = head->next;
        if (head == NULL) return NULL;
        index--;
    }
    return head;
}


////////////////////////// INSERTNODE
int insertNode(ListNode **ptrHead, int index, int value)
{
    ListNode *pre, *cur;

    // If empty list or inserting first node, need to update head pointer
    if (*ptrHead == NULL || index == 0)
    {
        //cur contains address of node to pre-insert
        cur = *ptrHead;

        //make pointer head store address of new node
        *ptrHead = malloc(sizeof(ListNode));

        // for this new node, put “value” as the data and “cur” as the address
        (*ptrHead)->item = value;
        (*ptrHead)->next = cur;

    return 0;
    }

    // Find the nodes before and at the target position
    // Create a new node and reconnect the links
    if ((pre = findNode(*ptrHead, index-1)) != NULL)
    {
        cur = pre->next;
        pre->next = malloc(sizeof(ListNode));
        pre->next->item = value;
        pre->next->next = cur;
        return 0;
    }

return -1;
}


////////////////////////// main
int main()
{
    ListNode *head = NULL;

    srand(time(NULL));
    while (sizeList(head) < 10)
    {
        insertNode(&head, 0, rand() % 100);
        printf("List: ");
        printList(head);
        printf("\n");
    }
    printf("%d nodes\n", sizeList(head));

    while (1==0)
        //(sizeList(head) > 0)
    {
        removeNode(&head, sizeList(head)-1);
        printf("List: ");
        printList(head);
        printf("\n");
    }
    printf("%d nodes\n", sizeList(head));
    return 0;

}
//*/

