#include "lista.h"
#include "quadtree.h"
#include "qry.h"

#ifndef __QRY3_h
#define __QRY3_h

void cv (QuadTree arvoresObjetos[], double n, char cep[], char face[], double num, Lista listasQry[]);

void soc(QuadTree arvoresObjetos[], int k, char cep[], char face[], double num, FILE* saida, Lista listasQry[]);

void ci(FILE* saida, QuadTree arvoresObjetos[], double x, double y, double r, Lista listasQry[], FILE* saidaSvgQry);

#endif