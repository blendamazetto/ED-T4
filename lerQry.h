#ifndef __leitura_h
#define __leitura_h
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "hidrante.h"
#include "radiobase.h"
#include "semaforo.h"
#include "quadra.h"
#include "lista.h"
#include "svg.h"
#include "qry.h"
#include "busca.h"
#include "posto.h"
#include "densidade.h"
#include "textoNumerico.h"
#include "linha.h"
#include "casos.h"
#include "poligono.h"


/*
*Le o arquivo Qry e realiza suas funçcoes
*precisa do nome do arquivo qry e a lista
*não retorna nada
*/
void lerQry (char saidaQry[], Lista listasObjetos[], char arqQry[], Lista listasQry);

#endif