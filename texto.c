#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"

typedef struct t{

    int i;
    double x;
    double y;
    char corb[20];
    char corp[20];
    char texto[20];

}TextoStruct;

Texto criaTexto(int i, double x, double y, char corb[], char corp[], char texto[255])
{
    TextoStruct* text = (TextoStruct*) malloc(sizeof(TextoStruct));

    text->i = i;
    text->x = x;
    text->y = y;
    strcpy(text->corb, corb);
    strcpy(text->corp, corp);
    strcpy(text->texto, texto);

    return text;
}

int getTextoI(Texto texto)
{
    TextoStruct* text = (TextoStruct*) texto;
    return text->i;
}

double getTextoX(Texto texto)
{
    TextoStruct* text = (TextoStruct*) texto;
    return text->x;
}

double getTextoY(Texto texto)
{
    TextoStruct* text = (TextoStruct*) texto;
    return text->y;
}

char* getTextoCorb(Texto texto)
{
    TextoStruct* text = (TextoStruct*) texto;
    return text->corb;
}

char* getTextoCorp(Texto texto)
{
    TextoStruct* text = (TextoStruct*) texto;
    return text->corp;
}

char* getTextoTxto(Texto texto)
{
    TextoStruct* text = (TextoStruct*) texto;
    return text->texto;
}

void setTextoI(Texto texto, int i)
{
    TextoStruct* text = (TextoStruct*) texto;
    text->i = i;
}

void setTextoX(Texto texto, double x)
{
    TextoStruct* text = (TextoStruct*) texto;
    text->x = x;
}

void setTextoY(Texto texto, double y)
{
    TextoStruct* text = (TextoStruct*) texto;
    text->y = y;
}

void setTextoCorb(Texto texto, char corb[])
{
    TextoStruct* text = (TextoStruct*) texto;
    strcpy(text->corb, corb);
}

void setTextoCorp(Texto texto, char corp[])
{
    TextoStruct* text = (TextoStruct*) texto;
    strcpy(text->corp, corp);
}

void setTextoTxto(Texto texto, char txto[])
{
    TextoStruct* text = (TextoStruct*) texto;
    strcpy(text->texto, txto);
}