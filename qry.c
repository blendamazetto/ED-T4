#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qry.h"
#include "lista.h"

void car(Lista listasObjetos[], double x, double y, double w, double h, char saidaSvg[], FILE* saida, Lista listasQry[])
{
    FILE *svgQry = fopen(saidaSvg, "a");

    double areaTotal=0;
    No node;

    for(node = getFirst(listasObjetos[3]); node != NULL; node = getNext(node))
    {
        Info q = getInfo(node);
    
        if (getQuadraX(q) >= x && getQuadraY(q) >= y && getQuadraX(q) + getQuadraW(q) <= x + w && getQuadraY(q) + getQuadraH(q) <= y + h)
        {
            areaTotal=areaTotal+(getQuadraH(q)*getQuadraW(q));

            fprintf(saida, "%s %lf\n", getQuadraCep(q),(getQuadraH(q)*getQuadraW(q)));

            TextoNumerico textNum = criaTextoNumerico((getQuadraX(q)+getQuadraW(q)/2), (getQuadraY(q)+getQuadraH(q)/2), "black", "black", (getQuadraW(q)*getQuadraH(q)));
            insert(listasQry[0], textNum);
        }
    }   

    fprintf(saida, "%lf\n",areaTotal);

    Retangulo ret = criaRetangulo(0, w, h, x ,y , "2.5", "black", "none");
    insert(listasQry[1], ret);

    Linha lin = criaLinha(x, y, x, 0, "black");
    insert(listasQry[2], lin);

    TextoNumerico textNum2 = criaTextoNumerico(x, 0, "black", "black", areaTotal);
    insert(listasQry[0], textNum2);

    fclose(svgQry);
}

double distancia(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
}

void cbq(Lista listasObjetos[], double x, double y, double r, char corb[], FILE* saida)
{
    No node; 

    for(node = getFirst(listasObjetos[3]); node != NULL; node = getNext(node))
    {
        Info q = getInfo(node);
    
        if(distancia(getQuadraX(q),getQuadraY(q),x,y) <= r && distancia(getQuadraX(q) + getQuadraW(q) ,getQuadraY(q) + getQuadraH(q),x,y) <= r)
        {
            if(distancia(getQuadraX(q) + getQuadraW(q), getQuadraY(q),x,y) <= r && distancia(getQuadraX(q), getQuadraY(q) + getQuadraH(q),x,y) <= r)
            {
                setQuadraCstrk(q, corb);
                fprintf(saida, "%s\n", getQuadraCep(q));
            }
        }
    } 
}

void i(Lista listasObjetos[], int j,  double x, double y, char saidaSvg[], FILE* saida, Lista listasQry[])
{
    FILE *svgQry = fopen(saidaSvg, "a");
    No node;

    for(node = getFirst(listasObjetos[0]); node != NULL; node = getNext(node))
    {
        Info c = getInfo(node);
        if(getCirculoI(c)==j)
        {
            float dist = sqrt(pow(x - getCirculoX(c),2) + pow(y - getCirculoY(c),2));

            if (getCirculoR(c) >= dist)
            {
                fprintf(saida,"circulo interno\n");

                Circulo circ = criaCirculo(0, 10, x, y, "1", "blue", "blue");
                insert(listasQry[3], circ);

                Linha lin = criaLinha(x, y, getCirculoX(c), getCirculoY(c), "blue");
                insert(listasQry[2], lin);
            }
            else
            {
                fprintf(saida,"circulo nao interno\n");

                Circulo circ = criaCirculo(0, 10, x, y, "1", "magenta", "magenta");
                insert(listasQry[3], circ);

                Linha lin = criaLinha(x, y, getCirculoX(c), getCirculoY(c), "magenta");
                insert(listasQry[2], lin);
            }
        }
    } 

    for(node = getFirst(listasObjetos[1]); node != NULL; node = getNext(node))
    {
        Info r = getInfo(node);
        if(getRetanguloI(r)==j)
        {
            float difx = x - getRetanguloX(r);
            float dify = y - getRetanguloY(r);

            if(difx >= 0 && difx <= getRetanguloW(r) && dify >= 0 && dify <= getRetanguloH(r))
            {
                fprintf(saida,"retangulo interno\n");

                Circulo circ = criaCirculo(0, 10, x, y, "1", "blue", "blue");
                insert(listasQry[3], circ);

                fprintf(svgQry,"\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n",x ,y ,getRetanguloX(r)+getRetanguloW(r)/2 ,getRetanguloY(r)+getRetanguloH(r)/2 ,"blue");

            }
            else
            {
                fprintf(saida,"retangulo nao interno\n");

                Circulo circ = criaCirculo(0, 10, x, y, "1", "magenta", "magenta");
                insert(listasQry[3], circ);

                fprintf(svgQry,"\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n",x ,y ,getRetanguloX(r)+getRetanguloW(r)/2 ,getRetanguloY(r)+getRetanguloH(r)/2 ,"magenta");
            }
        }
    } 

    fclose(svgQry);
}

