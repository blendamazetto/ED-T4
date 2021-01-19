#include<stdio.h>
#include<stdlib.h>
#include"svg.h"

void iniciaSvg(char svg[])
{

    FILE *arqSvg;
    arqSvg = fopen(svg, "w");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser aberto\n");
        exit(1);
    }

    fprintf(arqSvg, "<svg>\n");

    fclose(arqSvg);
}

void desenhaCirculo(double raio, double x, double y, char cor_b[], char cor_p[], char svg[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ", x, y, raio, cor_b, cor_p);

    fclose(arqSvg);

}


void desenhaRetangulo(double w, double h, double x, double y, char cor_b[], char cor_p[], char svg[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg, "\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width =\"1\"/>\n",x,y,w,h,cor_p,cor_b);

    fclose(arqSvg);
}

void desenhaRetanguloTracejado(double w, double h, double x, double y, char cor_b[], char svg[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg, "\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"%s\" stroke-width =\"1\" stroke-dasharray=\"1\" />\n",x,y,w,h,cor_b);

    fclose(arqSvg);
}

void desenhaRetanguloArredondado(double w, double h, double x, double y, char sw[], char svg[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg, "\n<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"beige\" stroke=\"olive\"  stroke-width=\"%s\" rx=\"20\"/>\n",x,y,w,h,sw);

    fclose(arqSvg);
}

void escreveTexto(double x, double y, char cor_b[], char cor_p[], char text[], char svg[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">%s</text>\n",x,y,cor_b,cor_p,text);

    fclose(arqSvg);
}

void escreveTextoNumerico(double x, double y, char cor_b[], char cor_p[], double texto, char svg[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">%lf</text>\n", x, y, cor_b, cor_p, texto);

    fclose(arqSvg);
}


void desenhaQuadra(double w, double h, double x, double y, char cor_b[], char cor_p[], char cep[], char svg[], char quaExpessura[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg,"\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\"/>\n",x, y, w, h, cor_p, cor_b, quaExpessura);
    fprintf(arqSvg, "\t<text x=\"%lf\" y=\"%lf\" fill=\"black\">%s</text>\n", x+w/4, y+h/2, cep);

    fclose(arqSvg);

}

void desenhaHidrante(double raio, double x, double y, char cor_b[], char cor_p[], char svg[], char hidraExpessura[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"%s\" fill=\"%s\"/>\n ", x, y, raio, cor_b, hidraExpessura,cor_p);

    fclose(arqSvg);
}

void desenhaSemaforo(double raio, double x, double y, char cor_b[], char cor_p[], char svg[], char semaExpessura[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"%s\" fill=\"%s\"/>\n ", x, y, raio, cor_b, semaExpessura, cor_p);

    fclose(arqSvg);
}

void desenhaRadioBase(double raio, double x, double y, char cor_b[], char cor_p[], char svg[], char radioExpessura[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"%s\" fill=\"%s\"/>\n ", x, y, raio, cor_b, radioExpessura, cor_p);


    fclose(arqSvg);

}

void desenhaPosto(double x, double y, char svg[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%d\" stroke=\"%s\" fill=\"%s\"/>\n ", x, y, 5, "green", "blue");

    fclose(arqSvg);

}

void desenhaLinha(double x1, double y1, double x2, double y2, char cor[], char svg[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n", x1, y1, x2, y2, cor);

    fclose(arqSvg);

}

void desenhaLinhaTracejada(double x1, double y1, double x2, double y2, char svg[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"black\" stroke-width=\"2\" stroke-dasharray=\"5\" />\n ", x1, y1, x2, y2);

    fclose(arqSvg);

}

void finalizaSvg(char svg[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser finalizado");
        exit(1);
    }

    fprintf(arqSvg, "</svg>");

    fclose(arqSvg);
}

void gerarSvgGeo(Lista listasObjetos[], char saidaSvg[])
{
    int i=0;

    if(i==0)
    {
        No node;
        for(node = getFirst(listasObjetos[i]); node != NULL; node = getNext(node))
        {
            Info c = getInfo(node);
            desenhaCirculo(getCirculoR(c), getCirculoX(c), getCirculoY(c), getCirculoCorb(c), getCirculoCorp(c), saidaSvg);
        } 
        i++;
    }

    if(i==1)
    {
        No node;
        for(node = getFirst(listasObjetos[i]); node != NULL; node = getNext(node))
        {
            Info r = getInfo(node);
            desenhaRetangulo(getRetanguloW(r), getRetanguloH(r), getRetanguloX(r), getRetanguloY(r), getRetanguloCorb(r), getRetanguloCorp(r), saidaSvg);           
        } 
        i++;
    }

    if(i==2)
    {
        No node;
        for(node = getFirst(listasObjetos[i]); node != NULL; node = getNext(node))
        {
            Info t = getInfo(node);
            escreveTexto(getTextoX(t), getTextoY(t), getTextoCorb(t), getTextoCorp(t), getTextoTxto(t), saidaSvg);
        } 
        i++;
    }

    if(i==3)
    {
        No node;
        for(node = getFirst(listasObjetos[i]); node != NULL; node = getNext(node))
        {
            Info q = getInfo(node);
            desenhaQuadra(getQuadraW(q), getQuadraH(q), getQuadraX(q), getQuadraY(q), getRadiobaseCstrk(q), getQuadraCfill(q), getQuadraCep(q), saidaSvg, getQuadraSw(q));           
        } 
        i++;
    }

    if(i==4)
    {
        No node;
        for(node = getFirst(listasObjetos[i]); node != NULL; node = getNext(node))
        {
            Info h = getInfo(node);
            desenhaHidrante(5, getHidranteX(h), getHidranteY(h), getHidranteCstrk(h), getHidranteCfill(h), saidaSvg, getHidranteSw(h));            
        } 
        i++;
    }

    if(i==5)
    {
        No node;
        for(node = getFirst(listasObjetos[i]); node != NULL; node = getNext(node))
        {
            Info s = getInfo(node);
            desenhaSemaforo(5, getSemaforoX(s), getSemaforoY(s), getSemaforoCstrk(s), getSemaforoCfill(s), saidaSvg, getSemaforoSw(s));
        } 
        i++;
    }

    if(i==6)
    {
        No node;
        for(node = getFirst(listasObjetos[i]); node != NULL; node = getNext(node))
        {
            Info rb = getInfo(node);
            desenhaRadioBase(5, getRadiobaseX(rb), getRadiobaseY(rb), getRadiobaseCstrk(rb), getRadiobaseCfill(rb), saidaSvg, getRadiobaseSw(rb));            
        } 
        i++;
    }

    if(i==7)
    {
        No node;
        for(node = getFirst(listasObjetos[i]); node != NULL; node = getNext(node))
        {
            Info po = getInfo(node);
            desenhaPosto(getPostoX(po), getPostoY(po), saidaSvg);
        } 
        i++;
    }
}


void gerarSvgQry(char saidaSvg[], Lista listasQry[])
{
    int i=0;

    if(i==0)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info textNum = getInfo(node);
            escreveTextoNumerico(getTextoNumericoX(textNum), getTextoNumericoY(textNum), getTextoNumericoCorb(textNum), getTextoNumericoCorp(textNum), getTextoNumericoTexto(textNum), saidaSvg);
        } 
        i++;
    }
    if(i==1)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info r = getInfo(node);
            desenhaRetangulo(getRetanguloW(r), getRetanguloH(r), getRetanguloX(r), getRetanguloY(r), getRetanguloCorb(r), getRetanguloCorp(r), saidaSvg);           
        } 
        i++;
    }
    if(i==2)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info lin = getInfo(node);
            desenhaLinha(getLinhaX1(lin), getLinhaY1(lin), getLinhaX2(lin), getLinhaY2(lin), getLinhaCor(lin), saidaSvg);
        } 
        i++;
    }
    if(i==3)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info c = getInfo(node);
            desenhaCirculo(getCirculoR(c), getCirculoX(c), getCirculoY(c), getCirculoCorb(c), getCirculoCorp(c), saidaSvg);
        } 
        i++;
    }
    if(i==4)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info t = getInfo(node);
            escreveTexto(getTextoX(t), getTextoY(t), getTextoCorb(t), getTextoCorp(t), getTextoTxto(t), saidaSvg);
        } 
        i++;
    }
    if(i==5)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info r = getInfo(node);
            desenhaRetanguloTracejado(getRetanguloW(r), getRetanguloH(r), getRetanguloX(r), getRetanguloY(r), getRetanguloCorb(r), saidaSvg);
        } 
        i++;
    }
    if(i==6)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info r = getInfo(node);
            desenhaRetanguloArredondado(getRetanguloW(r), getRetanguloH(r), getRetanguloX(r), getRetanguloY(r), "1", saidaSvg);
        } 
        i++;
    }
    if(i==7)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info lin = getInfo(node);
            desenhaLinhaTracejada(getLinhaX1(lin), getLinhaY1(lin), getLinhaX2(lin), getLinhaY2(lin), saidaSvg);
        } 
        i++;
    }
    if(i==8)
    {
        FILE *svg= fopen(saidaSvg, "a");

        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info p = getInfo(node);
            fprintf(svg,"\t<polygon id=\"%d\" fill=\"%s\" fill-opacity=\"0.2\" stroke=\"red\" stroke-width=\"5px\" points=\"", getPoligonoTamanho(getInfo(getLast(listasQry[i]))), getPoligonoCor(p));

            for(int aux=0; aux < getPoligonoTamanho(p); aux++)
            {
                fprintf(svg," %lf,%lf", getPoligonoX(p, aux), getPoligonoY(p, aux));
            }
            fprintf(svg," \"/>\n");
        }
        fclose(svg);
    }
}