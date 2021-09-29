////////////////////////////////////////////
//////////////// QUESTION 2 ////////////////
////////////////////////////////////////////
/* (moveMaxToFront) Write a C function moveMaxToFront()
 * that traverses a linked list of integers at most once,
 * then moves the node with the largest stored value to the front of the
 * list.
 * The function prototype is given as follows:
 * int moveMaxToFront(ListNode **ptrHead);
 * For example, if the linked list is (30, 20, 40, 70, 50),
 * the resulting linked list will be (70, 30, 20, 40,50).
 */
 /*
 //////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode
{
	int item;
	struct _listnode *next;
} ListNode;			// You should not change the definition of ListNode

typedef struct _linkedlist
{
	int size;
	ListNode *head;
} LinkedList;			// You should not change the definition of LinkedList


//////////////////////// function prototypes /////////////////////////////////////

// You should not change the prototype of this function
int moveMaxToFront(ListNode **ptrHead);

void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);


//////////////////////////// main() //////////////////////////////////////////////

int main()
{
	int c, i, j;
	c = 1;

	LinkedList ll;
	//Initialize the linked list 1 as an empty linked list
	ll.head = NULL;
	ll.size = 0;


	printf("1: Insert an integer to the linked list:\n");
	printf("2: Move the largest stored value to the front of the list:\n");
	printf("0: Quit:\n");

	while (c != 0)
	{
		printf("Please input your choice(1/2/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to add to the linked list: ");
			scanf("%d", &i);
			j=insertNode(&ll, ll.size, i);
			printf("The resulting linked list is: ");
			printList(&ll);
			break;
		case 2:
			moveMaxToFront(&(ll.head));  // You need to code this function
			printf("The resulting linked list after moving largest stored value to the front of the list is: ");
			printList(&ll);
			removeAllItems(&ll);
			break;
		case 0:
			removeAllItems(&ll);
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////

int moveMaxToFront(ListNode **ptrHead)
{
////////////////////////////////////////////
/////////////////// TODO ///////////////////
////////////////////////////////////////////

    //Find the index where the max value resides
    int MAX = (*ptrHead)->item;
    int MAXindex = 0;

    ListNode* cur = (*ptrHead)->next;
    int curIndex = 1;
    while (cur != NULL)
    {
        if ((cur->item) > MAX)
        {
            MAX = cur->item;
            MAXindex = curIndex;
        }
        cur = cur->next;
        curIndex++;
    }

    // Insert a new node at index 0 for the MAX value
    //cur contains address of node to pre-insert
    cur = *ptrHead;
    //make head store address of new MAX node
    *ptrHead = malloc(sizeof(ListNode));
    (*ptrHead)->item = MAX;
    (*ptrHead)->next = cur;

    // Remove the old node (which is at MAXindex+1)
    // 4 1 2 4 3
    //       ^
    //  index3
    //get pre to point at the node before the node to remove
    //get cur to point at the node to remove
    //if cur->next != NULL, node to remove is not last. get pre to point at cur->next
    //if cur->next == NULL, node to remove is the last. get pre to point at null
    ListNode* pre = *ptrHead;
    for (int i = 0; i < MAXindex; i++)
    {
        pre = pre->next;
    }
    pre->next = pre->next->next;

                                    int moveMaxToFront(ListNode **ptrHead)
                                    {
                                        ListNode* cur = *ptrHead;
                                        if (cur == NULL || cur->next == NULL) return;

                                        int maxValue = cur->item;
                                        int maxIndex = 0;
                                        int curIndex = 0;
                                        while (cur != NULL)
                                        {
                                            if (cur->item > maxValue)
                                            {
                                                maxValue = cur->item;
                                                maxIndex = curIndex;
                                            }
                                            curIndex++;
                                            cur = cur->next;
                                        }
                                        //printf("maxValue %i maxIndex %i", maxValue, maxIndex);
                                        if (maxIndex == 0) return;


                                        //removeNode
                                        // Find the nodes before and after the target position
                                        // Free the target node and reconnect the links
                                        ListNode* pre = *ptrHead;
                                        for (int i=0; i<maxIndex-1; i++)
                                        {
                                            pre = pre->next;
                                        }
                                        cur = pre->next;
                                        pre->next = cur->next;
                                        free(cur);


                                        //insertNode
                                        cur = *ptrHead;
                                        ListNode* newNode = malloc(sizeof(ListNode));
                                        newNode->item = maxValue;
                                        newNode->next = cur;
                                        *ptrHead = newNode;
                                    }

}

//////////////////////////////////////////////////////////////////////////////////

void printList(LinkedList *ll){

	ListNode *cur;
	if (ll == NULL)
		return;
	cur = ll->head;

	if (cur == NULL)
		printf("Empty");
	while (cur != NULL)
	{
		printf("%d ", cur->item);
		cur = cur->next;
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
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
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

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}

void removeAllItems(LinkedList *ll)
{
	ListNode *cur = ll->head;
	ListNode *tmp;

	while (cur != NULL){
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	ll->head = NULL;
	ll->size = 0;
}
 //*/