void pnt (Lista listasObjetos[], int j, char corb[], char corp[], FILE* saida)
{
    if(buscarCirculo(listasObjetos, j) != NULL)
{
        Info c = getInfo(buscarCirculo(listasObjetos, j));

        fprintf(saida,"%lf %lf\n", getCirculoX(c), getCirculoY(c));
        setCirculoCorb(c, corb);
        setCirculoCorp(c, corp);
    }

    No node;
    for(node = getFirst(listasObjetos[1]); node != NULL; node = getNext(node))
    {
        Info r = getInfo(node);

        if(getRetanguloI(r)== j)
        {
            fprintf(saida,"%lf %lf\n", getRetanguloX(r), getRetanguloY(r));
            setRetanguloCorb(r, corb);
            setRetanguloCorp(r, corp);
        }    
    } 

    for(node = getFirst(listasObjetos[2]); node != NULL; node = getNext(node))
    {
        Info t = getInfo(node);

        if(getTextoI(t)== j)
        {
            fprintf(saida,"%lf %lf\n", getTextoX(t), getTextoY(t));
            setTextoCorb(t, corb);
            setTextoCorp(t, corp);
        }    
    } 
}

void delf(Lista listasObjetos[], int j, FILE* saida)
{
    if(buscarCirculo(listasObjetos, j) != NULL)
    {
        Info c = getInfo(buscarCirculo(listasObjetos, j));
        fprintf(saida,"%d %lf %lf %lf %s %s \n", getCirculoI(c), getCirculoR(c), getCirculoX(c), getCirculoY(c), getCirculoCorb(c), getCirculoCorp(c));
        removerNo(listasObjetos[0], buscarCirculo(listasObjetos, j), 1);
    }

    if(buscarRetangulo(listasObjetos, j) != NULL)
    {
        Info r = getInfo(buscarRetangulo(listasObjetos, j));
        fprintf(saida,"%d %lf %lf %lf %lf %s %s \n", getCirculoI(r), getRetanguloW(r), getRetanguloH(r), getRetanguloX(r), getRetanguloY(r), getRetanguloCorb(r), getRetanguloCorp(r));
        removerNo(listasObjetos[1], buscarRetangulo(listasObjetos, j), 1);
    }

    if(buscarTexto(listasObjetos, j) != NULL)
    {
        Info t = getInfo(buscarTexto(listasObjetos, j));
        fprintf(saida,"%d %lf %lf %s %s %s\n",getTextoI(t), getTextoX(t), getTextoY(t), getTextoCorb(t), getTextoCorp(t), getTextoTxto(t));
        removerNo(listasObjetos[2], buscarTexto(listasObjetos, j), 1);
    }
}

