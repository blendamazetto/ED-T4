#include "ponto.h"

#ifndef __MORADOR_H
#define __MORADOR_H

//Define "Estabelecimento" como um void pointer
typedef void* Morador;

Morador criaMorador(char cpf[], char face[], char compl[], char cep[], double num, Ponto ponto);

char* getMoradorCpf(Morador morador);

char* getMoradorCep(Morador morador);

char* getMoradorFace(Morador morador);

double getMoradorNum(Morador morador);

char* getMoradorCompl(Morador morador);

Ponto getMoradorPonto(Morador morador);

void setMoradorCpf(Morador morador, char cpf[]);

void setMoradorPonto(Morador morador, Ponto ponto);

void setMoradorCep(Morador morador, char cep[]);

void setMoradorFace(Morador morador, char face[]);

void setMoradorCompl(Morador morador, char compl[]);

void setMoradorNum(Morador morador, double num);

void swapMorador(Morador m1, Morador m2);

#endif
