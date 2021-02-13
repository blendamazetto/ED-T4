#include "lista.h"

#ifndef __STACK__
#define __STACK__

//Define "Lista" como um void pointer
typedef void* Pilha;

Pilha createStack();

void insertStack(Pilha p, Info info);

Info removeStack(Pilha p);

No criarNo();

int isEmptyStack(Pilha pilha);

No getTopo(Pilha p);

int getTamnhoStack(Pilha p);

void deleteStack(Pilha p);

Info getInfo(No elemento);

No getAnterior(No elemento);

#endif