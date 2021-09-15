//////////////////////////////////////////////////////////////////////
/*
#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////

typedef struct _btnode{
int item;
struct _btnode *left;
struct _btnode *right;
} BTNode;

///////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value);
void printBSTInOrder(BTNode *node);
int isBST(BTNode *node, int min, int max);
BTNode *removeBSTNode(BTNode *node, int value);
BTNode *findMin(BTNode *p);

///////////////////////////////////////////////////////////////////////

int main(){
	int i=0;

	BTNode *root=NULL;

	//question 1
	do{
		printf("input a value you want to insert(-1 to quit):");

		scanf("%d",&i);
		if (i!=-1)
			insertBSTNode(&root,i);
	}while(i!=-1);

	//question 2
	printf("\n");
	printBSTInOrder(root);

	//question 3
	if ( isBST(root,-1000000, 1000000)==1)
		printf("It is a BST!\n");
	else
		printf("It is not a BST!\n");

	//question 4
	do{
		printf("\ninput a value you want to remove(-1 to quit):");
		scanf("%d",&i);
		if (i!=-1)
		{
			root=removeBSTNode(root,i);
			printBSTInOrder(root);
		}
	}while(i!=-1);


	return 0;
}

//////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value)
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
    //BASE CASE: INSERT A NEW NODE USING MALLOC
    if (*node == NULL)
    {
        *node = malloc(sizeof(BTNode));
        (*node)->item = value;
        (*node)->left  = NULL;
        (*node)->right = NULL;
        return;
    }

	if (value == (*node)->item)

	{
		printf("already inside\n");
		return;
	}

	if (value < (*node)->item)
        // need a pointer to pointer to BTNode
		insertBSTNode(&((*node)->left),value);

	else
		insertBSTNode(&((*node)->right), value);
}

//////////////////////////////////////////////////////////////////////

void printBSTInOrder(BTNode *node)
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
    // in-order: left-print-right
    if (node==NULL) return;
    printBSTInOrder(node->left);
    printf("%i ", node->item);
    printBSTInOrder(node->right);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int isBST(BTNode *node, int min, int max) // the item stored in node has to be smaller than max and larger than min
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
    if (node==NULL) return;

    // for all nodes on left, the "local" parent node is the max
    isBST(node->left, min, node->item);
    if (min < node->item < max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    // for all nodes on left, the "local" parent node is the smallest
    isBST(node->right, node->item, max);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *removeBSTNode(BTNode *node, int value)
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
    // CASE 1: X HAS NO CHILDREN (REMOVE X)
    if (node->left == NULL && node->right == NULL)
    {
        node->item == NULL;
    }

    // CASE 2: X HAS ONE CHILD (SWAP X WITH ITS CHILD)
    if (node->left == NULL || node->right == NULL)
    {
        if (node->left != NULL)
        {
            BTNode* temp = node->left;
            node->item = temp->item;
            node->left = NULL;
        }
        else if (node->right != NULL)
        {
            BTNode* temp = node->right;
            node->item = temp->item;
            node->right = NULL;
        }
    }

    // CASE 3: X HAS TWO CHILDREN
    // SWAP X WITH SUCCESSOR
    typedef struct _listnode
    {
        BTNode* BTNodee;
        struct _listnode* next;
    } ListNode;

    ListNode* ln = (ListNode*) malloc(sizeof(ListNode));
    ln->BTNodee  = NULL;
    ln->next     = NULL;

    ListNode* cur = ln;
    void traverseBST(BTNode *node, ListNode* ln)
    {
        if (node==NULL) return;
        traverseBST(node->left, ln);
        cur->BTNodee = node;
        cur->next = malloc(sizeof(ListNode));
        cur = cur->next;
        traverseBST(node->right, ln);
    }

    traverseBST(node, ln);


    cur = ln;
    while (cur != NULL)
    {
        if (value == cur->BTNodee->item)
        {
            BTNode* tempp = cur->BTNodee;
            cur->BTNodee = cur->next->BTNodee;
            cur->BTNodee->next = tempp;
            break;
        }
        cur = cur->next;
    }

    // PERFORM CASE 1 OR 2

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *findMin(BTNode *p)
{
	// write your code here
}
//*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
