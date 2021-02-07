#include "stack.h"

#ifndef __FILA__
#define __FILA__

//Define "Lista" como um void pointer
typedef void* Fila;

Fila createQueue();

void insertQueue(Fila f, Info info);

void removeQueue(Fila f);

int isEmptyQueue(Fila f);

No getPrimeiro(Fila f);

int getTamanhoQueue(Fila f);

void deleteQueue(Fila f);

No getProximo(No elemento);

#endif