void del (Lista listasObjetos[], char id[], FILE* saida, char saidaSvg[], Lista listasQry[])
{

    FILE *svgQry = fopen(saidaSvg, "a");

    if(buscarQuadra(listasObjetos, id) != NULL)
    {
        Info q = getInfo(buscarQuadra(listasObjetos, id));
        fprintf(saida,"%s %lf %lf %lf %lf\n", getQuadraCep(q), getQuadraX(q), getQuadraY(q), getQuadraW(q), getQuadraH(q));

        Linha lin = criaLinha(getQuadraX(q)+getQuadraW(q)/2, (getQuadraY(q)+getQuadraH(q)/2), getQuadraX(q)+getQuadraW(q)/2, 0, "black");
        insert(listasQry[2], lin);

        Texto text = criaTexto(0, getQuadraX(q)+getQuadraW(q)/2, 0, "black", "black", getQuadraCep(q));
        insert(listasQry[4], text);

        removerNo(listasObjetos[3], buscarQuadra(listasObjetos, id), 1);
    }

    if(buscarHidrante(listasObjetos, id) != NULL)
    {
        Info h = getInfo(buscarHidrante(listasObjetos, id));
        fprintf(saida,"%s %lf %lf \n", getHidranteId(h), getHidranteX(h), getHidranteY(h));

        Linha lin = criaLinha(getHidranteX(h), getHidranteY(h), getHidranteX(h), 0, "black");
        insert(listasQry[2], lin);

        Texto text = criaTexto(0, getHidranteX(h), 0, "black", "black", getHidranteId(h));
        insert(listasQry[4], text);

        removerNo(listasObjetos[4], buscarHidrante(listasObjetos, id), 1);
    }

    if(buscarSemaforo(listasObjetos, id) != NULL)
    {
        Info s = getInfo(buscarSemaforo(listasObjetos, id));
        fprintf(saida,"%s %lf %lf \n", getSemaforoId(s), getSemaforoX(s), getSemaforoY(s));

        Linha lin = criaLinha(getSemaforoX(s), getSemaforoY(s), getSemaforoX(s), 0, "black");
        insert(listasQry[2], lin);

        Texto text = criaTexto(0, getSemaforoX(s), 0, "black", "black", getSemaforoId(s));
        insert(listasQry[4], text);

        removerNo(listasObjetos[5], buscarSemaforo(listasObjetos, id), 1);
    }

    if(buscarRadioBase(listasObjetos, id) != NULL)
    {
        Info rb = getInfo(buscarRadioBase(listasObjetos, id));
        fprintf(saida,"%s %lf %lf \n", getRadiobaseId(rb), getRadiobaseX(rb), getRadiobaseY(rb));

        Linha lin = criaLinha(getRadiobaseX(rb), getRadiobaseY(rb), getRadiobaseX(rb), 0, "black");
        insert(listasQry[2], lin);

        Texto text = criaTexto(0, getRadiobaseX(rb), 0, "black", "black", getRadiobaseId(rb));
        insert(listasQry[4], text);

        removerNo(listasObjetos[6], buscarRadioBase(listasObjetos, id), 1);
    }

    fclose(svgQry);
}

void crd (Lista listasObjetos[], char id[], FILE* saida)
{
    if(buscarQuadra(listasObjetos, id) != NULL)
    {
        Info q = getInfo(buscarQuadra(listasObjetos, id));
        fprintf(saida,"%lf %lf QUADRA\n", getQuadraX(q), getQuadraY(q));
    }

    if(buscarHidrante(listasObjetos, id) != NULL)
    {
       
        Info h = getInfo(buscarHidrante(listasObjetos, id));
        fprintf(saida,"%lf %lf HIDRANTE\n", getHidranteX(h), getHidranteY(h));
    }

    if(buscarSemaforo(listasObjetos, id) != NULL)
    {
       Info s = getInfo(buscarSemaforo(listasObjetos, id));
        fprintf(saida,"%lf %lf SEMAFORO\n", getSemaforoX(s), getSemaforoY(s));
    }

    if(buscarRadioBase(listasObjetos, id) != NULL)
    {
        Info rb = getInfo(buscarRadioBase(listasObjetos, id));
        fprintf(saida,"%lf %lf RADIO BASE\n", getRadiobaseX(rb), getRadiobaseY(rb));
    }
}

float max(float n1, float n2)
{
    if(n1 > n2)
    {
        return n1;
    }
    return n2;
}

float min(float n1, float n2)
{
    if(n1 > n2)
    {
        return n2;
    }
    return n1;
}

void retanguloxCirculo(Info circ, Info ret, FILE* saida, Lista listasQry[])
{
    float deltaX, deltaY, x, y, w, h;

    if(getCirculoX(circ) > getRetanguloX(ret))
    {
        deltaX = pow(getRetanguloX(ret) + getRetanguloW(ret) - getCirculoX(ret),2);
    }
    else
    {
        deltaX = pow(getRetanguloX(ret) - getCirculoX(circ),2);
    }
    if(getCirculoY(circ) > getRetanguloY(ret))
    {
        deltaY = pow(getRetanguloY(ret) + getRetanguloH(ret) - getCirculoY(circ),2);
    }
    else
    {
        deltaY = pow(getRetanguloY(ret) - getCirculoY(circ),2);
    }

    x = min(getRetanguloX(ret),getCirculoX(circ) - getCirculoR(circ));
    w = max(getRetanguloX(ret) + getRetanguloW(ret),getCirculoX(circ) + getCirculoR(circ)) - x;
    y = min(getRetanguloY(ret),getCirculoY(circ) - getCirculoR(circ));
    h = max(getRetanguloY(ret) + getRetanguloH(ret),getCirculoY(circ) + getCirculoR(circ)) - y;

    if(sqrt(deltaX + deltaY) <= getCirculoR(circ))
    {
        fprintf(saida,"%d: circulo %d: retangulo SIM\n", getCirculoI(circ), getRetanguloI(ret));

        Retangulo ret = criaRetangulo(0, w,h,x,y, "1", "black", "none");
        insert(listasQry[1], ret);
    }
    else
    {
        fprintf(saida,"%d: circulo %d: retangulo NAO\n", getCirculoI(circ), getRetanguloI(ret));

        Retangulo ret = criaRetangulo(0, w,h,x,y, "1", "black", "none");
        insert(listasQry[5], ret);

    }
}

