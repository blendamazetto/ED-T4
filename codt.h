#ifndef __CODT_H
#define __CODT_H

//Define "Circulo" como um void pointer
typedef void* Codt;

Codt criaCodt(char codt[], char descricao[]);

char* getCodtCodt(Codt c);

void setCodtCodt(Codt c, char codt[]);

char* getCodtDescricao(Codt c);

void setCodtDescricao(Codt c, char descricao[]);

#endif