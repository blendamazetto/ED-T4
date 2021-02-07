#ifndef __STACK__
#define __STACK__

//Define "No" como um void pointer
typedef void* No;

//Define "Lista" como um void pointer
typedef void* Pilha;

//Define "Info" como um void pointer
typedef void* Info;

Pilha createStack();

void insertStack(Pilha p, Info info) ;

void removeStack(Pilha p) ;

No criarNo();

int isEmptyStack(Pilha p);

No getTopo(Pilha p);

int getTamnhoStack(Pilha p);

void deleteStack(Pilha p);

Info getInfo(No elemento);

No getAnterior(No elemento);

#endif