void circuloInt(Info c1, Info c2, FILE* saida, Lista listasQry[])
{
    float dist,x,y,w,h;

    dist = sqrt(pow(getCirculoX(c1) - getCirculoX(c2),2) + pow(getCirculoY(c1) - getCirculoY(c2),2));
    x = min(getCirculoX(c1) - getCirculoR(c1), getCirculoX(c2) - getCirculoR(c2));
    w = max(getCirculoX(c1) + getCirculoR(c1), getCirculoX(c2) + getCirculoR(c2)) - x;
    y = min(getCirculoY(c1) - getCirculoR(c1), getCirculoY(c2) - getCirculoR(c2));
    h = max(getCirculoY(c1) + getCirculoR(c1), getCirculoY(c2) + getCirculoR(c2)) - y;

    if(dist <= getCirculoR(c2) + getCirculoR(c1))
    {
        fprintf(saida,"%d: circulo %d: circulo SIM\n", getCirculoI(c1),getCirculoI(c2));

        Retangulo ret = criaRetangulo(0, w,h,x,y, "1", "black", "none");
        insert(listasQry[1], ret);

    }
    else
    {
        fprintf(saida,"%d: circulo %d: circulo NAO\n",getCirculoI(c1),getCirculoI(c2));

        Retangulo ret = criaRetangulo(0, w,h,x,y, "1", "black", "none");
        insert(listasQry[5], ret);

    }
}

void retanguloInt(Info r1, Info r2, FILE* saida, Lista listasQry[])
{
    float x,w,y,h;
    x = min(getRetanguloX(r1),getRetanguloX(r2));
    w = max(getRetanguloX(r1) + getRetanguloW(r1),getRetanguloX(r2) + getRetanguloW(r2)) - x;
    y = min(getRetanguloY(r1),getRetanguloY(r2));
    h = max(getRetanguloY(r1) + getRetanguloH(r1),getRetanguloY(r2) + getRetanguloH(r2)) - y;

    if (w <= getRetanguloW(r1) + getRetanguloW(r2) && h <= getRetanguloH(r1) + getRetanguloH(r2))
    {
        fprintf(saida,"%d: retangulo %d: retangulo SIM\n", getRetanguloI(r1),getRetanguloI(r2));

        Retangulo ret = criaRetangulo(0, w,h,x,y, "1", "black", "none");
        insert(listasQry[1], ret);
    }
    else
    {
        fprintf(saida,"%d: retangulo %d: retangulo NAO\n", getRetanguloI(r1),getRetanguloI(r2));

        Retangulo ret = criaRetangulo(0, w,h,x,y, "1", "black", "none");
        insert(listasQry[5], ret);
    }
}

void o(int j, int k, FILE* saida, Lista listasObjetos[], Lista listasQry[])
{
    if(buscarCirculo(listasObjetos, j) != NULL && buscarCirculo(listasObjetos, k) != NULL)
    {
        Info c1 = getInfo(buscarCirculo(listasObjetos, j));
        Info c2 = getInfo(buscarCirculo(listasObjetos, k));
        circuloInt(c1, c2, saida, listasQry);
    }

   else if(buscarRetangulo(listasObjetos, j) != NULL && buscarCirculo(listasObjetos, k) != NULL)
    {
        Info ret = getInfo(buscarRetangulo(listasObjetos, j));
        Info circ = getInfo(buscarCirculo(listasObjetos, k));
        retanguloxCirculo(circ, ret, saida, listasQry);           
    }

    else if(buscarRetangulo(listasObjetos, k) != NULL && buscarCirculo(listasObjetos, j) != NULL)
    {
        Info ret = getInfo(buscarRetangulo(listasObjetos, k));
        Info circ = getInfo(buscarCirculo(listasObjetos, j));
        retanguloxCirculo(circ, ret, saida, listasQry);              
    }

    else if(buscarRetangulo(listasObjetos, j) != NULL && buscarRetangulo(listasObjetos, k) != NULL)
    {
        Info r1 = getInfo(buscarRetangulo(listasObjetos, j));
        Info r2 = getInfo(buscarRetangulo(listasObjetos, k));
        retanguloInt(r1, r2, saida, listasQry);
    }
}

