#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quadtree.h"
#include "lista.h"
#include "ponto.h"
#include "queue.h"
#include "qry.h"

#define nw 0
#define ne 1
#define sw 2
#define se 3

typedef struct node
{
    struct node *children[4];
    struct node *parent;
    Ponto ponto;
    QtInfo info;

}NodeStruct;

typedef struct quadtree
{
    NodeStruct* root;
    char* (*fun)(QtInfo);

}QuadtreeStruct;

QuadTree criaQt(funcGetChave f)
{
    QuadtreeStruct* qt = (QuadtreeStruct*)malloc(sizeof(QuadtreeStruct));
    qt->root = NULL;
    qt->fun = f;
    return qt;
}

void dentroRetanguloQt(QuadTree qt, NodeStruct* node, Lista l, double x1, double y1, double x2, double y2, void* (*fun)(void*, void*))
{
    if(node == NULL)
    {
        return;
    }
    if(pontoInternoRet(node->ponto, x1, y1, x2 - x1, y2 - y1))
    {
        if(fun != NULL)
        {
            insert(l,fun(qt, node));
        }
        else
        {
            insert(l,node);
        }
    }
    for(int i = 0; i < 4; i++)
    {
        dentroRetanguloQt(qt, node->children[i], l, x1, y1, x2, y2, fun);
    }
}

QtInfo getInfoQt(QuadTree qt, QtNo pNo){
    NodeStruct* node = (NodeStruct*) pNo;
    qt = qt;
    return node->info;
}

char* getChaveQt(QuadTree qt, QtNo pNo)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = (NodeStruct*) pNo;

    return quadtree->fun(getInfoQt(quadtree, node));
}

Lista chavesDentroRetanguloQt(QuadTree qt, double x1, double y1, double x2, double y2)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = quadtree->root;

    Lista l = create();
    dentroRetanguloQt(qt, node, l, x1, y1, x2, y2, (void*(*)(void*, void*))getChaveQt);
    return l;

}

void dentroCirculoQt(QuadTree qt, NodeStruct* node, Lista l, double x, double y, double r, void* (*fun)(void*, void*))
{
    if(node == NULL)
    {
        return;
    }
    if(pontoInternoCirc(node->ponto, x, y, r))
    {
        if(fun != NULL)
        {
            insert(l,fun(qt, node));
        }
        else
        {
            insert(l,node);
        }
        
    }
    for(int i = 0; i < 4; i++)
    {
        dentroCirculoQt(qt, node->children[i], l, x, y, r, fun);
    }
}

Lista chavesDentroCirculoQt(QuadTree qt,double x, double y, double r)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = quadtree->root;

    Lista l = create();
    dentroCirculoQt(qt, node, l, x, y, r, (void*(*)(void*, void*))getChaveQt);
    return l;
}

Ponto getPontoQt(QuadTree qt, QtNo pNo)
{
    NodeStruct* node = (NodeStruct*) pNo;
    return node->ponto;
}

Lista pontosDentroRetanguloQt(QuadTree qt, double x1, double y1, double x2, double y2)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = quadtree->root;

    Lista l = create();

    dentroRetanguloQt(qt, node, l, x1, y1, x2, y2, getPontoQt);
    return l;

}

Lista pontosDentroCirculoQt(QuadTree qt,double x, double y, double r)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = quadtree->root;

    Lista l = create();
    dentroCirculoQt(qt, node, l, x, y, r, getPontoQt);
    return l;
}

Lista nosDentroRetanguloQt(QuadTree qt, double x1, double y1, double x2, double y2)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = quadtree->root;

    Lista l = create();
    dentroRetanguloQt(qt, node, l, x1, y1, x2, y2, NULL);
    return l;

}

Lista nosDentroCirculoQt(QuadTree qt,double x, double y, double r)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = quadtree->root;

    Lista l = create();
    dentroCirculoQt(qt, node, l, x, y, r, NULL);
    return l;
}

