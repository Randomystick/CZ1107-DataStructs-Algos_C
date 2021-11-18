///*
#include <stdio.h>
#include <stdlib.h>

typedef struct _arraynode
{
    int *itemArray;
    int sizeArray;
    struct _arraynode *next;
}ArrayNode;

typedef struct _arraylist{
   int size; //the size of a possible sequence
   ArrayNode *head;
} ArrayList;

typedef struct _listnode
{
    int item;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int sum; //the number of possible sequences
   int size;
   ListNode *head;
} LinkedList;

// You should not change the prototypes of these functions
//////LinkedList///////////////////////////////////////////
int insertNode(LinkedList *ll, int index, int coin);
int removeNode(LinkedList *ll, int index);
ListNode *findNode(LinkedList ll, int index);
void removeAllItems(LinkedList *ll);
///////////////////////////////////////////////////

void sumToC(LinkedList* ll, int C, ArrayList* al);
int main()
{
    int C;
    printf("Enter a number:\n");
    scanf("%d",&C);

    LinkedList ll;
    ll.head = NULL;
    ll.sum = 0;
    ll.size = 0;
    ArrayList al;
    al.head = NULL;
    al.size = 0;

    sumToC(&ll,C,&al);
    ArrayNode* temp;
    int i,j;
    temp = al.head;
    for(i=0;i<al.size;i++){
        for(j=0;j<temp->sizeArray;j++)
            printf(" %d ",temp->itemArray[j]);
        printf("\n");
        temp = temp->next;
    }

    return 0;
}

void sumToC(LinkedList* ll, int C, ArrayList* al)
{
// 9

// 1 2 6
// 1 3 5
// 1 8
// 2 3 4
// 2 7
// 3 6
// 4 5
// 9

//-----------------------------------------------------------------------------------------------------------------
//            al                                                                ll
// size               head                              sum                     size            head
// ^number of          |                                ^is it equal            ^to insert        |
// solutions           |                                 C?                      at back          |
// in total           \|/                                                                        \|/
//                   itemArray     itemArray                                                    item        item
//                   sizeArray     sizeArray                                                    next ---->  next
//                   next ------>  next
//                   ^each array is a solution and its no of elements
//-----------------------------------------------------------------------------------------------------------------
    // SOLUTION FOUND - THIS IS THE ONLY TIME TO TOUCH al
    if (ll->sum == C)
    {
        //printf("solutionnnn\n");
        // parse the solution
        ArrayNode* solution = (ArrayNode *) malloc(sizeof(ArrayNode));
        solution->sizeArray = ll->size;
        solution->next = NULL;
        solution->itemArray = (int*) malloc((ll->size)*sizeof(int));
        ListNode* cur = ll->head;
        int i = 0;
        while (cur != NULL)
        {
            solution->itemArray[i] = cur->item;
            cur = cur->next;
            i++;
        }

        // find the last node of al
        ArrayNode* lastNode = al->head;
        if (lastNode == NULL)
        {
            al->head = solution;
        }
        else
        {
            while (lastNode->next != NULL)
            {
                lastNode = lastNode->next;
            }
        lastNode->next = solution;
        }
        al->size++;
    }

    // for every possible number between 1 and C
    for (int j=1; j<=C; j++)
    {
        //printf("looping, j is %i\n", j);

        ListNode* lastNode = ll->head;
        if (lastNode != NULL)
        {
            if (lastNode->next != NULL)
            {
                while (lastNode->next != NULL)
                {
                    lastNode = lastNode->next;
                }
            }
        }
        //printf("ll->sum is %i j is %i, C is %i\n", ll->sum, j, C);
        // if we can add this number
        int sum = ll->sum;
        if ( lastNode == NULL || ll->head == NULL || (sum+j<=C) && (lastNode->item < j) )
        {
            //printf("Adding %i\n", j);
            insertNode(ll, ll->size, j);
            //printf("ll->sum now %i, size now %i\n", ll->sum, ll->size);
            // place a 'hook' down and go deeper.
            sumToC(ll, C, al);

            removeNode(ll, ll->size-1);
        }
    }
} // END FUNCTIONNNN
///////////////////////////////////////////////////////
int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size)
		return 0;

        if (index == 0){
		cur = ll->head;
		ll->head = (ListNode*) malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->sum += value;
		ll->size++;
		return 1;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(*ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->sum += value;
		ll->size++;
		return 1;
	}

	return 0;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index > ll->size)
		return 0;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		ll->sum -= ll->head->item;
		free(ll->head);
		ll->head = cur;
		ll->size--;
		return 1;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(*ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return 0;

		cur = pre->next;
		ll->sum -= cur->item;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 1;
	}

	return 0;
}

ListNode *findNode(LinkedList ll, int index){

	ListNode *temp;

	if (index < 0 || index >= ll.size)
		return NULL;

	temp = ll.head;

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
	ll->sum =0;
}
//*/
