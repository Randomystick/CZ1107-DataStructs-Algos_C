/*
#include <stdlib.h>
#include <stdio.h>

typedef struct _listnode
{
int item;
struct _listnode* next;
} ListNode;

typedef struct _linkedlist{
	ListNode *head; //head pointer variable
	int size;
} LinkedList;

////////////////////////// PRINTLIST
void printList(LinkedList *ll)
// you are passing by reference the actual linked list, and hence the actual head pointer ll->head.
// as a result, a new *temp pointer has to be created to retrieve and modify ll->head locally and non-destructively.
{
    ListNode *temp = ll->head;
    if (temp == NULL)
    return;

    while (temp != NULL)
    {
        printf("%d ", temp->item);
        temp = temp->next;
    }
    printf("\n");
}


////////////////////////// FINDNODE
ListNode * findNode(LinkedList *ll, int index)
{
    ListNode *temp = ll->head;
    if (temp == NULL || index < 0) return NULL;

    while (index > 0)
    {
        temp = temp->next;
        if (temp == NULL) return NULL;
        index--;
    }
    return temp;
}


////////////////////////// INSERTNODE
int insertNode(LinkedList * ll_ptr, int index, int value)
{
    ListNode *pre, *cur;

    // If empty list or inserting first node, need to update head pointer
    if (ll_ptr->head == NULL || index == 0)
    {
        //cur contains address of node to pre-insert
        cur = ll_ptr->head;
        ll_ptr->head = 0;
        //make pointer head store address of new node
        ll_ptr->head = malloc(sizeof(ListNode));

        // for this new node, put “value” as the data and “cur” as the address
        ll_ptr->head->item = value;
        ll_ptr->head->next = cur;

    return 0;
    }

    // Find the nodes before and at the target position
    // Create a new node and reconnect the links
    if ((pre = findNode(ll_ptr, index-1)) != NULL)
    {
        cur = pre->next;
        pre->next = malloc(sizeof(ListNode));
        pre->next->item = value;
        pre->next->next = cur;
        return 0;
    }

return -1;
}

int main()
{
    LinkedList ll;
    LinkedList *ptr_ll; //pass this into functions
    ptr_ll = &ll;
    insertNode(ptr_ll, 0, 13);
    insertNode(ptr_ll, 0, 16);
    insertNode(ptr_ll, 1, 111);
    printList(ptr_ll);
    return 0;
}
//*/

