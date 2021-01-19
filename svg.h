#ifndef __SVG_H
#define __SVG_H
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "hidrante.h"
#include "radiobase.h"
#include "semaforo.h"
#include "quadra.h"
#include "lista.h"
#include "svg.h"
#include "qry.h"
#include "posto.h"
#include "densidade.h"
#include "textoNumerico.h"
#include "linha.h"
#include "poligono.h"


/*
    *Inicia o arquivo svg colocando o comando necessario nele
    *Apenas o arquivo svg a ser aberto e passado como parametro
    *Retorna nada, fecha o svg apenas.
    * 
*/
void iniciaSvg(char svg[]);

/*
    *Desenha um circulo no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o circulo e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaCirculo(double raio, double x, double y, char cor_b[], char cor_p[], char svg[]);

/*
    *Desenha um retangulo tracejado no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o retangulo e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaRetanguloTracejado(double w, double h, double x, double y, char cor_b[], char svg[]);

/*
    *Desenha um retangulo no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o retangulo e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaRetangulo(double w, double h, double x, double y, char cor_b[], char cor_p[], char svg[]);

/*
    *Escreve um texto no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o texto e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void escreveTexto(double x, double y, char cor_b[], char cor_p[], char text[], char svg[]);

/*
    *Escreve um texto do tipo numerico no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o texto e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void escreveTextoNumerico(double x, double y, char cor_b[], char cor_p[], double texto, char svg[]);

/*
    *Desenha uma quadra no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para a quadra, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaQuadra(double w, double h, double x, double y, char cor_b[], char cor_p[], char cep[], char svg[], char quaExpessura[]);

/*
    *Desenha um hidrante no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o hidrante, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaHidrante(double raio, double x, double y, char cor_b[], char cor_p[], char svg[], char hidraExpessura[]);

/*
    *Desenha um semaforo no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o semaforo, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaSemaforo(double raio, double x, double y, char cor_b[], char cor_p[], char svg[], char semaExpessura[]);

/*
    *Desenha uma torre no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para a torre, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaRadioBase(double raio, double x, double y, char cor_b[], char cor_p[], char svg[], char radioExpessura[]);

/*
    *Desenha um posto no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para a criacao do posto, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaPosto(double x, double y, char svg[]);

/*
    *Desenha uma linha no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para a linha, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaLinha(double x1, double y1, double x2, double y2, char cor[], char svg[]);

/*
    *Desenha uma linha tracejada no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para a linha tracejada, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaLinhaTracejada(double x1, double y1, double x2, double y2, char svg[]);

/*
    *Finaliza o arquivo svg colocando o comando necessario nele
    *Apenas o arquivo svg a ser aberto e passado como parametro
    *Retorna nada, fecha o svg apenas.
    * 
*/
void finalizaSvg(char svg[]);

void gerarSvgGeo(Lista listasObjetos[], char saidaSvg[]);

/*
    *Imprime os elementos guardados na lista no arquivo svg feito para o qry
    *Precisa das listas e do arquivo a ser editado
    *Retorna nada.
    * 
*/
void gerarSvgQry(char saidaSvg[], Lista listasQry[]);


#endif
