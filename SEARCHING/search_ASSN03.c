/*
#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 37
#define PRIME     13

enum Marker {EMPTY,USED};

typedef struct _slot{
    int key;
    enum Marker indicator;
    int next;
} HashSlot;

int HashInsert(int key, HashSlot hashTable[]);
int HashFind(int key, HashSlot hashTable[]);

int hash(int key)
{
    return (key % TABLESIZE);
}

int main()
{
    int opt;
    int i;
    int key;
    int index;
    HashSlot hashTable[TABLESIZE];

    for(i=0;i<TABLESIZE;i++){
        hashTable[i].next = -1;
        hashTable[i].key = 0;
        hashTable[i].indicator = EMPTY;
    }

    printf("============= Hash Table ============\n");
    printf("|1. Insert a key to the hash table  |\n");
    printf("|2. Search a key in the hash table  |\n");
    printf("|3. Print the hash table            |\n");
    printf("|4. Quit                            |\n");
    printf("=====================================\n");

    printf("Enter selection: ");
    scanf("%d",&opt);
    while(opt>=1 && opt <=3){
        switch(opt){
        case 1:
            printf("Enter a key to be inserted:\n");
            scanf("%d",&key);
            index = HashInsert(key,hashTable);
            if(index <0)
                printf("Duplicate key\n");
            else if(index < TABLESIZE)
                printf("Insert %d at index %d\n",key, index);
            else
                printf("Table is full.\n");
            break;
        case 2:
            printf("Enter a key for searching in the HashTable:\n");
            scanf("%d",&key);
            index = HashFind(key, hashTable);

            if(index!=-1)
                printf("%d is found at index %d.\n",key,index);
            else
                printf("%d is not found.\n",key);
            break;

        case 3:
            printf("index:\t key \t next\n");
            for(i=0;i<TABLESIZE;i++) printf("%d\t%d\t%d\n",i, hashTable[i].key,hashTable[i].next);
            break;
        }
        printf("Enter selection: ");
        scanf("%d",&opt);
    }
    return 0;
}

int HashInsert(int key, HashSlot hashTable[])
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
    int hasEmpty = 0;
    int hasDuplicate = 0;
    for (int i = 0; i < TABLESIZE; i++)
    {
        if (hashTable[i].key == key) hasDuplicate = 1;
        if (hashTable[i].key == 0) hasEmpty = 1;
    }
    if (!hasEmpty) return TABLESIZE+1;
    if (hasDuplicate) return -1;



    int originalIndex = hash(key);

    //original slot unoccupied, very good
    if (hashTable[originalIndex].key == 0)
    {
        hashTable[originalIndex].key = key;
        return originalIndex;
    }

    //original slot occupied, time to find where to slot
    int newIndex = originalIndex+1 % TABLESIZE;
    while (hashTable[newIndex].key != 0)
    {
        newIndex = (newIndex+1) % TABLESIZE;
        //printf("newindex %d", newIndex);
    }

    //slot in at the new index
    hashTable[newIndex].key = key;

    //put in the new index in the next
    int putAlready = 0;
    int indexToPutNext = originalIndex;

    while (putAlready == 0)
    {
        if (hashTable[indexToPutNext].next == -1)
        {
            hashTable[indexToPutNext].next = newIndex;
            putAlready = 1;
        }
        else
        {
            indexToPutNext = hashTable[indexToPutNext].next;
        }
    }
    return newIndex;
}

int HashFind(int key, HashSlot hashTable[])
{
    int i;
    for (i = 0; i < TABLESIZE; i++)
    {
        if (hashTable[i].key == key) break;
    }

    if (i==TABLESIZE) return -1;
    else return i;
}
//*/
