#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lerQry.h"

void lerQry (char saidaQry[], char arqQry[], Lista listasQry, QuadTree arvoresObjetos[], Hash tabelas[])
{
    char* saidaTxt = malloc((5 + strlen(saidaQry))*sizeof(char));
    char* saidaSvg = malloc((5 + strlen(saidaQry))*sizeof(char));
    sprintf(saidaTxt,"%s.txt",saidaQry);
    sprintf(saidaSvg,"%s.svg",saidaQry);

    FILE* qry = fopen(arqQry,"r");
    FILE* saida = fopen(saidaTxt,"w");
    FILE* saidaSvgQry = fopen(saidaSvg,"w");

    iniciaSvg(saidaSvgQry);

    if(saida == NULL || qry == NULL)
    {
        printf("Erro ao abrir o QRY ou ao gerar o TXT\n");
        exit(1);
    }
    char j[20], k[20];
    int ident;
    double x, y, r, w ,h, num, n;
    char tipo[5], corb[20], corp[20], identificacao[20], parametroOpcional[1], face[1], cep[20], cpf[20], cnpj[25], compl[20], t[2], sfx[25], tp[20];

   while(fscanf(qry,"%s",tipo) != EOF)
    {
        if(strcmp(tipo,"o?") == 0)
        {
            fscanf(qry,"%s %s",j,k);
            fprintf(saida,"%s %s %s\n",tipo,j,k);
            o(j, k, arvoresObjetos, listasQry, saida);
        }
        else if(strcmp(tipo,"i?") == 0)
        {
            fscanf(qry,"%s %lf %lf",j,&x,&y);
            fprintf(saida,"%s %s %lf %lf\n",tipo,j,x,y);  
            i(j, x, y, arvoresObjetos, listasQry, saida);
        }
        else if(strcmp(tipo,"pnt") == 0)
        {
            fscanf(qry,"%s %s %s",j,corb,corp);
            fprintf(saida,"%s %s %s %s\n",tipo,j,corb,corp);
            pnt(j, corb, corp, arvoresObjetos, saida);
        }
        else if(strcmp(tipo,"pnt*") == 0)
        {
            fscanf(qry,"%s %s %s %s",j,k,corb,corp);
            fprintf(saida,"%s %s %s %s %s\n",tipo,j,k,corb,corp);
            pnt(j, corb, corp, arvoresObjetos, saida);
            pnt(k, corb, corp, arvoresObjetos, saida);
        }
        else if(strcmp(tipo,"delf") == 0)
        {
            fscanf(qry,"%s",j);
            fprintf(saida,"%s %s\n",tipo,j); 
            delf(saida, arvoresObjetos, j);
        }
        else if(strcmp(tipo,"delf*") == 0)
        {
            fscanf(qry,"%s %s",j,k);
            fprintf(saida,"%s %s %s\n",tipo,j,k);
            delf(saida, arvoresObjetos, j);
            delf(saida, arvoresObjetos, k);
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
        }
        else if(strcmp(tipo, "del")==0)
        {
            fscanf(qry,"%s",identificacao);
            fprintf(saida,"%s %s\n",tipo, identificacao);
        }
        else if(strcmp(tipo, "cbq")==0)
        {
            fscanf(qry,"%lf %lf %lf %s",&x, &y, &r, corb);
            fprintf(saida,"%s %lf %lf %lf %s\n",tipo,x, y, r, corb);
        }
        else if(strcmp(tipo, "crd?")==0)
        {
            fscanf(qry,"%s",identificacao);
            fprintf(saida,"%s %s\n",tipo, identificacao);
        }
        else if(strcmp(tipo, "car")==0)
        {
            fscanf(qry,"%lf %lf %lf %lf",&x, &y, &w, &h);
            fprintf(saida,"%s %lf %lf %lf %lf\n",tipo, x, y, w, h);
        }
        else if(strcmp(tipo, "cv")==0)
        {
            fscanf(qry,"%lf %s %s %lf",&n, cep, face, &num);
            fprintf(saida,"cv %lf %s %s %lf\n", n, cep, face, num);
        }
        else if(strcmp(tipo, "soc")==0)
        {
            fscanf(qry,"%s %s %s %lf",k, cep, face, &num);
            fprintf(saida,"soc %s %s %s %lf\n", k, cep, face, num);
        }
        else if(strcmp(tipo, "ci")==0)
        {
            fscanf(qry,"%lf %lf %lf",&x, &y, &r);
            fprintf(saida,"%s %lf %lf %lf\n",tipo, x, y, r);
        }
        else if(strcmp(tipo, "m?")==0)
        {
            fscanf(qry,"%s",cep);
            fprintf(saida,"%s\n",tipo);
        }
        else if(strcmp(tipo, "dm?")==0)
        {
            fscanf(qry,"%s",cpf);
            fprintf(saida,"%s\n",tipo);
        }
        else if(strcmp(tipo, "de?")==0)
        {
            fscanf(qry,"%s",cnpj);
            fprintf(saida,"%s\n",tipo);
        }
        else if(strcmp(tipo, "mud")==0)
        {
            fscanf(qry,"%s %s %s %lf %s",cpf, cep, face, &num, compl);
            fprintf(saida,"%s\n",tipo);
        }
        else if(strcmp(tipo, "dmprbt")==0)
        {
            fscanf(qry,"%s %s", t, sfx);
            fprintf(saida,"%s\n",tipo);
        }
        else if(strcmp(tipo, "eplg?")==0)
        {
            fscanf(qry,"%s", parametroOpcional);

            if(strcmp(parametroOpcional,"*")==0)
            {
                ident=1;
                fscanf(qry,"%lf %lf %lf %lf", &x, &y, &w, &h);
                fprintf(saida,"%s %lf %lf %lf %lf\n", tipo, x, y, w, h);
            }
            else if(strcmp(parametroOpcional,"tp")==0)
            {
                ident=0;
                fscanf(qry,"%lf %lf %lf %lf", &x, &y, &w, &h);
                fprintf(saida,"%s %lf %lf %lf %lf\n", tipo, x, y, w, h);
                strcpy(tp, parametroOpcional);
            }
        }
        else if (strcmp(tipo, "catac")==0)
        {
            fscanf(qry,"%lf %lf %lf",&x, &y, &r);
            fprintf(saida,"%s %lf %lf %lf\n",tipo, x, y, r);
        }
    }

    gerarSvgQry(arvoresObjetos, listasQry, saidaSvgQry);
     
    finalizaSvg(saidaSvgQry);

    fclose(saida);
    fclose(qry);
    free(saidaSvg);
    free(saidaTxt);
}