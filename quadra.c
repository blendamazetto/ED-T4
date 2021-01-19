#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quadra.h"

typedef struct q{

    char cep[20];
    double x;
    double y;
    double w;
    double h;
    char sw[20];
    char cfill[20];
    char cstrk[20];
    char sombra[20];

}QuadraStruct;

Quadra criaQuadra(char cep[], double x, double y, double w, double h, char sw[], char cfill[], char cstrk[], char sombra[])
{
    QuadraStruct* quadra = (QuadraStruct*) malloc(sizeof(QuadraStruct));

    strcpy(quadra->cep, cep);
    quadra->x = x;
    quadra->y = y;
    quadra->w = w;
    quadra->h = h;
    strcpy(quadra->sw, sw);
    strcpy(quadra->cfill, cfill);
    strcpy(quadra->cstrk, cstrk);
    strcpy(quadra->sombra, sombra);
    
    return quadra;
}

char* getQuadraCep(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->cep;
}

double getQuadraX(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->x;
}

double getQuadraY(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->y;
}

double getQuadraW(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->w;
}

double getQuadraH(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->h;
}

char* getQuadraSw(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->sw;
}

char* getQuadraCfill(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->cfill;
}

char* getQuadraCstrk(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->cstrk;
}

char* getQuadraSombra(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->sombra;
}


void setQuadraCep(Quadra quadra, char cep[])
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    strcpy(quad->cep, cep);

}

void setQuadraX(Quadra quadra, double x)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    quad->x = x;
}

void setQuadraY(Quadra quadra, double y)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    quad->y = y;
}

void setQuadraW(Quadra quadra, double w)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    quad->w = w;
}

void setQuadraH(Quadra quadra, double h)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    quad->h = h;
}

void setQuadraSw(Quadra quadra, char sw[])
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    strcpy(quad->sw, sw);
}

void setQuadraCfill(Quadra quadra, char cfill[])
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    strcpy(quad->cfill, cfill);
}

void setQuadraCstrk(Quadra quadra, char cstrk[])
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    strcpy(quad->cstrk, cstrk);
}

void setQuadraSombra(Quadra quadra, char sombra[])
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    strcpy(quad->sombra, sombra);
}
