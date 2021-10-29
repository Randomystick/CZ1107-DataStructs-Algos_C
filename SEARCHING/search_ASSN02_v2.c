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
    int numComparisons, hashNum;
    numComparisons = hashNum = 0;
    int curSlot;

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


    int inserted = 0;
    //confirm no duplicate
    while (hashNum<TABLESIZE)
    {
        curSlot = hash1(key + hashNum*hash2(key));

        //can input, we done
        if (inserted == 0 && (hashTable[curSlot].indicator == EMPTY))
        {
            hashTable[curSlot].key = key;
            hashTable[curSlot].indicator = USED;
            inserted = 1;
            break;
        }

        else if (inserted == 0 && (hashTable[curSlot].indicator == DELETED))
        {
            hashTable[curSlot].key = key;
            hashTable[curSlot].indicator = USED;
            inserted = 1;
        }

        else if (hashTable[curSlot].indicator == DELETED && inserted == 1)
        {
            numComparisons++;
        }

        //slot taken, need do again
        else if (hashTable[curSlot].indicator == USED && inserted == 0)
        {
            numComparisons++;
        }

        hashNum++;
    }
    return numComparisons;
}

int HashDelete(int key, HashSlot hashTable[])
{
//////////////////////////////
//////////// TODO ////////////
//////////////////////////////
    int numComparisons = 0;
    int curSlot;

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

    int deleted = 0;
    // confirm exists for us to delete
    while (deleted == 0)
    {
        curSlot = hash1(key + numComparisons*hash2(key));

        //can delete, we done
        if (hashTable[curSlot].indicator == USED && hashTable[curSlot].key == key)
        {
            hashTable[curSlot].indicator = DELETED;
            deleted = 1;
        }

        numComparisons++;
    }
    return numComparisons;
}
//*/
