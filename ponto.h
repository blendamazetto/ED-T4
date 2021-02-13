#include "qry.h"

#ifndef __PONTO__
#define __PONTO__

typedef void* Ponto;

Ponto createPonto(double x, double y);

double getPontoX(Ponto ponto);

double getPontoY(Ponto ponto);

void setPontoX(Ponto ponto, double x);

void setPontoY(Ponto ponto, double y);

void swapPonto(Ponto p1, Ponto p2);

void atribuirPonto(Ponto *p1, Ponto *p2);

double getPontoDist(Ponto pont, double x, double y);

#endif