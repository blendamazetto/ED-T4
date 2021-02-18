#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qry3.h"

void cv (QuadTree arvoresObjetos[], double n, char cep[], char face[], double num, Lista listasQry[])
{
    double x, y;

    if(getNodeByIdQt(arvoresObjetos[3],cep) != NULL)
    {
        Info q = getInfoByIdQt(arvoresObjetos[3], cep);

        if(strcmp(face, "N"))
        {
            x = getQuadraX(q) + num;
            y = getQuadraY(q) + getQuadraH(q);
        }

        else if(strcmp(face, "S"))
        {
            x = getQuadraX(q) + num;
            y = getQuadraY(q);
        }

        else if(strcmp(face, "L"))
        {
            x = getQuadraX(q);
            y = getQuadraY(q) + num;
        }

        else if(strcmp(face, "O"))
        {
            x = getQuadraX(q) + getQuadraW(q);
            y = getQuadraY(q) + num;
        }
    }
  
    Casos caso = criaCasos(n, x, y, face, num, cep);
    insereQt(arvoresObjetos[10], getCasosPonto(caso), caso);

    Retangulo ret = criaRetangulo("0", 10, 10, x, y, "2", "orange", "orange");
    insert(listasQry[1], ret);

    TextoNumerico textNum = criaTextoNumerico(x, y, "white", "white", n);
    insert(listasQry[0], textNum);
}

void soc(QuadTree arvoresObjetos[], int k, char cep[], char face[], double num, FILE* saida, Lista listasQry[])
{
    double x, y;

    if(getNodeByIdQt(arvoresObjetos[3], cep) != NULL)
    {
        Info q = getInfoByIdQt(arvoresObjetos[3], cep);

        if(strcmp(face, "N"))
        {
            x = getQuadraX(q) + num;
            y = getQuadraY(q) + getQuadraH(q);
        }

        else if(strcmp(face, "S"))
        {
            x = getQuadraX(q) + num;
            y = getQuadraY(q);
        }

        else if(strcmp(face, "L"))
        {
            x = getQuadraX(q);
            y = getQuadraY(q) + num;
        }

        else if(strcmp(face, "O"))
        {
            x = getQuadraX(q) + getQuadraW(q);
            y = getQuadraY(q) + num;
        }
    }

    Retangulo ret = criaRetangulo("0", 10, 10, x, y, "2", "white", "blue");
    insert(listasQry[1], ret);

    Lista l = create();
    percorreLarguraQt(arvoresObjetos[7],insertList,l);

    double vet[tamanhoDaLista(l)];
    int size = 0;

    No node;
    for(node = getFirst(l); node != NULL; node = getNext(node))
    {
        Info po = getInfo(node);

        double dist = distancia(x, y, getPostoX(po), getPostoY(po));
        setPostoDistancia(po, dist);
        vet[size] = dist;
        size++;
    }

    shellSort(vet, tamanhoDaLista(l));

    No aux;
    Info inf;

    for(int cont=0; cont<k; cont++)
    {
        for(aux = getFirst(l); aux != NULL; aux = getNext(aux))
        {   
            inf = getInfo(aux);

            if(getPostoDistancia(inf) == vet[cont])
            {
                Linha lin = criaLinha(x, y, getPostoX(inf), getPostoY(inf), "black");
                insert(listasQry[7], lin);

                fprintf(saida,"%lf %lf\n", getPostoX(inf), getPostoY(inf));
            }
        }
    }
}


