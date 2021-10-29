#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 200 //The number digit limitation

typedef struct _btnode{
	int item;
	struct _btnode *left;
	struct _btnode *right;
} BTNode;   // You should not change the definition of BTNode

typedef struct _node{
     BTNode* item;
     struct _node *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void deleteTree(BTNode **root);

void createExpTree(BTNode** root,char* prefix);
void printTree(BTNode *node);
void printTreePostfix(BTNode *node);
double computeTree(BTNode *node);

void push(Stack *sPtr,  BTNode* item);
int pop(Stack *sPtr);
BTNode *peek(Stack s);
int isEmptyStack(Stack s);

int main()
{
    char prefix[SIZE];
    BTNode* root=NULL;

    // printf("Enter an prefix expression:\n");
    scanf("%[^\n]s",prefix);

    createExpTree(&root, prefix);

    // printf("The Infix Expression:\n");
    printTree(root);
    printf("\n");
    // printf("The Postfix (Reverse Polish) Expression:\n");
    printTreePostfix(root);
    printf("\n");
    // printf("Answer ");
    printf("%.2f\n", computeTree(root));
    deleteTree(&root);
    return 0;
}

int operatorCheck(char lol)
{
    if( lol == '*' || lol == '/') return 2;

    if (lol == '+' || lol == '-') return 1;

    return 0;
}

void createExpTree(BTNode** root,char* prefix)
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
    if (prefix==NULL) return; //nothing to add lol

    BTNode* cur;
    Stack savePoints;
    savePoints.head = NULL;
    savePoints.size = 0;

    char* prefixMax = prefix + strlen(prefix) - 1; //the last char

    while (prefix <= prefixMax) //iterate through all the chars
    {
        //if white space, advance pointer
        if(isspace(*prefix))
        {
            prefix++;
            continue;
        }

        //if first node, add the root node
        if (*root == NULL)
        {
            *root = malloc(sizeof(BTNode));
            (*root)->item = *prefix;
            (*root)->left  = NULL;
            (*root)->right = NULL;
            prefix++;
            cur = *root;
            continue;
        }

        //printf("lol");
        //printf("lol:%c\n", cur->item);

        // IF OPERAND, PUT AS LEAF NODE
        if (!operatorCheck(*prefix))
        {
            //printf("%c", *prefix);
            //advance prefix till the end of this number
            int numDigit = 1;
            int digitToAddRev = 0;
            while(isdigit((*prefix)))
            {
                digitToAddRev += numDigit * ((*prefix) - '0');
                numDigit *= 10;
                prefix++;
            }

            //reverse the number that we got
            int digitToAdd = 0;
            while (digitToAddRev)
            {
                digitToAdd = digitToAdd*10 + digitToAddRev%10;
                digitToAddRev /= 10;
            }
            //printf("%i", digitToAdd);

            int hasInserted = 0;
            while (!hasInserted)
            {
                //if left node is null, insert the node in the left
                if (cur->left == NULL)
                {
                    cur->left = malloc(sizeof(BTNode));
                    (cur->left)->item = digitToAdd;
                    (cur->left)->left  = NULL;
                    (cur->left)->right = NULL;
                    //printf("hi %i", cur->left->item);
                    hasInserted = 1;
                }
                //if right node is null, insert the node in the right
                else if (cur->right == NULL)
                {
                    cur->right = malloc(sizeof(BTNode));
                    (cur->right)->item = digitToAdd;
                    (cur->right)->left  = NULL;
                    (cur->right)->right = NULL;
                    //printf("hi %i", cur->right->item);
                    hasInserted = 1;
                }

                // if both left and right are occupied by digits, pop a savepoint from the stack and repeat
                else if ( !(operatorCheck(cur->left->item)) && !(operatorCheck(cur->right->item)) )
                {
                    cur = peek(savePoints);
                    pop(&savePoints);
                }

                else
                {
                    cur = peek(savePoints);
                    pop(&savePoints);
                    //printf("errrrr");
                    //hasInserted = 1;
                }
            }
        }

        // IF OPERATOR, PUT AS INTERNAL NODE
        // rules:
        //// if left null, add left. if right null, add right
        ////// if operator was successfully added, always advance the cur to that newly added node.
        ////// if cur is an operator (always true) and left or right is null, save the current cur into savePoint
        //// if both left and right are occupied by digits, pop a savepoint from the stack and repeat
        else if (operatorCheck(*prefix))
        {
            int hasInserted = 0;
            while (!hasInserted)
            {
                //if left node is null, insert the node in the left
                if (cur->left == NULL)
                {
                    cur->left = malloc(sizeof(BTNode));
                    (cur->left)->item = *prefix;
                    (cur->left)->left  = NULL;
                    (cur->left)->right = NULL;
                    //printf("hi %i", cur->left->item);
                    hasInserted = 1;
                    if ( (operatorCheck(cur->item)) && (cur->right == NULL) )
                    {
                        push(&savePoints, cur);
                    }
                    cur = cur->left;
                }
                //if right node is null, insert the node in the right
                else if (cur->right == NULL)
                {
                    cur->right = malloc(sizeof(BTNode));
                    (cur->right)->item = *prefix;
                    (cur->right)->left  = NULL;
                    (cur->right)->right = NULL;
                    //printf("hi %i", cur->right->item);
                    hasInserted = 1;
                    if ( (operatorCheck(cur->item)) && (cur->left == NULL) )
                    {
                        push(&savePoints, cur);
                    }
                    cur = cur->right;
                }

                // if both left and right are occupied by digits, pop a savepoint from the stack and repeat
                else if ( !(operatorCheck(cur->left->item)) && !(operatorCheck(cur->right->item)) )
                {
                    cur = peek(savePoints);
                    pop(&savePoints);
                }

                else
                {
                    cur = peek(savePoints);
                    pop(&savePoints);
                    //printf("errrrr part 2");
                    //hasInserted = 1;
                }
            }
            //printf("%c", *prefix);
        }

        prefix++;
    } //end iteration
}

