#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qry2.h"

void dq(FILE *saida, QuadTree arvoresObjetos[], int flag, char id[], double r, Lista listasQry[]) 
{
    Ponto p;
    Info info;
    double x, y, w, h;

    switch(id[0]) 
    {
        case 'h':
            info = getInfoByIdQt(arvoresObjetos[4], id);
            p = getHidrantePonto(info);
            x = getHidranteX(info);
            y = getHidranteY(info);
            fprintf(saida, "Hidrante:\n");

            break;
        
        case 's':
            info = getInfoByIdQt(arvoresObjetos[5], id);
            p = getSemaforoPonto(info);
            x = getSemaforoX(info);
            y = getSemaforoY(info);
            fprintf(saida, "Semaforo:\n");

            break;

        case 'r':
            info = getInfoByIdQt(arvoresObjetos[6], id);
            p = getRadiobasePonto(info);
            x = getRadiobaseX(info);
            y = getRadiobaseY(info);
            fprintf(saida, "RadioBase:\n");
            break;
    }
    
    Lista l = nosDentroCirculoQt(arvoresObjetos[3], x, y, r);

    No node = getFirst(l);
    while (node != NULL) 
    {
        info = getInfoQt(arvoresObjetos[3], getInfo(node));
        p = getQuadraPonto(info);
        h = getQuadraH(info);
        w = getQuadraW(info);

        if(retInternoCirc(getPontoX(p),getPontoY(p),w,h,x,y,r))
        {
            if (flag) 
            {
                Retangulo ret = criaRetangulo("0", getQuadraW(info), getQuadraH(info), getQuadraX(info),getQuadraY(info), "1", "olive", "beige");
                insert(listasQry[6], ret);
            }

            fprintf(saida, "Quadra removida: %s\n", getQuadraCep(info));
            QtNo aux = getInfo(node);
            info = removeNoQt(arvoresObjetos[3], aux);
            desalocaQuadra(info);
        }
        node = getNext(node);
    }

    Circulo circ = criaCirculo("0", r, x, y, "1", "black", "none");
    insert(listasQry[3], circ);

    Circulo circ2 = criaCirculo("0", 6, x, y, "1", "blue", "none");
    insert(listasQry[3], circ2);

    Circulo circ3 = criaCirculo("0", 7, x, y, "1", "yellow", "none");
    insert(listasQry[3], circ3);
    
    removeList(l, NULL);
}

void del(FILE* saida, QuadTree arvoresObjetos[], char j[], Lista listasQry[])
{
    if(getNodeByIdQt(arvoresObjetos[3],j) != NULL)
    {
        QtNo node = getNodeByIdQt(arvoresObjetos[3],j);
        Info q = removeNoQt(arvoresObjetos[3], node);
        
        fprintf(saida,"%s %lf %lf %lf %lf\n", getQuadraCep(q), getQuadraX(q), getQuadraY(q), getQuadraH(q), getQuadraW(q));
        
        Linha lin = criaLinha(getQuadraX(q)+getQuadraW(q)/2, (getQuadraY(q)+getQuadraH(q)/2), getQuadraX(q)+getQuadraW(q)/2, 0, "black");
        insert(listasQry[2], lin);

        Texto text = criaTexto("0", getQuadraX(q)+getQuadraW(q)/2, 0, "black", "black", getQuadraCep(q));
        insert(listasQry[4], text);

        desalocaQuadra(q);
    }
    
    else if(getNodeByIdQt(arvoresObjetos[4],j) != NULL)
    {
        QtNo node = getNodeByIdQt(arvoresObjetos[4],j);
        Info h = removeNoQt(arvoresObjetos[4], node);
        
        fprintf(saida,"%s %lf %lf \n", getHidranteId(h), getHidranteX(h), getHidranteY(h));

        Linha lin = criaLinha(getHidranteX(h), getHidranteY(h), getHidranteX(h), 0, "black");
        insert(listasQry[2], lin);

        Texto text = criaTexto("0", getHidranteX(h), 0, "black", "black", getHidranteId(h));
        insert(listasQry[4], text);

        desalocarPontoHidrante(h);
    }

    else if(getNodeByIdQt(arvoresObjetos[5],j) != NULL)
    {
        QtNo node = getNodeByIdQt(arvoresObjetos[5],j);
        Info s = removeNoQt(arvoresObjetos[5], node);
        
        fprintf(saida,"%s %lf %lf \n", getSemaforoId(s), getSemaforoX(s), getSemaforoY(s));

        Linha lin = criaLinha(getSemaforoX(s), getSemaforoY(s), getSemaforoX(s), 0, "black");
        insert(listasQry[2], lin);

        Texto text = criaTexto("0", getSemaforoX(s), 0, "black", "black", getSemaforoId(s));
        insert(listasQry[4], text);

        desalocaSemaforo(s);
    }
    else if(getNodeByIdQt(arvoresObjetos[6],j) != NULL)
    {
        QtNo node = getNodeByIdQt(arvoresObjetos[6],j);
        Info rb = removeNoQt(arvoresObjetos[6], node);
        
        fprintf(saida,"%s %lf %lf \n", getRadiobaseId(rb), getRadiobaseX(rb), getRadiobaseY(rb));

        Linha lin = criaLinha(getRadiobaseX(rb), getRadiobaseY(rb), getRadiobaseX(rb), 0, "black");
        insert(listasQry[2], lin);

        Texto text = criaTexto("0", getRadiobaseX(rb), 0, "black", "black", getRadiobaseId(rb));
        insert(listasQry[4], text);

        desalocaRadiobase(rb);
    }
}