void percorreProfundidade(QuadTree qt, NodeStruct* node, funcVisita f,ExtraInfo ei)
{
    if(node == NULL)
    {
        return;
    }
    
    f(getInfoQt(qt, node),ei);

    for(int i = 0; i < 4; i++)
    {
        percorreProfundidade(qt, node->children[i],f,ei);
    }
}

void percorreProfundidadeQt(QuadTree qt,funcVisita f,ExtraInfo ei)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = quadtree->root;

    percorreProfundidade(qt, node, f, ei);
}

void percorreLarguraQt(QuadTree qt,funcVisita f,ExtraInfo ei)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    Fila fila = createQueue();

    NodeStruct* aux;

    if(quadtree->root == NULL)
    {
        return;
    }

    insertQueue(fila, quadtree->root);
    
    do
    {
        aux = removeQueue(fila);
        for(int i = 0; i < 4; i++)
        {
            if(aux->children[i] != NULL)
            {
                insertQueue(fila, aux->children[i]);
            }
        }
        f(getInfoQt(quadtree, aux),ei);

    }while(!isEmptyQueue(fila));
}

QtNo insereQt(QuadTree qt,Ponto p, QtInfo pInfo)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = (NodeStruct*)malloc(sizeof(NodeStruct));
    NodeStruct* aux = quadtree->root; 

    node->ponto = p;
    node->info = pInfo;
    node->parent = NULL;

    for(int i = 0; i < 4; i++)
    {
        node->children[i] = NULL;
    }
    if(aux == NULL)
    {
        quadtree->root = node;
        return node;
    }
    Ponto pAux;

    do
    {
        pAux = aux->ponto;
        if(getPontoX(p) >= getPontoX(pAux))
        {
            if(getPontoY(p) >= getPontoY(pAux))
            {
                if(aux->children[ne] == NULL)
                {
                    aux->children[ne] = node;
                    node->parent = aux;
                }
                else
                {
                    aux = aux->children[ne];
                }
            }
            else
            {
                if(aux->children[nw] == NULL)
                {
                    aux->children[nw] = node;
                    node->parent = aux;
                }
                else
                {
                    aux = aux->children[nw];
                }
            }
        }
        else
        {
            if(getPontoY(p) >= getPontoY(pAux))
            {
                if(aux->children[se] == NULL)
                {
                    aux->children[se] = node;
                    node->parent = aux;
                }
                else
                {
                    aux = aux->children[se];
                }
            }
            else
            {
                if(aux->children[sw] == NULL)
                {
                    aux->children[sw] = node;
                    node->parent = aux;
                }
                else
                {
                    aux = aux->children[sw];
                }
            }
        }
    }while(node->parent == NULL);

    return node;
}

void insere(QuadtreeStruct* quadtree, NodeStruct* node)
{
    NodeStruct* aux = quadtree->root;
    node->parent = NULL;
    for(int i = 0; i < 4; i++)
    {
        node->children[i] = NULL;
    }
    if(aux == NULL)
    {
        quadtree->root = node;
        return;
    }
    do
    {
        Ponto pAux = aux->ponto;
        Ponto p = node->ponto;
        if(getPontoX(p) >= getPontoX(pAux))
        {
            if(getPontoY(p) >= getPontoY(pAux))
            {
                if(aux->children[ne] == NULL)
                {
                    aux->children[ne] = node;
                    node->parent = aux;
                }
                else
                {
                    aux = aux->children[ne];
                }
            }
            else
            {
                if(aux->children[nw] == NULL)
                {
                    aux->children[nw] = node;
                    node->parent = aux;
                }
                else
                {
                    aux = aux->children[nw];
                }
            }
        }
        else
        {
            if(getPontoY(p) >= getPontoY(pAux))
            {
                if(aux->children[se] == NULL)
                {
                    aux->children[se] = node;
                    node->parent = aux;
                }
                else
                {
                    aux = aux->children[se];
                }
            }
            else
            {
                if(aux->children[sw] == NULL)
                {
                    aux->children[sw] = node;
                    node->parent = aux;
                }
                else
                {
                    aux = aux->children[sw];
                }
            }
        }
    }while(node->parent == NULL);
}

