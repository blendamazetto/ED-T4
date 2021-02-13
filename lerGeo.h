#ifndef __LERGEO_H
#define __LERGEO_H
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "hidrante.h"
#include "radiobase.h"
#include "semaforo.h"
#include "quadra.h"
#include "lista.h"
#include "svg.h"
#include "posto.h"
#include "densidade.h"
#include "estabelecimentoComercial.h"
#include "pessoa.h"
#include "morador.h"
#include "quadtree.h"
#include "hashtable.h"
#include "codt.h"

/*
*Le o arquivo geo
*precisa do nome do arquivo e a lista para salvar as informacoes
*não retorna nada
*/
void lerGeo(char arqGeo[], char nomeSvgGeo[], Lista listasObjetos[], QuadTree arvoresObjetos[], Hash tabelas[]);

void lerEc(char arqEc[], Lista listasObjetos[], QuadTree arvoresObjetos[], Hash tabelas[]);

void lerPm(char arqPm[], Lista listasObjetos[], QuadTree arvoresObjetos[], Hash tabelas[]);

#endif