void dq(Lista listaObjetos[], FILE* txt, char svg_qry[], char id[], double r, int ident, Lista listasQry[])
{
    FILE *svgQry = fopen(svg_qry, "a");

    Info info;
    No aux;
    No node;
    int i; 
    int achou = 0;
    double x;
    double y;
    char auxId[20];
    double auxX, auxY;


    switch (id[0])
    {
        case 'h':
            i = 4;
            break;

        case 's':
            i = 5;
            break;

        case 'r':
            i = 6;
            break;
    }

    if(i == 4)
    {
        for(node = getFirst(listaObjetos[i]); node != NULL; node = getNext(node))
        {
            info = getInfo(node);
            if(strcmp(getHidranteId(info),id) == 0)
            {
                x = getHidranteX(info);
                y = getHidranteY(info);
                achou = 0;

                Circulo circ = criaCirculo(0, r, x, y, "1", "black", "none");
                insert(listasQry[3], circ);

                Circulo circ2 = criaCirculo(0, 6, x, y, "1", "blue", "none");
                insert(listasQry[3], circ2);

                Circulo circ3 = criaCirculo(0, 7, x, y, "1", "yellow", "none");
                insert(listasQry[3], circ3);

                strcpy(auxId, id);
                auxX=x;
                auxY=y;
                break;
            }
        }
    }

    else if(i == 5)
    {
        for(node = getFirst(listaObjetos[i]); node != NULL; node = getNext(node))
        {
            info = getInfo(node);
            if(strcmp(getSemaforoId(info),id) == 0)
            {
                x = getSemaforoX(info);
                y = getSemaforoY(info);
                achou = 0;

                Circulo circ = criaCirculo(0, r, x, y, "1", "black", "none");
                insert(listasQry[3], circ);

                Circulo circ2 = criaCirculo(0, 6, x, y, "1", "blue", "none");
                insert(listasQry[3], circ2);

                Circulo circ3 = criaCirculo(0, 7, x, y, "1", "yellow", "none");
                insert(listasQry[3], circ3);

                strcpy(auxId, id);
                auxX=x;
                auxY=y;
                break;
            }
        }
    }

    else if(i == 6)
    {
        for(node = getFirst(listaObjetos[i]); node != NULL; node = getNext(node))
        {
            info = getInfo(node);
            if(strcmp(getRadiobaseId(info),id) == 0)
            {
                x = getRadiobaseX(info);
                y = getRadiobaseY(info);
                achou = 0;

                Circulo circ = criaCirculo(0, r, x, y, "1", "black", "none");
                insert(listasQry[3], circ);

                Circulo circ2 = criaCirculo(0, 6, x, y, "1", "blue", "none");
                insert(listasQry[3], circ2);

                Circulo circ3 = criaCirculo(0, 7, x, y, "1", "yellow", "none");
                insert(listasQry[3], circ3);

                strcpy(auxId, id);
                auxX=x;
                auxY=y;
                break;
            }
        }
    }

   if(achou == 1)
    {
        fprintf(txt, "\nOBJETO NAO ENCONTRADO\n");
        return;
    }

    node = getFirst(listaObjetos[3]);
    while(node != NULL)
    {
        info = getInfo(node);
        if(distancia(getQuadraX(info),getQuadraY(info),x,y) <= r && distancia(getQuadraX(info) + getQuadraW(info) ,getQuadraY(info) + getQuadraH(info),x,y) <= r)
        {
            if(ident)
            {
                Retangulo ret = criaRetangulo(0, getQuadraW(info), getQuadraH(info), getQuadraX(info),getQuadraY(info), "1", "olive", "beige");
                insert(listasQry[6], ret);
            }

            fprintf(txt,"%s\n", getQuadraCep(info));
            aux = node;
            node = getNext(node);
            removerNo(listaObjetos[3], aux, 1);
        }
        else{
            node = getNext(node);
        }
    }

    fprintf(txt,"%s %lf %lf\n",auxId,auxX,auxY);
    fclose(svgQry);
}

