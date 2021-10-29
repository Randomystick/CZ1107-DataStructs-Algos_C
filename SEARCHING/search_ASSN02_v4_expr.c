/*
#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 37
#define PRIME     13

enum Marker {EMPTY,USED,DELETED};

typedef struct _slot{
    int key;
    enum Marker indicator;
} HashSlot;

int HashInsert(int key, HashSlot hashTable[]);
int HashDelete(int key, HashSlot hashTable[]);


int hash1(int key);
int hash2(int key);

int main()
{
    int opt;
    int i;
    int key;
    int comparison;
    HashSlot hashTable[TABLESIZE];

    for(i=0;i<TABLESIZE;i++){
        hashTable[i].indicator = EMPTY;
        hashTable[i].key = 0;
    }

    printf("============= Hash Table ============\n");
    printf("|1. Insert a key to the hash table  |\n");
    printf("|2. Delete a key from the hash table|\n");
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
            comparison = HashInsert(key,hashTable);
            if(comparison <0)
                printf("Duplicate key\n");
            else if(comparison < TABLESIZE)
                printf("Insert: %d Key Comparisons: %d\n",key, comparison);
            else
                printf("Key Comparisons: %d. Table is full.\n",comparison);
            break;
        case 2:
            printf("Enter a key to be deleted:\n");
            scanf("%d",&key);
            comparison = HashDelete(key,hashTable);
            if(comparison <0)
                printf("%d does not exist.\n", key);
            else if(comparison <= TABLESIZE)
                printf("Delete: %d Key Comparisons: %d\n",key, comparison);
            else
                printf("Error\n");
            break;
        case 3:
            for(i=0;i<TABLESIZE;i++) printf("%d: %d %c\n",i, hashTable[i].key,hashTable[i].indicator==DELETED?'*':' ');
            break;
        }
        printf("Enter selection: ");
        scanf("%d",&opt);
    }
    return 0;
}

int hash1(int key)
{
    return (key % TABLESIZE);
}

int hash2(int key)
{
    return (key % PRIME) + 1;
}

int HashInsert(int key, HashSlot hashTable[])
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
    // check whether it is duplicate
    int duplicate = 0;
    for (int i = 0; i < TABLESIZE; i++)
    {
        if (hashTable[i].indicator == USED && hashTable[i].key == key)
        {
            duplicate = 1;
        }
    }
    if (duplicate) return -1;

    int hasEmpty = 0;
    for (int i = 0; i<TABLESIZE; i++)
    {
        if (hashTable[i].key == 0)
        {
            hasEmpty = 1;
        }
    }
    if (hasEmpty == 0) return TABLESIZE;


    int numComparisons, hashNum;
    numComparisons = hashNum = 0;
    int curSlot, curSlotSaved;
    for (hashNum = 0; hashNum < TABLESIZE; hashNum++)
    {
        curSlot = hash1(key + hashNum*hash2(key));

        //can input, we done
        if (hashTable[curSlot].indicator == EMPTY)
        {
            hashTable[curSlot].key = key;
            hashTable[curSlot].indicator = USED;
            return numComparisons;
        }

        else if (hashTable[curSlot].indicator == USED)
        {
            numComparisons++;
        }

        else if (hashTable[curSlot].indicator == DELETED)
        {
            curSlotSaved = curSlot;
            for(;hashNum < TABLESIZE; hashNum++)
            {
                curSlot = hash1(key + hashNum*hash2(key));
                if (hashTable[curSlot].indicator == USED) numComparisons = numComparisons+1;

                if (hashTable[curSlot].indicator == EMPTY)
                {
                    hashTable[curSlotSaved].key = key;
                    hashTable[curSlotSaved].indicator = USED;
                    return numComparisons;
                }
            }
            hashTable[curSlotSaved].key = key;
            hashTable[curSlotSaved].indicator = USED;
            return numComparisons;
        }
    }
    return -69;
}

int HashDelete(int key, HashSlot hashTable[])
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
    // check whether it exists
    int exists = 0;
    for (int i = 0; i < TABLESIZE; i++)
    {
        if (hashTable[i].indicator == USED && hashTable[i].key == key)
        {
            exists = 1;
        }
    }
    if (!exists) return -1;

    int numComparisons = 0;
    int curSlot;
    int hashNum = 0;
    for (hashNum = 0; hashNum < TABLESIZE; hashNum++)
    {
        curSlot = hash1(key+hashNum*hash2(key));

        if (hashTable[curSlot].indicator == USED)
        {
            numComparisons++;
            if (hashTable[curSlot].key == key)
            {
                hashTable[curSlot].indicator = DELETED;
                return numComparisons;
            }
        }
    }
    return -69;
}
//*/
