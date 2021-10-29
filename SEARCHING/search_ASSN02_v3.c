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

    // check whether it is duplicate.
    // don't care about key comparisons in this case because just return -1
    for (int i = 0; i < TABLESIZE; i++)
    {
        if (hashTable[i].indicator == USED && hashTable[i].key == key)
        {
            return -1;
        }
    }

    int hashNum = 0;
    int curSlot;
    int slotToInsert = -1;
    int numComparisons = 0;
    //confirm no duplicate, so the first slot we find is the slot to insert already
    while (1==1)
    {
        curSlot = hash1(key + hashNum*hash2(key));
        hashNum++;

        //can input, we done
        if (hashTable[curSlot].indicator == EMPTY)
        {
            slotToInsert = curSlot;
            break;
        }

        //slot taken, need reroll
        if (hashTable[curSlot].indicator == USED)
        {
            numComparisons++;
            continue;
        }

        //slot is deleted and the key used to be here, we done
        if (hashTable[curSlot].indicator == DELETED && hashTable[curSlot].key == key)
        {
            slotToInsert = curSlot;
            numComparisons++;
            break;
        }

        //slot is deleted but the key was not here, we still need to keep checking to confirm that it doesn't appear again
        //note: it doesn't because we already confirmed no duplicates earlier on. we just do this for the number of comparisons
        if (hashTable[curSlot].indicator == DELETED && hashTable[curSlot].key != key)
        {
            slotToInsert = curSlot;
            numComparisons++;
        }
    }
    if (slotToInsert == -1)
    {
        return TABLESIZE+1;
    }
    else
    {
        hashTable[slotToInsert].indicator = USED;
        hashTable[slotToInsert].key = key;
        return numComparisons;
    }
}

int HashDelete(int key, HashSlot hashTable[])
{
    // check whether the key exists in the hashtable.
    // don't care about key comparisons in this case because just return -1
    int exists = 0;
    for (int i = 0; i < TABLESIZE; i++)
    {
        if (hashTable[i].indicator == USED && hashTable[i].key == key)
        {
            exists = 1;
        }
    }
    if (!exists) return -1;


    int hashNum = 0;
    int curSlot;
    int slotToDelete = -1;
    int numComparisons = 0;
    //confirm exists
    while (1==1)
    {
        curSlot = hash1(key + hashNum*hash2(key));
        hashNum++;

        //can delete, we done
        if (hashTable[curSlot].indicator == USED && hashTable[curSlot].key == key)
        {
            slotToDelete = curSlot;
            numComparisons++;
            break;
        }
    }


    if (slotToDelete == -1)
    {
        return -1;
    }
    else
    {
        hashTable[slotToDelete].indicator = DELETED;
        hashTable[slotToDelete].key = key;
        return numComparisons+1;
    }
}
//*/
