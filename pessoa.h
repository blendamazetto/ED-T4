#include "ponto.h"

#ifndef __PESSOA_H
#define __PESSOA_H

//Define "Estabelecimento" como um void pointer
typedef void* Pessoa;

Pessoa criaPessoa(char cpf[], char nome[], char sobrenome[], char sexo[], char nascimento[]);

char* getPessoaCpf(Pessoa pessoa);

char* getPessoaNome(Pessoa pessoa);

char* getPessoaSobrenome(Pessoa pessoa);

char* getPessoaSexo(Pessoa pessoa);

char* getPessoaNascimento(Pessoa pessoa);

void setPessoaCpf(Pessoa pessoa, char cpf[]);

void setPessoaNome(Pessoa pessoa, char nome[]);

void setPessoaNascimento(Pessoa pessoa, char nascimento[]);

void setPessoaSexo(Pessoa pessoa, char sexo[]);

void setPessoaSobrenome(Pessoa pessoa, char sobrenome[]);

void swapPessoa(Pessoa p1, Pessoa p2);

#endif
