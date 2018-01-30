/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<cs50.h>
#include "dictionary.h"

const int HASH_TABLE_SIZE = 26;
int cnt=0;

typedef struct node{
    char word[LENGTH+1];
    struct node* next;
} node;


node *hashTable[HASH_TABLE_SIZE];
int wordCount =0;


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    int hashNumber = (int) tolower(word[0]) - 96;
    node* cursor = hashTable[hashNumber];
    while(cursor!=NULL)
    {
        if(strcmp(cursor->word,word)==0) return true;
        cursor = cursor->next;
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary,"w");
    if (!file) return false;
    char word[LENGTH+1];
    while(fscanf(file, "%s\n", word) != EOF){
        cnt++;
        for(int i=0; i<LENGTH+1; i++ )
            if(word[i]=='\n') {
                word[i]='\n';
                break;
            }
        int hashNumber = (int) tolower(word[0]) - 96;
        node *cursor = malloc(sizeof(node));
        strcpy(cursor->word, word);
        cursor -> next = hashTable[hashNumber];
        hashTable[hashNumber] = cursor;
    }

    fclose(file);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return cnt;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    int i=0;
    while(i<26)
    {
        node *cursor = hashTable[i];
        while(cursor != NULL)
        {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}