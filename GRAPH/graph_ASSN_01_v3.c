///*
#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int vertex;
    struct _listnode *next;
} ListNode;
typedef ListNode StackNode;
typedef ListNode QueueNode;

typedef struct _graph
{
    int V;
    int E;
    ListNode **list;
}Graph;

typedef struct _queue
{
    int size;
    QueueNode *head;
    QueueNode *tail;
} Queue;

typedef struct _stack
{
    int size;
    StackNode *head;
} Stack;

void insertAdjVertex(ListNode** AdjList,int vertex);
void removeAdjVertex(ListNode** AdjList,int vertex);

void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);
void printQ(QueueNode *cur);
//////STACK///////////////////////////////////////////
void push(Stack *sPtr, int vertex);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);
//////////////////////////////////

// CHECK WHETHER DFS EXISTS. if yes, put the path in the stack
int hasDFS(int **matrix, int size, Stack* s)
{
    // take the first vertex in the stack. for the first run, this is 0,
    // the source. for every other recursive run, this is the latest vertex
    // in the traversal.
    int cur = peek(*s);
    int RETURNVAL = 0;

    // for every possible vertex...
    for (int i = size-1; i>=0; i--)
    {
        // if this vertex is adjacent...
        if (matrix[cur][i] == 1)
        {
            //...and the sink, then a path is found
            if(i == size-1) return 1;

            // else, push this vertex to the stack and stop flow between cur and adj
            push(s, i);
            matrix[cur][i] = 0;

            //recursion
            RETURNVAL = hasDFS(matrix, size, s);

            //false alarm - we failed to find a path. pop the last node we visited and start flow between cur and adj again
            if (RETURNVAL == 0)
            {
                //printf("hi");
                matrix[cur][i] = 1;
                pop(s);
            } else break;
        }
    }
    //printf("%i\n", RETURNVAL);
    return RETURNVAL;
}

// SUM THE TOTAL NUMBER OF DFS FOUND
int matching(int **matrix, int size)
{
    // since we are only concerned with the total number of matches,
    // and all paths have the same weight of 1,
    // we only need to care about the number of times we can draw a path through
    // the residual network. we don't need to care about the network graph.
    // in this sense, **matrix serves as our residual graph. this works because the
    // network graph is the same as the residual graph at the beginning when this
    // function is first called.

    int MATCHES = 0;

    // store the path that DFS found
    Stack s; s.head = NULL; s.size = 0;

    int matchFound = 0;
    while (1==1)
    {
        // put the source into the stack before passing to DFS
        push(&s, 0);
        // a path found
        if (hasDFS(matrix, size, &s))
        {
            // apply the reverse flow
            int after = peek(s); pop(&s);
            while (!isEmptyStack(s))
            {
                int before = peek(s); pop(&s);
                matrix[after][before] = 1;
                after = before;
            }
            MATCHES++;
        } else break;
    }

    return MATCHES;
}



int main()
{
    // numStudents numProjs numMentors
    // numOfPrefProj numOfPrefMentors --PrefProj-- --ProfMentors--  \
    // numOfPrefProj numOfPrefMentors --PrefProj-- --ProfMentors--   |
    // numOfPrefProj numOfPrefMentors --PrefProj-- --ProfMentors--   | numStudents times
    // numOfPrefProj numOfPrefMentors --PrefProj-- --ProfMentors--   |
    // numOfPrefProj numOfPrefMentors --PrefProj-- --ProfMentors--  /

    // 4 3 3
    // 2 2      1 3     2 1
    // 2 2      2 3     1 2
    // 2 2      1 3     1 2
    // 2 1      1 3     3

    int Prj, Std, Mtr;
    scanf("%d %d %d", &Std, &Prj, &Mtr);

    int V = (Prj+Std+Mtr) * 2 + 2;
    int ** matrix = (int**) malloc(V * sizeof(int*));

    // INITIALISE CAPACITY TO ZERO
    for(int i = 0; i < V; i++)
    {
        matrix[i] = (int*) malloc(V * sizeof(int));
        for(int j = 0; j < V; j++)
        {
            matrix[i][j] = 0;
        }
    }

    // CONNECT SOURCE 0 TO PROJECT IN
    for(int i = 1; i <= Prj; i++)
    {
        matrix[0][i] = 1;
    }

    // CONNECT PROJECT IN TO PROJECT OUT
    for(int i = 1; i <= Prj; i++)
    {
        matrix[i][i+Prj] = 1;
    }

    // CONNECT STUDENT IN TO STUDENT OUT
    int studentStart = 2*Prj;
    for(int i = studentStart + 1; i <= studentStart + Std; i++)
    {
        matrix[i][i+Std] = 1;
    }

    // CONNECT MENTOR IN TO MENTOR OUT
    int mentorStart = 2*(Prj+Std);
    for(int i = mentorStart + 1; i<= mentorStart + Mtr; i++)
    {
        matrix[i][i+Mtr] = 1;
    }

    // CONNECT MENTOR OUT TO SINK
    int mentorOutStart = 2*(Prj+Std)+Mtr;
    for(int i = mentorOutStart + 1; i<=mentorOutStart + Mtr; i++)
    {
        matrix[i][V-1] = 1;
    }

    // CONNECT THE GRAPH
    studentStart++;
    for (int i = 0; i < Std; i++)
    {
        int PrjConnections, PrjIndex;
        int MtrConnections, MtrIndex;
        scanf("%i", &PrjConnections); //project out --> student in
        scanf("%i", &MtrConnections); //mentor in --> student out
        for (int j = 0; j < PrjConnections; j++)
        {
            scanf("%i", &PrjIndex);
            matrix[PrjIndex + Prj][studentStart] = 1;
        }
        for (int j = 0; j < MtrConnections; j++)
        {
            scanf("%i", &MtrIndex);
            matrix[studentStart + Std][MtrIndex + 2*Prj + 2*Std] = 1;
        }
        studentStart++;
    }

    //apply Ford Fulkerson algorithm
    // use DFS or BFS to find a path
    int ANSWER = matching(matrix, V);
    printf("%d\n", ANSWER);
    return 0;
}

