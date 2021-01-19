#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lerGeo.h"

void lerGeo(char arqGeo[], char nomeSvgGeo[], Lista listasObjetos[])
{

    FILE *geo;
    int id1, idPosto = 0;
    double raio, distancia = 0;
    int max[5] = {1000, 1000, 1000, 1000, 1000};
    char id2[20];
    char txt[255];
    int n = 0;
    char tipo[10];
    char cep[20];
    double x, y, h, w, d;
    char expessura[20];
    char hidraExpessura[20];
    char semaExpessura[20];
    char quaExpessura[20];
    char radioExpessura[20];
    char circleExpessura[20];
    char rectExpessura[20];
    char borda[22]; 
    char preenchimento[22];
    char Qborda[22] = "black", Qpreenchimento[22] = "red";
    char RBborda[22] = "black", RBpreenchimento[22] = "green";
    char Sborda[22] = "black", Spreenchimento[22] = "red";
    char Hborda[22] = "black", Hpreenchimento[22] = "yellow";

    hidraExpessura[0] = '2';
    semaExpessura[0] = '2';
    quaExpessura[0] = '2';
    radioExpessura[0] = '2';
    circleExpessura[0] = '2';
    rectExpessura[0] = '2';

    geo = fopen(arqGeo,"r");

    if(geo == NULL)
    {
        printf("\nERRO\nArquivo .geo nao pode ser aberto\n");
        exit(1);
    }
    
    iniciaSvg(nomeSvgGeo);
    
    while(!feof(geo))
    {
        fscanf(geo, "%s", tipo);

        if(strcmp(tipo, "nx")==0)
        {
            fscanf(geo,"%d\n", &max[0]);
        }
        else if(strcmp(tipo, "c")==0)
        {
            fscanf(geo,"%d %lf %lf %lf %s %s\n", &id1, &raio, &x, &y, borda, preenchimento);
            Circulo circulo = criaCirculo(id1, raio, x, y, circleExpessura, borda, preenchimento);
            insert(listasObjetos[0], circulo);
            
            
            n++;
        }
        else if(strcmp(tipo, "r")==0)
        {
            fscanf(geo,"%d %lf %lf %lf %lf %s %s\n", &id1, &w, &h, &x, &y, borda, preenchimento);
            Retangulo retangulo = criaRetangulo(id1, w, h, x, y, rectExpessura, borda, preenchimento);
            insert(listasObjetos[1], retangulo);
            
            n++;
        }
        else if(strcmp(tipo, "t")==0)
        {
            fscanf(geo,"%d %lf %lf %s %s", &id1, &x, &y, borda, preenchimento);
            fgets(txt, 255, geo);
            Texto texto = criaTexto(id1, x, y, borda, preenchimento, txt);
            insert(listasObjetos[2], texto);
        }
        else if(strcmp(tipo, "q")==0)
        {
            fscanf(geo,"%s %lf %lf %lf %lf\n", cep, &x, &y, &w, &h);
            Quadra quadra = criaQuadra(cep, x, y, w, h, quaExpessura, Qpreenchimento, Qborda, "null");
            insert(listasObjetos[3], quadra);
            
            n++;
        }
        else if(strcmp(tipo, "h")==0)
        {
            fscanf(geo,"%s %lf %lf\n", id2, &x, &y);
            Hidrante hidrante = criaHidrante(id2, x, y, hidraExpessura, Hpreenchimento, Hborda);
            insert(listasObjetos[4], hidrante);

            n++;
        }
        else if(strcmp(tipo, "s")==0)
        {
            fscanf(geo,"%s %lf %lf\n", id2, &x, &y);
            Semaforo semaforo = criaSemaforo(id2, x, y, semaExpessura, Spreenchimento, Sborda);
            insert(listasObjetos[5], semaforo);
            
            n++;
        }
        else if(strcmp(tipo, "rb")==0)
        {
            fscanf(geo,"%s %lf %lf\n", id2, &x, &y);
            Radiobase radioBase = criaRadiobase(id2, x, y, radioExpessura, RBpreenchimento, RBborda);
            insert(listasObjetos[6], radioBase);
            
            n++;
        }
        else if(strcmp(tipo, "cq")==0)
        {
            fscanf(geo,"%s %s %s\n", expessura, preenchimento, borda);

            strcpy(quaExpessura, expessura);
            strcpy(Qpreenchimento, preenchimento);
            strcpy(Qborda, borda); 

            n++;
        }
        else if(strcmp(tipo, "ch")==0)
        {
            fscanf(geo,"%s %s %s\n", expessura, preenchimento, borda);

            strcpy(hidraExpessura, expessura);
            strcpy(Hpreenchimento, preenchimento);
            strcpy(Hborda, borda);

            n++;
        }
        else if(strcmp(tipo, "cr")==0)
        {
            fscanf(geo,"%s %s %s\n", expessura, preenchimento, borda);

            strcpy(radioExpessura, expessura);
            strcpy(RBpreenchimento, preenchimento);
            strcpy(RBborda, borda);

            n++;
        }
        else if(strcmp(tipo, "cs")==0)
        {
            fscanf(geo,"%s %s %s\n", expessura, preenchimento, borda);
            
            strcpy(semaExpessura, expessura);
            strcpy(Spreenchimento, preenchimento);
            strcpy(Sborda, borda);

            n++;
        }
        else if(strcmp(tipo, "sw")==0)
        {
            fscanf(geo,"%s %s\n", circleExpessura, rectExpessura); 

            n++;
        }
        else if(strcmp(tipo, "ps")==0)
        {
            fscanf(geo,"%lf %lf\n",&x, &y);
            Posto posto = criaPosto(idPosto, x, y, distancia);
            insert(listasObjetos[7], posto);
        
            idPosto++;
            n++;
        }
        else if(strcmp(tipo, "dd")==0)
        {
            fscanf(geo,"%lf %lf %lf %lf %lf\n", &x, &y, &w, &h, &d);
            Densidade densidade = criaDensidade(x, y, w, h, d);
            insert(listasObjetos[8], densidade);

            n++;
        }
    }
    
    sombras(listasObjetos);
    gerarSvgGeo(listasObjetos, nomeSvgGeo);
    finalizaSvg(nomeSvgGeo);
    fclose(geo);

}