void printTree(BTNode *node)
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
    if (node == NULL) return;
    //in-order traversal: left, print, right
    printTree(node->left);
    if (1==1)
    {
        if (operatorCheck(node->item))
        {
            printf("%c ", node->item);
        }
        else
        {
            printf("%i ", node->item);
        }
    }
    printTree(node->right);
}


void printTreePostfix(BTNode *node)
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
    if (node == NULL) return;
    //post-order traversal: left, right, print
    printTreePostfix(node->left);
    printTreePostfix(node->right);
    if (1==1)
    {
        if (operatorCheck(node->item))
        {
            printf("%c ", node->item);
        }
        else
        {
            printf("%i ", node->item);
        }
    }
}

double computeTree(BTNode *node)
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////

	Stack s_postfixRev;
	s_postfixRev.head = NULL;
	s_postfixRev.size = 0;

    //1. Create empty stack
	Stack s;
	s.size = 0;
	s.head = NULL;

	if (node == NULL) return;

	do
	{
		//2. While root not NULL
		while (node != NULL)
		{
			//...push root's right child then root to stack then set root as root->left
			if (node->right != NULL)
			{
				push(&s, node->right);
			}
			push(&s, node);
			node=node->left;
		}

		//3. Pop item from stack and set it as root
		node = peek(s);
		pop(&s);
		if ((node->right != NULL) && (s.head !=NULL) && (node->right == peek(s)))
		{
			pop(&s);
			push(&s, node);
			node=node->right;
		}
		else
		{
		    push(&s_postfixRev, node);
			node = NULL;
		}
	} while (!isEmptyStack(s));

	Stack s_postfix;
	s_postfix.head = NULL;
	s_postfix.size = 0;
	while (!isEmptyStack(s_postfixRev))
    {
        push(&s_postfix, peek(s_postfixRev));
        pop(&s_postfixRev);
    }

///////////////////////////////////////////////////
//    while (!isEmptyStack(s_postfix))
//    {
//        BTNode* nodee = peek(s_postfix);
//        if (operatorCheck(nodee->item))
//        {
//            printf("char%c ", nodee->item);
//        }
//        else
//        {
//            printf("int%i ", nodee->item);
//        }
//        pop(&s_postfix);
//    }
///////////////////////////////////////////////////

//////    Stack tempStack;
//////    tempStack.head = NULL;
//////    tempStack.size = 0;
    double tempStack[999] = {-1.00};
    int tIndex = 0;
    // s_postfix is basically reading the postfix expression from left to right
    while (!isEmptyStack(s_postfix))
    {
        if (!operatorCheck(peek(s_postfix)->item)) //operand. push into tempStack
        {
            tempStack[tIndex] = (double)peek(s_postfix)->item;
            //printf("%f", tempStack[tIndex]);
            tIndex++;
            //push(&tempStack, peek(s_postfix));
        }
        else //operator. pop two operands from tempStack, evaluate and push back to tempStack
        {
            //printf(" %i ", peek(s_postfix)->item);
            double right = 0.00;
            double left = 0.00;
            if (tempStack[tIndex] != -1.00)
            //if (tempStack.head != NULL)
            {
                right = (double)tempStack[--tIndex];
                //printf("right%i\n", right);
                //right = peek(tempStack)->item;
            }
            else return 0.00;
            //pop(&tempStack);
            if (tempStack[tIndex] != -1.00)
            //if (tempStack.head != NULL)
            {
                left = (double)tempStack[--tIndex];
                //printf("left%i\n", left);
                //left = peek(tempStack)->item;
            }
            else return 0.00;
            //pop(&tempStack);
            double result = 0.00;
            char opr = peek(s_postfix)->item;
            if (opr == '*')
            {
                result = (double)left*right;
            }
            else if (opr == '/')
            {
                result = (double)left/right;
            }
            else if (opr == '+')
            {
                result = (double)left+right;
            }
            else if (opr == '-')
            {
                result = (double)left-right;
            }
            //printf("lol:%i\n", result);
            tempStack[tIndex++] = result;
//////            BTNode* resultNode = malloc(sizeof(BTNode));
//////            resultNode->item = result;
//////            resultNode->left  = NULL;
//////            resultNode->right = NULL;
//////            push(&tempStack, resultNode);
        }
        pop(&s_postfix);
    }

    if (tempStack[0] != -1.00)
    //if (tempStack.head != NULL)
    {
        return tempStack[0];
    }
    return 0.00;

}

void push(Stack *sPtr, BTNode *item){
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

BTNode *peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

void deleteTree(BTNode **root){
    BTNode* temp;
    if(*root !=NULL)
    {
        temp = (*root)->right;
        deleteTree(&((*root)->left));
        free(*root);
        *root = NULL;
        deleteTree(&temp);
    }
}
