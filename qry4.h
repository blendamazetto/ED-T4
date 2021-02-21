#include "lista.h"
#include "quadtree.h"
#include "qry.h"
#include "hashtable.h"
#include "morador.h"
#include "pessoa.h"
#include "estabelecimentoComercial.h"

#ifndef __QRY4_h
#define __QRY4_h

void m(QuadTree arvoresObjetos[], FILE* saida, Hash tabelas[], char cep[], Lista listasObjetos[]);

void dm (QuadTree arvoresObjetos[], FILE* saida, Lista listasQry[], Hash tabelas[], char cpf[], Lista listasObjetos[]);

void de(QuadTree arvoresObjetos[], FILE* saida, Hash tabelas[], char cnpj[], Lista listasObjetos[]);

void mud(QuadTree arvoresObjetos[], FILE* saida, Lista listasQry[], Hash tabelas[], char cpf[], char cep[], char face[], double num, char compl[], Lista listasObjetos[]);

void epgl (QuadTree arvoresObjetos[], FILE* saida, Lista listasQry[], Hash tabelas[], double x, double y, double w, double h, Lista listasObjetos[], char tp[]);

#endif