void lerEc(char arqEc[])
{
    FILE *ec;
    ec = fopen(arqEc,"r");

    if(ec == NULL)
    {
        printf("\nERRO\nArquivo .geo nao pode ser aberto\n");
        exit(1);
    }

    char tipo[10];
    char codt[20];
    char descricao[255];
    char cnpj[25];
    char cpf[20];
    char cep[20];
    char face[2];
    double num;
    char nome[255];


    while(!feof(ec))
    {
        fscanf(ec, "%s", tipo);

        if(strcmp(tipo, "t")==0)
        {
            fscanf(ec,"%s %s\n", codt, descricao);
        }

        else if(strcmp(tipo, "e")==0)
        {
            fscanf(ec,"%s %s %s %s %s %lf %s\n", cnpj, cpf, codt, cep, face, &num, nome);
        }
    }

    fclose(ec);
}

void lerPm(char arqPm[])
{
    FILE *pm;
    pm = fopen(arqPm,"r");

    if(pm == NULL)
    {
        printf("\nERRO\nArquivo .geo nao pode ser aberto\n");
        exit(1);
    }

    char tipo[10];
    char cpf[20];
    char nome[100];
    char sobrenome[100];
    char sexo[2];
    char nascimento[11];
    char face[2];
    double num;
    char compl[20];
    char cep[20];

    while(!feof(pm))
    {   
        fscanf(pm, "%s", tipo);

        if(strcmp(tipo, "p")==0)
        {
            fscanf(pm,"%s %s %s %s %s\n", cpf, nome, sobrenome, sexo, nascimento);
        }

        else if(strcmp(tipo, "m")==0)
        {
            fscanf(pm, "%s %s %s %lf %s", cpf, cep, face, &num, compl);
        }
    }

    fclose(pm);
}