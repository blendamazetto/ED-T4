#ifndef __QRY_h
#define __QRY_h
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "hidrante.h"
#include "radiobase.h"
#include "semaforo.h"
#include "quadra.h"
#include "posto.h"
#include "densidade.h"
#include <math.h>
#include "textoNumerico.h"
#include "linha.h"
#include "poligono.h"
#include "casos.h"
#include "ponto.h"
#include "lista.h"
#include "stack.h"
#include "quadtree.h"

double distancia(double x1, double y1, double x2, double y2);

int pontoInternoCirc(Ponto ponto, double xCirc, double yCirc, double r);

int pontoInternoRet(Ponto ponto, double xRet, double yRet, double w, double h);

int orientacao(Ponto a, Ponto b, Ponto c);

int comparar(Ponto p0, Ponto a, Ponto b);

No partition(Lista l, No primeiro, No ultimo, Ponto (*getPonto)(Info), void (*swap)(Info, Info));

void quickSortList(Lista l, No primeiro, No ultimo, Ponto (*getPonto)(Info), void (*swap)(Info, Info));

Lista convexHull(Lista list, Ponto (*getPonto)(Info), void (*swap)(Info, Info));

Ponto defaultGetPonto(Ponto info);

void balancearQuadTree(QuadTree qt, Lista l, Ponto (*getPonto)(void*), void (*swap)(void*, void*));

Ponto descobrirPonto(char cep[], char face[], double num, QuadTree tree);

float max(float n1, float n2);

float min(float n1, float n2);

void retanguloxCirculo(Info circ, Info ret, FILE* saida, Lista listasQry[]);

void circuloInt(Info c1, Info c2, FILE* saida, Lista listasQry[]);

void retanguloInt(Info r1, Info r2, FILE* saida, Lista listasQry[]);

#endif