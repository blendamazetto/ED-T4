#include "lista.h"
#include "quadtree.h"
#include "qry.h"

#ifndef __QRY2_h
#define __QRY2_h

void dq(FILE *saida, QuadTree arvoresObjetos[], int flag, char id[], double r, Lista listasQry[]);

void del(FILE* saida, QuadTree arvoresObjetos[], char j[], Lista listasQry[]);

void cbq(QuadTree arvoresObjetos[], double x, double y, double r, char corb[], FILE* saida);

void crd(QuadTree arvoresObjetos[], char id[], FILE* saida);

void car (QuadTree arvoresObjetos[], double x, double y, double w, double h, FILE* saida, Lista listasQry[]);

#endif