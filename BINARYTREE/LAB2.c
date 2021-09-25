//////////////////////////////////////////////////////////////////////
///*
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
BTNode *findVal(BTNode *p, int value);

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
    //BASE CASE: INSERT A NEW NODE USING MALLOC AT THE EMPTY SLOT
        // either the tree is empty, or
        // you reached the correct place to insert the node after going through the recursion
    if (*node == NULL)
    {
        *node = malloc(sizeof(BTNode));
        (*node)->item  = value;
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
    if (node == NULL)
    {
        printf("cant find");
        return;
    }

    // LOCATE THE NODE
    // value is smaller than root. move into left subtree
    if (value < node->item)
    {
        node->left = removeBSTNode(node->left, value);
    }

    // value is bigger than root. move into right subtree
    else if (node->item < value)
    {
        node->right = removeBSTNode(node->right, value);
    }

    // we found the node, time to remove
    else
    {
        // CASE 1: X HAS NO CHILDREN (REMOVE X)
        if (node->left == NULL && node->right == NULL)
        {
            node == NULL;
            return node;
        }

        // CASE 2: X HAS ONE CHILD (SWAP X WITH ITS CHILD)
        if (node->left == NULL || node->right == NULL)
        {
            if (node->left != NULL)
            {
                BTNode* temp = node->left;
                //free(node);
                return temp;
            }
            else if (node->right != NULL)
            {
                BTNode* temp = node->right;
                //free(node);
                return temp;
            }
        }

        // CASE 3: X HAS TWO CHILDREN
        // SWAP X WITH SUCCESSOR

        //find the successor - smallest in the right subtree
        BTNode* succ = findMin(node->right);
        node->item = succ->item;
        // PERFORM CASE 1 OR 2
        node->right = removeBSTNode(node->right, succ->item);
    }
    return node; // when no change is required - just go back up the tree without editing any node
} //end fn

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


BTNode *findMin(BTNode *p)
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
    BTNode* cur = p;
    while (cur != NULL && cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur;
}

//*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