void shellSort(double *vet, int size) 
{
    int i, j;
    double value;
    int h = 1;

    while(h < size) 
    {
        h = 3*h+1;
    }
    while (h > 0) 
    {
        for(i = h; i < size; i++) 
        {
            value = vet[i];
            j = i;
            while (j > h-1 && value <= vet[j - h]) 
            {
                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = value;
        }
        h = h/3;
    }
}


void soc(Lista listasObjetos[], int k, char cep[], char face[], double num, FILE* saida, Lista listasQry[])
{
    double x, y;

    if(buscarQuadra(listasObjetos, cep) != NULL)
    {
        Info q = getInfo(buscarQuadra(listasObjetos, cep));

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

    Retangulo ret = criaRetangulo(0, 10, 10, x, y, "2", "white", "blue");
    insert(listasQry[1], ret);

    double vet[200];
    int size = 0;

    No node;
    for(node = getFirst(listasObjetos[7]); node != NULL; node = getNext(node))
    {
        Info po = getInfo(node);

        double dist = distancia(x, y, getPostoX(po), getPostoY(po));
        setPostoDistancia(po, dist);
        vet[size] = dist;
        size++;
        
    }

    shellSort(vet, size);

    No aux;
    for(int cont=0; cont<k; cont++)
    {
        for(aux = getFirst(listasObjetos[7]); aux != NULL; aux = getNext(aux))
        {   
            Info inf = getInfo(aux);
            if(getPostoDistancia(inf)==vet[cont])
            {
                Linha lin = criaLinha(x, y, getPostoX(inf), getPostoY(inf), "black");
                insert(listasQry[7], lin);

                fprintf(saida,"%lf %lf\n", getPostoX(inf), getPostoY(inf));
            }
        }
    }
}

void cv(Lista listasObjetos[], double n, char cep[], char face[], double num, Lista listasQry[])
{
    double x, y;

    if(buscarQuadra(listasObjetos, cep) != NULL)
    {
        Info q = getInfo(buscarQuadra(listasObjetos, cep));

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
    insert(listasObjetos[9], caso);

    Retangulo ret = criaRetangulo(0, 10, 10, x, y, "2", "orange", "orange");
    insert(listasQry[1], ret);

    TextoNumerico textNum = criaTextoNumerico(x, y, "black", "black", n);
    insert(listasQry[0], textNum);

}

int circIntRegiao(Densidade dd, double x, double y, double r)
{
    if((x - r > getDensidadeX(dd) && x - r < getDensidadeX(dd) + getDensidadeW(dd)) ||(x + r > getDensidadeX(dd) && x + r < getDensidadeX(dd) + getDensidadeW(dd)))
    {
        if((y - r > getDensidadeY(dd) && y - r < getDensidadeY(dd) + getDensidadeH(dd)) ||(y + r > getDensidadeY(dd) && y + r < getDensidadeY(dd) + getDensidadeH(dd))){
            return 1;
        }
    }
    return 0;
}

int pontoInternoCirc(double xPonto, double yPonto, double xCirc, double yCirc, double r)
{
    return distancia(xPonto, yPonto, xCirc, yCirc) <= r;
}

double obterArea(Lista l)
{
    double a = 0;
    Info i, j;
    No node;

    for(node = getFirst(l); getNext(node) != NULL; node = getNext(node))
    {
        i = getInfo(node);
        j = getInfo(getNext(node));
        a += getCasosX(i) * getCasosY(j) - getCasosY(i) * getCasosX(j);
    }

    i = getInfo(node);
    j = getInfo(getFirst(l));
    a += getCasosX(i) * getCasosY(j) - getCasosY(i) * getCasosX(j);

    return a/2;
}

Posto centroide(Lista l, double area)
{
    double x = 0, y = 0;
    Info i, j;
    No node;

    for(node = getFirst(l); getNext(node) != NULL; node = getNext(node))
    {
        i = getInfo(node);
        j = getInfo(getNext(node));
        x += (getCasosX(i) + getCasosX(j)) * getCasosX(i) * getCasosY(j) - getCasosY(i) * getCasosX(j);
        y += (getCasosY(i) + getCasosY(j)) * getCasosX(i) * getCasosY(j) - getCasosY(i) * getCasosX(j);
    }

    i = getInfo(node);
    j = getInfo(getFirst(l));

    x += (getCasosX(i) + getCasosX(j)) * getCasosX(i) * getCasosY(j) - getCasosY(i) * getCasosX(j);
    y += (getCasosY(i) + getCasosY(j)) * getCasosX(i) * getCasosY(j) - getCasosY(i) * getCasosX(j);

    return criaPosto(0, x/(6 * area), y/(6 * area), 0);
}

int orientacao(Casos a, Casos b, Casos c)
{
    double area = (getCasosX(b) - getCasosX(a)) * (getCasosY(c) - getCasosY(a)) - (getCasosY(b) - getCasosY(a)) * (getCasosX(c) - getCasosX(a));

    if(area > 1)
    {
        return 1;
    }
    if(area < 1)
    {
        return -1;
    }
    return 0;
}

int comparar(Casos p0, Casos a, Casos b)
{
    int aux = orientacao(p0,a,b);

    if(aux == 0){
        return distancia(getCasosX(p0),getCasosY(p0),getCasosX(b),getCasosY(b)) < distancia(getCasosX(p0),getCasosY(p0),getCasosX(a),getCasosY(a));
    }
    return aux == 1;
}

No partition(Lista l, No primeiro, No ultimo)
{
    No i = getPrevious(primeiro);

    for(No j = primeiro; j != ultimo; j = getNext(j))
    {
        if(comparar(getInfo(getFirst(l)), getInfo(j), getInfo(ultimo))){
            i = (i == NULL) ? primeiro : getNext(i); 
            swap(getInfo(i), getInfo(j));
        }
    }
    i = (i == NULL) ? primeiro : getNext(i); 
    swap(getInfo(i), getInfo(ultimo));
    return i; 
}

void quickSortList(Lista l, No primeiro, No ultimo)
{
    if(ultimo != NULL && primeiro != ultimo && getNext(ultimo) != primeiro)
    { 
        No p = partition(l, primeiro, ultimo);
        quickSortList(l, primeiro,getPrevious(p));
        quickSortList(l, getNext(p),ultimo);
    }
}

Lista envoltoria(Lista list)
{
    No primeiro = getFirst(list), i;
    Casos p2;
    Casos p1 = getInfo(primeiro);

    for(i = getNext(primeiro); i != NULL; i = getNext(i))
    {
        p2 = getInfo(i);

        if(getCasosY(p2) < getCasosY(p1) || (getCasosY(p2) == getCasosY(p1) && getCasosX(p2) < getCasosX(p1)))
        {
            p1 = p2;
        }
    }

    swap(getInfo(primeiro),p1);

    quickSortList(list,getNext(primeiro),getLast(list));

    int j = 1;

    for(i = getNext(getNext(primeiro)); i != NULL; i = getNext(i))
    {
        p1 = getInfo(i);
        p2 = getInfo(getPrevious(i));

        if(orientacao(getInfo(primeiro),p1,p2) == 0)
        {
            removerNo(list, getPrevious(i), 0);
        }
        else
        {
            j++;
        }
    }
        
    if (j < 3)
    {
        return NULL;
    }

    Lista envConv = create();

    i = primeiro;

    for(j = 0; j < 3; j++)
    {
        insert(envConv,getInfo(i));
        i = getNext(i);
    }
    while(i != NULL)
    {
        while (orientacao(getInfo(getPrevious(getLast(envConv))), getInfo(getLast(envConv)), getInfo(i)) != 1)
        {
            removerNo(envConv,getLast(envConv), 0);
        }
        insert(envConv,getInfo(i));
        i = getNext(i);
    }
    return envConv;    
}

void ci(FILE* saida, Lista listasObjetos[], double x, double y, double r, Lista listasQry[])
{
    No node;
    Info fig;
    int flag = 1, n = 0;
    double d, inc, area;
    char cor[22];
    Posto posto = NULL;

    for(node = getFirst(listasObjetos[8]); node != NULL; node = getNext(node))
    {
        fig = getInfo(node);
        if(circIntRegiao(fig,x,y,r))
        {
            d = getDensidadeD(fig);
            flag = 0;
            break;
        }
    }
    insert(listasQry[3], criaCirculo(0, r, x, y, "4", "green", "none"));

    if(flag)
    {
        return;
    }
    
    Lista l = create();

    for(node = getFirst(listasObjetos[9]); node != NULL; node = getNext(node))
    {
        fig = getInfo(node);

        if(pontoInternoCirc(getCasosX(fig),getCasosY(fig),x,y,r))
        {
            insert(l,fig);
            fprintf(saida,"X : %lf y : %lf\n", getCasosX(fig),getCasosY(fig));
            n += getCasosN(fig);
        }
    }

    if(getFirst(l) == NULL)
    {
        free(l);
        return;
    }

    Lista casos;

    if(tamanhoDaLista(l) < 3)
    {
        casos = NULL;
    }
    else
    {
        casos = envoltoria(l);
    }
    
    if(casos == NULL)
    {
        casos = l;
    }
    else
    {
        removeList(l, 0);
    }

    area = obterArea(casos);

    fprintf(saida,"Numero de casos : %d\nArea : %lf\n",n,area);

    if(area != 0)
    {
        inc = 10 * n/(d * area);

        if(inc < 0.1)
        {
            strcpy(cor, "00FFFF");
            fprintf(saida,"Categoria : A - Livre de Covid\n");
        }
        else if(inc < 5)
        {
            strcpy(cor, "008080");
            fprintf(saida,"Categoria : B - Baixa incidencia\n");
        }
        else if(inc < 10)
        {
            strcpy(cor, "FFFF00");
            fprintf(saida,"Categoria : C - Media incidencia\n");
        }
        else if(inc < 20)
        {
            strcpy(cor, "FF0000");
            fprintf(saida,"Categoria : D - Alta incidencia\n");
        }
        else
        {
            strcpy(cor, "800080");
            fprintf(saida,"Categoria : E - Catastrofico\n");

            for(node = getFirst(listasObjetos[7]); node != NULL; node = getNext(node))
            {
                fig = getInfo(node);

                if(pontoInternoCirc(getPostoX(fig), getPostoY(fig), x, y, r))
                {
                    posto = fig;
                }
            }
            if(posto == NULL)
            {
                posto = centroide(casos,area);
                fprintf(saida,"Necessário novo posto em (%lf,%lf)\n",getPostoX(posto),getPostoY(posto));
            }
        }
    }
    else
    {
        fprintf(saida,"Não é possivel obter a categoria da região, apenas um caso dentro do circulo\n");
    }

    int tamanho = tamanhoDaLista(casos);

    No no = getFirst(casos);

    Info inf = criaPoligono(cor, tamanho);

    insert(listasQry[8], inf);

    for(int cont =0; cont<tamanho; cont++)
    {
        Info aux = getInfo(no);
        setPoligonoX(inf, getCasosX(aux), cont);
        setPoligonoY(inf, getCasosY(aux), cont);

        no = getNext(no);
    }
}

    void sombras(Lista listasObjetos[])
    {
        No node;
        for(node = getFirst(listasObjetos[3]); node != NULL; node = getNext(node))
        {
            Info q = getInfo(node);

            No no;
            for(no = getFirst(listasObjetos[8]); no != NULL; no = getNext(node))
            {
                Info d = getInfo(no);
                double x = getDensidadeX(d);
                double y = getDensidadeY(d);
                double w = getDensidadeW(d);
                double h = getDensidadeH(d);

                if(getQuadraX(q) >= x && getQuadraY(q) >= y && getQuadraX(q) + getQuadraW(q) <= x + w && getQuadraY(q) + getQuadraH(q) <= y + h)
                {
                    if(getDensidadeD(d)>10.0 && getDensidadeD(d)<500.0)
                    {
                        setQuadraSombra(q, "#FFFF00");
                    }

                    else if(getDensidadeD(d)>500.0 && getDensidadeD(d)<1500.0)
                    {
                        setQuadraSombra(q, "#FF9955");
                    }

                    else if(getDensidadeD(d)>1500.0 && getDensidadeD(d)<3000.0)
                    {
                        setQuadraSombra(q, "#FF0000");
                    }

                    else if(getDensidadeD(d)>3000.0 && getDensidadeD(d)<4500.0)
                    {
                        setQuadraSombra(q, "#FF00CC");
                    }

                    else if(getDensidadeD(d)>4500.0 && getDensidadeD(d)<6000.0)
                    {
                        setQuadraSombra(q, "#6600FF");
                    }
                    else
                    {
                        setQuadraSombra(q, "#A02C5A");
                    }
                }
            }
        }
    }
