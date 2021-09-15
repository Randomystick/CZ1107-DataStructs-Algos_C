////////////////////////////////////////////////////////////////////
///*
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////


typedef struct _btnode{
	int item;
	struct _btnode *left;
	struct _btnode *right;

} BTNode;

////////////////////////////////////////////////////////////////////


void mirrorTree(BTNode *node);

void printSmallerValues(BTNode *node, int m);
int smallestValue(BTNode *node);
int hasGreatGrandchild(BTNode *node);

void printTree_InOrder(BTNode *node);

////////////////////////////////////////////////////////////////////

int main(int argc, const char * argv[]){

	int i;
	BTNode *root, *root2;
	BTNode btn[15];

	// Create the tree in Q1
	// Using manual dynamic allocation of memory for BTNodes

	root = malloc(sizeof(BTNode));
	root->item = 4;

	root->left = malloc(sizeof(BTNode));
	root->left->item = 5;

	root->right = malloc(sizeof(BTNode));
	root->right->item = 2;

	root->left->left = NULL;

	root->left->right = malloc(sizeof(BTNode));
	root->left->right->item = 6;

	root->left->right->left = NULL;
	root->left->right->right = NULL;

	root->right->left = malloc(sizeof(BTNode));
	root->right->left->item = 3;

	root->right->right = malloc(sizeof(BTNode));
	root->right->right->item = 1;

	root->right->left->left = NULL;

	root->right->left->right = NULL;

	root->right->right->left = NULL;

	root->right->right->right = NULL;

	printTree_InOrder(root);
	printf("\n");
	mirrorTree(root);
	printTree_InOrder(root);
	printf("\n\n");

	//question 2
	printf("\n input m for question 2:");
	scanf("%d", &i);
	printf("the values smaller than %d are:", i);
	printSmallerValues(root, i);
	printf("\n\n");

	//question 3
	printf("The smallest value in the tree is %d\n", smallestValue(root));

	//question 4
	// Create a tree for Q4: Tall enough so some nodes have great-grandchildren
	// Use array of BTNodes, create tree by linking nodes together
	for (i = 0; i <= 6; i++){
		btn[i].item = i;
		btn[i].left = &(btn[i * 2 + 1]);
		btn[i].right = &(btn[i * 2 + 2]);
	}

	for (i = 7; i <= 14; i++){
		btn[i].item = i;
		btn[i].left = NULL;
		btn[i].right = NULL;
	}
	root2 = &btn[0];

	printf("The tree for question 4 visited by in-order is \n");
	printTree_InOrder(root2);
	printf("\nthe values stored in all nodes of the tree that have at least one great-grandchild are: ");

	hasGreatGrandchild(root2);

	return 0;
}

void mirrorTree(BTNode *node)
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
    if (node == NULL) return;

    // VISIT LEFT SUBTREE
    mirrorTree(node->left);

    // VISIT RIGHT SUBTREE
    mirrorTree(node->right);

    // DO THE SWAP - YOU ARE NOW AT THE DEEPEST NODE
    BTNode* tempNode    = node->left;
    node->left  = node->right;
    node->right = tempNode;

}

int hasGreatGrandchild(BTNode *node)
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
// for every node in the original tree, check its height.
// if height is 3 or greater, that node has great grandchild.
    if (node == NULL) return -1;


    int l,r;
    l = hasGreatGrandchild(node->left);
    r = hasGreatGrandchild(node->right);

    if (r>l) l = r;
    if (l>1) //needs to be 1 because this statement comes before the return, hence the +1 in the return is not active yet.
    {
        printf("%d ", node->item);
    }
    return (l+1);

}

void printSmallerValues(BTNode *node, int m)
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////

    if (node == NULL) return;

    if (node->item < m)
    {
        printf("%i ", node->item);
    }

    printSmallerValues(node->left, m);
    printSmallerValues(node->right, m);
}

int smallestValue(BTNode *node)
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
	if (node == NULL) return 99999;

	int cur = node->item;
	int l   = smallestValue(node->left);
	int r   = smallestValue(node->right);
	if (l > r) l = r;
	if (cur > l)
    {
        return l;
    }
    else
    {
        return cur;
    }
}


//////////////////////////////////////////////////////////////////

void printTree_InOrder(BTNode *node){

	if (node == NULL) return;
	printTree_InOrder(node->left);
	printf("%d, ", node->item);
	printTree_InOrder(node->right);
	return;
}
//*/
