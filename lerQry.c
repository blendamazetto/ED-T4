#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lerQry.h"

void lerQry (char saidaQry[], Lista listasObjetos[], char arqQry[], Lista listasQry)
{
    char* saidaTxt = malloc((5 + strlen(saidaQry))*sizeof(char));
    char* saidaSvg = malloc((5 + strlen(saidaQry))*sizeof(char));
    sprintf(saidaTxt,"%s.txt",saidaQry);
    sprintf(saidaSvg,"%s.svg",saidaQry);

    FILE* qry = fopen(arqQry,"r");
    FILE* saida = fopen(saidaTxt,"w");

    iniciaSvg(saidaSvg);

    if(saida == NULL || qry == NULL)
    {
        printf("Erro ao abrir o QRY ou ao gerar o TXT\n");
        exit(1);
    }

    int j;
    int k;
    int ident;
    double x;
    double y;
    char tipo[5];
    char corb[20];
    char corp[20];
    char identificacao[20];
    double r;
    char parametroOpcional[1];
    double w, h;
    char face[1];
    char cep [20];
    double num;
    double n;


   while(fscanf(qry,"%s",tipo) != EOF)
    {
        if(strcmp(tipo,"o?") == 0)
        {
            fscanf(qry,"%d %d",&j,&k);
            fprintf(saida,"%s %d %d\n",tipo,j,k);
            o(j, k, saida, listasObjetos, listasQry);
        }
        else if(strcmp(tipo,"i?") == 0)
        {
            fscanf(qry,"%d %lf %lf",&j,&x,&y);
            fprintf(saida,"%s %d %lf %lf\n",tipo,j,x,y);
            i(listasObjetos, j, x, y, saidaSvg, saida, listasQry);
        }
        else if(strcmp(tipo,"pnt") == 0)
        {
            fscanf(qry,"%d %s %s",&j,corb,corp);
            fprintf(saida,"%s %d %s %s\n",tipo,j,corb,corp);
            pnt (listasObjetos, j, corb, corp, saida);

        }
        else if(strcmp(tipo,"pnt*") == 0)
        {
            fscanf(qry,"%d %d %s %s",&j,&k,corb,corp);
            fprintf(saida,"%s %d %d %s %s\n",tipo,j,k,corb,corp);
            pnt (listasObjetos, j, corb, corp, saida);
            pnt (listasObjetos, k, corb, corp, saida);
        }
        else if(strcmp(tipo,"delf") == 0)
        {
            fscanf(qry,"%d",&j);
            fprintf(saida,"%s %d\n",tipo,j);
            delf(listasObjetos, j, saida);
        }
        else if(strcmp(tipo,"delf*") == 0)
        {
            fscanf(qry,"%d %d",&j,&k);
            fprintf(saida,"%s %d %d\n",tipo,j,k);
            delf(listasObjetos, j, saida);
            delf(listasObjetos, k, saida);
        }
       else if(strcmp(tipo, "dq") == 0) 
        {
            
            fscanf(qry,"%s", parametroOpcional);

             if(strcmp(parametroOpcional,"#")==0)
            {
                ident=1;
                fscanf(qry,"%s %lf",identificacao, &r);
                fprintf(saida,"dq# %s %lf\n", identificacao, r);
            }
            else
            {
                ident=0;
                fscanf(qry,"%lf", &r);
                strcpy(identificacao, parametroOpcional);
                fprintf(saida,"dq %s %lf\n",identificacao, r);
            }
            dq(listasObjetos, saida, saidaSvg, identificacao, r, ident, listasQry);
        }
        else if(strcmp(tipo, "del")==0)
        {
            fscanf(qry,"%s",identificacao);
            fprintf(saida,"%s %s\n",tipo, identificacao);
            del(listasObjetos, identificacao, saida, saidaSvg, listasQry);
        }
        else if(strcmp(tipo, "cbq")==0)
        {
            fscanf(qry,"%lf %lf %lf %s",&x, &y, &r, corb);
            fprintf(saida,"%s %lf %lf %lf %s\n",tipo,x, y, r, corb);
            cbq(listasObjetos, x, y, r, corb, saida);
        }
        else if(strcmp(tipo, "crd?")==0)
        {
            fscanf(qry,"%s",identificacao);
            fprintf(saida,"%s %s\n",tipo, identificacao);
            crd(listasObjetos, identificacao, saida);
        }
        else if(strcmp(tipo, "car")==0)
        {
            fscanf(qry,"%lf %lf %lf %lf",&x, &y, &w, &h);
            fprintf(saida,"%s %lf %lf %lf %lf\n",tipo, x, y, w, h);
            car(listasObjetos, x, y, w, h, saidaSvg, saida, listasQry);
        }
        else if(strcmp(tipo, "cv")==0)
        {
            fscanf(qry,"%lf %s %s %lf",&n, cep, face, &num);
            fprintf(saida,"cv %lf %s %s %lf\n", n, cep, face, num);
            cv(listasObjetos, n, cep, face, num, listasQry);
        }
        else if(strcmp(tipo, "soc")==0)
        {
            fscanf(qry,"%d %s %s %lf",&k, cep, face, &num);
            fprintf(saida,"soc %d %s %s %lf\n", k, cep, face, num);
            soc(listasObjetos, k, cep, face, num, saida, listasQry);
        }
        else if(strcmp(tipo, "ci")==0)
        {
            fscanf(qry,"%lf %lf %lf",&x, &y, &r);
            fprintf(saida,"%s %lf %lf %lf\n",tipo, x, y, r);
            ci(saida, listasObjetos, x, y, r, listasQry);
        }
    }

    gerarSvgGeo(listasObjetos, saidaSvg);
    gerarSvgQry(saidaSvg, listasQry);

    finalizaSvg(saidaSvg);

    fclose(saida);
    fclose(qry);
    free(saidaSvg);
    free(saidaTxt);
}