void insertAdjVertex(ListNode** AdjList,int vertex)
{
    ListNode *temp;
    if(*AdjList==NULL)
    {
        *AdjList = (ListNode *)malloc(sizeof(ListNode));
        (*AdjList)->vertex = vertex;
        (*AdjList)->next = NULL;
    }
    else
    {
        temp = (ListNode *)malloc(sizeof(ListNode));
        temp->vertex = vertex;
        temp->next = *AdjList;
        *AdjList = temp;
    }
}
void enqueue(Queue *qPtr, int vertex)
{
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    if(newNode==NULL) exit(0);

    newNode->vertex = vertex;
    newNode->next = NULL;

    if(isEmptyQueue(*qPtr)) qPtr->head=newNode;
    else qPtr->tail->next = newNode;

    qPtr->tail = newNode;
    qPtr->size++;
}


void removeAdjVertex(ListNode** AdjList,int vertex)
{
    ListNode *temp, *preTemp;
    if(*AdjList != NULL)
    {
        if((*AdjList)->vertex ==vertex)
        {//first node
            temp = *AdjList;
            *AdjList = (*AdjList)->next;
            free(temp);
        return;
        }
        preTemp = *AdjList;
        temp = (*AdjList)->next;
        while(temp!=NULL && temp->vertex != vertex)
        {
            preTemp= temp;
            temp = temp->next;
        }
        preTemp->next = temp->next;
        free(temp);
    }
}


int dequeue(Queue *qPtr)
{
    if(qPtr==NULL || qPtr->head==NULL)
    { //Queue is empty or NULL pointer
        return 0;
    }
    else
    {
        QueueNode *temp = qPtr->head;
        qPtr->head = qPtr->head->next;
        if(qPtr->head == NULL) //Queue is emptied
        qPtr->tail = NULL;

        free(temp);
        qPtr->size--;
        return 1;
    }
}

int getFront(Queue q)
{
    return q.head->vertex;
}

int isEmptyQueue(Queue q)
{
    if(q.size==0) return 1;
    else return 0;
}

void removeAllItemsFromQueue(Queue *qPtr)
{
    while(dequeue(qPtr));
}

void printQ(QueueNode *cur)
{
    if(cur==NULL) printf("Empty");

    while (cur != NULL)
    {
        printf("%d ", cur->vertex);
        cur = cur->next;
    }
    printf("\n");
}

void push(Stack *sPtr, int vertex)
{
    StackNode *newNode;
    newNode= malloc(sizeof(StackNode));
    newNode->vertex = vertex;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr)
{
    if(sPtr==NULL || sPtr->head==NULL)
    {
        return 0;
    }
    else
    {
        StackNode *temp = sPtr->head;
        sPtr->head = sPtr->head->next;
        free(temp);
        sPtr->size--;
        return 1;
    }
}

int isEmptyStack(Stack s)
{
    if(s.size==0) return 1;
    else return 0;
}

int peek(Stack s)
{
    return s.head->vertex;
}

void removeAllItemsFromStack(Stack *sPtr)
{
    while(pop(sPtr));
}

//*/
