#include "lista.h"

#ifndef __HASHTABLE__
#define __HASHTABLE__

//Define "Hash" como um void pointer
typedef void* Hash;

unsigned int hash (char key[], int tamanhoHash);

Hash createHashTable(int tamanhoHash);

void insertHashTable(Info info, char key[], int tamanho, Hash hashtable);

void printHashTable(int tamanho, Hash hashtable);

Hash searchHashTable(char key[], Hash hashtable, int tamanho);

void removeNodeHashTable(char key[], Hash hashtable, int tamanho);

char* criaInfo(char info[]);

char* getHashInfo(Info info);

void deleteHashTable(Hash hashtable, int tamanho);



#endif