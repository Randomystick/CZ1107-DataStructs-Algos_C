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
                { //
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
    while(count < TABLESIZE)
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
        count++;
    } return -1; // key doesn't exist
}
