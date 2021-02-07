#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct node
{
    Info info;
    struct node* anterior;

}NoStruct;

typedef struct pilha
{
    NoStruct *topo;
    int tamanho;

}PilhaStruct;

Pilha createStack()
{
    PilhaStruct* pilha = (PilhaStruct*) malloc(sizeof(PilhaStruct));
    pilha->topo = NULL;
    pilha->tamanho = 0;

    return pilha;
}

void insertStack(Pilha p, Info info) 
{
    PilhaStruct* pilha = (PilhaStruct*) p;
    NoStruct* node = (NoStruct*) malloc(sizeof(NoStruct));

    node->info = info;

    if(pilha->topo == NULL)
    {
        pilha->topo = node;
        node->anterior = NULL;
    }
    else
    {
        node->anterior = pilha->topo;
        pilha->topo = node;
    }
    
    pilha->tamanho++;
}

void removeStack(Pilha p) 
{
    PilhaStruct* pilha = (PilhaStruct*) p;
    NoStruct* node = (NoStruct*) malloc(sizeof(NoStruct));

    node = pilha->topo;
    pilha->topo = node->anterior;
    
    free(node);

    pilha->tamanho--;
}

No criarNo()
{
    NoStruct* node = (NoStruct*) malloc(sizeof(NoStruct));
    node->info = NULL;

    return node;
}

int isEmptyStack(Pilha p)
{
    PilhaStruct* pilha = (PilhaStruct*) p;

    if(pilha->tamanho == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }  
}

No getTopo(Pilha p)
{
    PilhaStruct* pilha = (PilhaStruct*) p;

    return pilha->topo;
}

int getTamnhoStack(Pilha p)
{
    PilhaStruct* pilha = (PilhaStruct*) p;

    return pilha->tamanho;
}

void deleteStack(Pilha p)
{
    PilhaStruct* pilha = (PilhaStruct*) p;

    for(int i=0; i<pilha->tamanho; i++)
    {
        removeStack(pilha);
    }
}

Info getInfo(No elemento)
{
    NoStruct* node = (NoStruct*) elemento;

    return node->info;
}

No getAnterior(No elemento)
{
    NoStruct* node = (NoStruct*) elemento;

    return node->anterior;

}



