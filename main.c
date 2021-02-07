#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "circulo.h"
#include "hashtable.h"
#include "fila.h"

int main()
{
    /*Pilha duracell = create();

    Circulo circ = criaCirculo(3.0, 3.0, 3.0, 3.0, "oi", "oi", "oi");
    Circulo circ1 = ;
    Circulo circ2 = criaCirculo(5.0, 5.0, 5.0, 5.0, "oi", "oi", "oi");

    insertStack(duracell, circ);
    insertStack(duracell, circ1);
    insertStack(duracell, circ2);
    
    No node;

    for(node = getTopo(duracell); node!= NULL; node = getAnterior(node))
    {
        Info c = getInfo(node);
        printf("%lf", getCirculoR(c));
    }

    Hash hashtable = createHashTable(3);

    Info info1 = criaInfo("123456");
    Info info2 = criaInfo("09876");
    Info info3 = criaInfo("7654");
    
    char key1[7];
    char key2[7];
    char key3[7];
    strcpy(key1, "circ1");
    strcpy(key2, "circ2");
    strcpy(key3, "circ3");

    insertHashTable(info1, key1, 3, hashtable);
    insertHashTable(info2, key2, 3, hashtable);
    insertHashTable(info3, key3, 3, hashtable);

    printf("%s\n", getHashInfo(info1));
    printf("%s\n", getHashInfo(info2));
    printf("%s\n", getHashInfo(info3));

    removeNodeHashTable("circ2", hashtable, 3);

    printHashTable(3, hashtable);*/

    

    /*Fila fila = createQueue();

    Circulo circ = criaCirculo(3.0, 3.0, 3.0, 3.0, "oi", "oi", "oi");
    Circulo circ1 = criaCirculo(4.0, 4.0, 4.0, 4.0, "oi", "oi", "oi");
    Circulo circ2 = criaCirculo(5.0, 5.0, 5.0, 5.0, "oi", "oi", "oi");

    insertQueue(fila, circ);
    insertQueue(fila, circ1);
    insertQueue(fila, circ2);
    
    No node;

    for(node = getPrimeiro(fila); node!= NULL; node = getProximo(node))
    {
        Info c = getInfo(node);
        printf("%lf", getCirculoR(c));
    }*/

    return 0;
}