QtNo getNodeById(QuadTree qt, QtNo no, char* chave){
    NodeStruct* node = (NodeStruct*) no;
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    if(strcmp(quadtree->fun(getInfoQt(qt, node)), chave) == 0){
        return node;
    }
    QtNo aux;
    for(int i = 0; i < 4; i++){
        if(node->children[i] != NULL)
        {
            aux = getNodeById(qt,node->children[i],chave);
            if(aux != NULL)
            {
                return aux;
            }
        }
    }
    return NULL;
}

QtNo getNodeByIdQt(QuadTree qt, char* chave){
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    if(quadtree->root == NULL){
        return NULL;
    }
    return getNodeById(qt, quadtree->root, chave);
}

QtInfo removeNoQt(QuadTree qt,QtNo pNo){
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = (NodeStruct*) pNo;
    NodeStruct* aux;
    int i;
    QtInfo info;
    Fila fila = createQueue();
    if(node->parent == NULL){
        for(i = 0; i < 4; i++){
            if(node->children[i] != NULL){
                insertQueue(fila, node->children[i]);
            }
        }
        quadtree->root = NULL;
    }
    else{
        for(i = 0; i < 4; i++){
            if(node->children[i] != NULL){
                if(node->parent->children[i] == NULL){
                    node->parent->children[i] = node->children[i];
                }
                else{
                    insertQueue(fila, node->children[i]);
                }
            }
        }
        for(i = 0; i < 4; i++){
            if(node->parent->children[i] == node){
                node->parent->children[i] = NULL;
                break;
            }
        }
    }
    while(!isEmptyQueue(fila)){
        aux = removeQueue(fila);
        for(i = 0; i < 4; i++){
            if(aux->children[i] != NULL){
                insertQueue(fila, aux->children[i]);
            }
        }
        insere(quadtree,aux);
    }
    info = getInfoQt(quadtree, node);
    free(node);
    free(fila);
    return info;
}

QtNo getNoQt(QuadTree qt, double x, double y)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* aux = quadtree->root;
    Ponto p;

    while (aux != NULL)
    {
        p = aux->ponto;
        if(x == getPontoX(p) && y == getPontoY(p))
        {
            return aux;
        }
        if(x > getPontoX(p))
        {
            if(y > getPontoY(p))
            {

                aux = aux->children[ne];
            }
            else
            {
                aux = aux->children[nw];
            }
        }
        else
        {
            if(y > getPontoY(p))
            {
                aux = aux->children[se];
            }
            else
            {
                aux = aux->children[sw];
            }
        }
    }
    return NULL;
}

QtInfo getInfoById(QuadTree qt, QtNo no, char* chave)
{
    NodeStruct* node = (NodeStruct*) no;
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;

    if(strcmp(quadtree->fun(getInfoQt(qt, node)), chave) == 0)
    {
        return getInfoQt(qt, node);
    }
    QtInfo aux;
    for(int i = 0; i < 4; i++)
    {
        if(node->children[i] != NULL)
        {
            aux = getInfoById(qt,node->children[i],chave);
            if(aux != NULL)
            {
                return aux;
            }
        }
    }
    return NULL;
}

QtInfo getInfoByIdQt(QuadTree qt, char* chave)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;

    return getInfoById(qt, quadtree->root, chave);
}

void desalocaNos(NodeStruct* node)
{
    if(node == NULL)
    {
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        desalocaNos(node->children[i]);
    }
    if(node->ponto != node->info)
    {
        free(node->ponto);
    }
    free(node->info);
    free(node);
}

void desalocaQt(QuadTree qt)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    desalocaNos(quadtree->root);

    free(qt);
}