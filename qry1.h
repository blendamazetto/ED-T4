#include "lista.h"
#include "quadtree.h"
#include "qry.h"

#ifndef __QRY1_h
#define __QRY1_h

void o(char j[], char k[], QuadTree arvoresObjetos[], Lista listasQry[], FILE* saida);

void i (char j[], double x, double y, QuadTree arvoresObjetos[], Lista listasQry[], FILE* saida);

void pnt (char j[], char corb[], char corp[], QuadTree arvoresObjetos[], FILE* saida);

void delf(FILE* saida, QuadTree arvoresObjetos[], char j[]);

#endif