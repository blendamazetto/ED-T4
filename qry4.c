#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qry4.h"

void m(QuadTree arvoresObjetos[], FILE* saida, Hash tabelas[], char cep[], Lista listasObjetos[])
{
    Info info = searchHashTable(cep, tabelas[3], tamanho(listasObjetos[3]));

    if(info == NULL)
    {
        fprintf(saida,"INEXISTENTE\n");
        return;
    }

    double x = getPontoX(getQuadraPonto(info));
    double y = getPontoY(getQuadraPonto(info));
    double x2 = x + getQuadraW(info);
    double y2 = y + getQuadraH(info);

    Lista moradores = nosDentroRetanguloQt(arvoresObjetos[9], x, y, x2, y2);

    for(No node = getFirst(moradores); node != NULL; node = getNext(node))
    {
        Info inf = getInfoQt(arvoresObjetos[9], getInfo(node));
        Info pessoa = searchHashTable(getMoradorCpf(inf), tabelas[2], tamanho(listasObjetos[10]));

        fprintf(saida,"NOME: %s %s CPF: %s NASCIMENTO: %s SEXO: %s ", getPessoaNome(pessoa), getPessoaSobrenome(pessoa), getPessoaCpf(pessoa), getPessoaNascimento(pessoa), getPessoaSexo(pessoa));
        fprintf(saida,"CEP: %s FACE: %s NUM: %lf COMPL: %s\n", getMoradorCpf(inf), getMoradorFace(inf), getMoradorNum(inf), getMoradorCompl(inf));
    }
    removeList(moradores, NULL);
}

void dm(QuadTree arvoresObjetos[], FILE* saida, Lista listasQry[], Hash tabelas[], char cpf[], Lista listasObjetos[])
{
    Info morador = getInfoByIdQt(arvoresObjetos[9], cpf);
    Info pessoa = searchHashTable(cpf, tabelas[2], tamanho(listasObjetos[10]));

    if(morador == NULL || pessoa == NULL)
    {
        fprintf(saida,"INEXISTENTE\n");
        return;
    }

    double x = getPontoX(getMoradorPonto(morador));
    double y = getPontoY(getMoradorPonto(morador));

    fprintf(saida,"NOME: %s %s CPF: %s NASCIMENTO: %s SEXO: %s ", getPessoaNome(pessoa), getPessoaSobrenome(pessoa), getPessoaCpf(pessoa), getPessoaNascimento(pessoa), getPessoaSexo(pessoa));
    fprintf(saida,"CEP: %s FACE: %s NUM: %lf COMPL: %s\n", getMoradorCep(morador), getMoradorFace(morador), getMoradorNum(morador), getMoradorCompl(morador));
    
    Linha l = criaLinha(x, y ,x, 0, "black");
    insert(listasQry[2], l);

    char texto[1000];

    sprintf(texto,"CPF:%s NOME:%s CEP:%s FACE:%s NUM:%lf",getMoradorCpf(morador), getPessoaNome(pessoa), getMoradorCep(morador), getMoradorFace(morador), getMoradorNum(morador));

    Texto text = criaTexto("0", x, 0, "black", "black", texto);
    insert(listasQry[4], text);
}

void de(QuadTree arvoresObjetos[], FILE* saida, Hash tabelas[], char cnpj[], Lista listasObjetos[])
{
    Info e = getInfoByIdQt(arvoresObjetos[8], cnpj);

    if(e == NULL)
    {
        fprintf(saida,"INEXISTENTE\n");
        return;
    }

    char cpf[20];
    strcpy(cpf, getEstabelecimentoCpf(e));
    Info pessoa = searchHashTable(cpf, tabelas[2], tamanho(listasObjetos[10]));
    char descricao[255];
    strcpy(descricao, searchHashTable(getEstabelecimentoCodt(e), tabelas[1], tamanho(listasObjetos[12])));

    if(e == NULL || pessoa == NULL)
    {
        return;
    }

    fprintf(saida, "ESTABELECIMENTO - NOME: %s CNPJ: %s CODT: %s DESCRICAO: %s CEP: %s FACE: %s NUM: %lf \n", getEstabelecimentoNome(e),getEstabelecimentoCnpj(e), getEstabelecimentoCodt(e), descricao, getEstabelecimentoCep(e), getEstabelecimentoFace(e), getEstabelecimentoNum(e));
    fprintf(saida,"DONO - NOME: %s %s CPF: %s NASCIMENTO: %s SEXO: %s \n", getPessoaNome(pessoa), getPessoaSobrenome(pessoa), getPessoaCpf(pessoa), getPessoaNascimento(pessoa), getPessoaSexo(pessoa));
}

void mud(QuadTree arvoresObjetos[], FILE* saida, Lista listasQry[], Hash tabelas[], char cpf[], char cep[], char face[], double num, char compl[], Lista listasObjetos[])
{
    Info morador = getInfoByIdQt(arvoresObjetos[9], cpf);
    Info pessoa = searchHashTable(cpf, tabelas[2], tamanho(listasObjetos[10]));
    Ponto p = descobrirPonto(cep, face, num, arvoresObjetos[3]);

    if(morador == NULL || pessoa == NULL)
    {
        fprintf(saida,"INEXISTENTE\n");
        return;
    }

    Linha l = criaLinha(getPontoX(getMoradorPonto(morador)), getPontoY(getMoradorPonto(morador)), getPontoX(p), getPontoY(p), "red");
    insert(listasQry[2], l);

    Circulo c = criaCirculo("0", 8, getPontoX(getMoradorPonto(morador)), getPontoY(getMoradorPonto(morador)), "3", "white", "red");
    insert(listasQry[3], c);

    Circulo c1 = criaCirculo("0", 8, getPontoX(p), getPontoY(p), "3", "white", "blue");
    insert(listasQry[3], c1);

    char auxCep[20], auxFace[2], auxCompl[20];
    double AuxNum = getMoradorNum(morador);
    strcpy(auxCep, getMoradorCep(morador));
    strcpy(auxFace, getMoradorFace(morador));
    strcpy(auxCompl, getMoradorCompl(morador));

    setMoradorCep(morador, cep);
    setMoradorFace(morador, face);
    setMoradorNum(morador, num);
    setMoradorCompl(morador, compl);
    setMoradorPonto(morador, p);

    fprintf(saida,"DONO - NOME: %s %s CPF: %s NASCIMENTO: %s SEXO: %s \n", getPessoaNome(pessoa), getPessoaSobrenome(pessoa), getPessoaCpf(pessoa), getPessoaNascimento(pessoa), getPessoaSexo(pessoa));
    fprintf(saida,"ENDERECO ANTIGO: CEP: %s FACE: %s NUM: %lf COMPL: %s\n", auxCep, auxFace, AuxNum, auxCompl);
    fprintf(saida,"ENDERECO NOVO: CEP: %s FACE: %s NUM: %lf COMPL: %s\n", getMoradorCep(morador), getMoradorFace(morador), getMoradorNum(morador), getMoradorCompl(morador));
}
