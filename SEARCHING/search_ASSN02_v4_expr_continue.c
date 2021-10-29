///*
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

//Question 2
int HashInsert(int key, HashSlot hashTable[])
{
   //Write your code here
    int comparison = 0;
    int index;
    int count = 0;
    int storedIndex;
    for(count = 0; count < TABLESIZE; count++)
    {
        index = hash1(key + (count * hash2(key)));
        if(hashTable[index].indicator == EMPTY)
        { //empty then insert
            hashTable[index].key = key;
            hashTable[index].indicator = USED;
            return comparison;
        }

        else if(hashTable[index].indicator == USED)
        {
            comparison ++;
            if(hashTable[index].key == key)
            { //duplicate return
                return -1;
            }
        }

        else if(hashTable[index].indicator == DELETED)
        {
            storedIndex = index;
            for(; count<TABLESIZE; count++)
            { //check for duplicate if indicator is DELETED
                index = hash1(key +(count * hash2(key)));
                if((hashTable[index].indicator == USED) && (hashTable[index].key == key))
                { //duplicate return
                    return -1;
                }
                if(hashTable[index].indicator == USED) // carry on searching
                    comparison++;

                if(hashTable[index].indicator == EMPTY)
                {
                    hashTable[storedIndex].key = key;
                    hashTable[storedIndex].indicator = USED;
                    return comparison;
                }
            }
            hashTable[storedIndex].key = key;
            hashTable[storedIndex].indicator = USED;
            return comparison;
        }
    } return TABLESIZE;
}

int HashDelete(int key, HashSlot hashTable[])
{
   //Write your code here
    int index;
    int comparison = 0;
    int count = 0;
    int hashNum = 0;
    for (int i = 0; i < TABLESIZE; i++)
    {
        hashNum += count+i;
    }
    for (count = 0; count < TABLESIZE; count++)
    {
        index = hash1(key + (count*hash2(key)));

        if(hashTable[index].indicator == USED)
        {
            comparison++;
            if(hashTable[index].key == key)
            {
                hashTable[index].indicator = DELETED;
                return comparison;
            }
        }
        else if(hashTable[index].indicator == EMPTY)
        {
            return -1;
        }
    } return -1; // key doesn't exist
}
