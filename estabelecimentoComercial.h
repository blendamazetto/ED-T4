#include "ponto.h"

#ifndef __ESTABELECIMENTO_H
#define __ESTABELECIMENTO_H

//Define "Estabelecimento" como um void pointer
typedef void* Estabelecimento;

Estabelecimento criaEstabelecimento(char cnpj[], char cpf[], char codt[], char cep[], char face[], double num, char nome[], Ponto ponto);

char* getEstabelecimentoCnpj(Estabelecimento estabelecimento);

char* getEstabelecimentoCpf(Estabelecimento estabelecimento);

char* getEstabelecimentoCodt(Estabelecimento estabelecimento);

char* getEstabelecimentoCep(Estabelecimento estabelecimento);

char* getEstabelecimentoFace(Estabelecimento estabelecimento);

double getEstabelecimentoNum(Estabelecimento estabelecimento);

char* getEstabelecimentoNome(Estabelecimento estabelecimento);

Ponto getEstabelecimentoPonto(Estabelecimento estabelecimento);

void setEstabelecimentoCnpj(Estabelecimento estabelecimento, char cnpj[]);

void setEstabelecimentoCpf(Estabelecimento estabelecimento, char cpf[]);

void setEstabelecimentoCodt(Estabelecimento estabelecimento, char codt[]);

void setEstabelecimentoCep(Estabelecimento estabelecimento, char cep[]);

void setEstabelecimentoFace(Estabelecimento estabelecimento, char face[]);

void setEstabelecimentoNum(Estabelecimento estabelecimento, double num);

void setEstabelecimentoNome(Estabelecimento estabelecimento, char nome[]);

void setEstabelecimentoPonto(Estabelecimento estabelecimento, Ponto ponto);

void swapEstabelecimento(Estabelecimento e1, Estabelecimento e2);

#endif
