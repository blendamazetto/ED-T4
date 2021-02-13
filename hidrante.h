#include "ponto.h"

#ifndef __HIDRANTE_H
#define __HIDRANTE_H

//Define "Hidrante" como um void pointer
typedef void* Hidrante;

/*
*Cria uma struct hidrante
*Precisa dos parametros necessarios para a criação de um hidrante
*Retorna um void pointer para a struct hidrante
*/
Hidrante criaHidrante(char id[], double x, double y, char sw[], char cfill[], char cstrk[]);

/*
*Obtem o id de um hidrante
*Precisa de um void pointer hidrante como parametro
*Retorna o id de um hidrante
*/
char* getHidranteId(Hidrante hidrante);

/*
*Obtem o eixo x do hidrante
*Precisa de um void pointer hidrante como parametro
*Retorna o eixo x de um hidrante
*/
double getHidranteX(Hidrante hidrante);

/*
*Obtem o eixo y do hidrante
*Precisa de um void pointer hidrante como parametro
*Retorna o eixo y de um hidrante
*/
double getHidranteY(Hidrante hidrante);

/*
*Obtem a sw do hidrante
*Precisa de um void pointer hidrante como parametro
*Retorna a sw(Sw) de um hidrante
*/
char* getHidranteSw(Hidrante hidrante);

/*
*Obtem a cor de stroke do hidrante
*Precisa de um void pointer hidrante como parametro
*Retorna a cor de stroke(Cfill) de um hidrante
*/
char* getHidranteCfill(Hidrante hidrante);

/*
*Obtem a cor de fill do hidrante
*Precisa de um void pointer hidrante como parametro
*Retorna a cor de fill(Cstrk) de um hidrante
*/
char* getHidranteCstrk(Hidrante hidrante);

/*
*Armazena um valor que é passado como parametro no Id do hidrante também passado por parametro
*Precisa de um void pointer hidrante e de uma string 
*Não retorna nada
*/
void setHidranteId(Hidrante hidrante, char id[]);

/*
*Armazena um valor que é passado como parametro no x do hidrante também passado por parametro
*Precisa de um void pointer hidrante e de um valor double
*Não retorna nada
*/
void setHidranteX(Hidrante hidrante, double x);

/*
*Armazena um valor que é passado como parametro no y do hidrante também passado por parametro
*Precisa de um void pointer hidrante e de um valor double
*Não retorna nada
*/
void setHidranteY(Hidrante hidrante, double y);

/*
*Armazena um valor que é passado como parametro na sw do hidrante também passado por parametro
*Precisa de um void pointer hidrante e de uma string 
*Não retorna nada
*/
void setHidranteSw(Hidrante hidrante, char sw[]);

/*
*Armazena um valor que é passado como parametro na cor de stroke do hidrante também passado por parametro
*Precisa de um void pointer hidrante e de uma string 
*Não retorna nada
*/
void setHidranteCfill(Hidrante hidrante, char cfill[]);

/*
*Armazena um valor que é passado como parametro na cor de prenchimento do hidrante também passado por parametro
*Precisa de um void pointer hidrante e de uma string 
*Não retorna nada
*/
void setHidranteCstrk(Hidrante hidrante, char cstrk[]);

Ponto getHidrantePonto(Hidrante hidrante);

void setHidrantePonto(Hidrante hidrante, Ponto ponto);

void swapHidrante(Hidrante hidrante1, Hidrante hidrante2);

void desalocarPontoHidrante(Hidrante hidrante);


#endif