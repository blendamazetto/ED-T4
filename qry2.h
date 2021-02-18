#include "lista.h"
#include "quadtree.h"
#include "qry.h"

#ifndef __QRY2_h
#define __QRY2_h

void dq(FILE *saida, QuadTree arvoresObjetos[], int flag, char id[], double r, Lista listasQry[]);

void del(FILE* saida, QuadTree arvoresObjetos[], char j[], Lista listasQry[]);

#endif