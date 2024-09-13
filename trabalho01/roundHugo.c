#include <stdio.h>
// #include <limits.h>
// #include < string.h> 
// #include <ctype.h>
// #include <math.h>
// #include <stdlib.h>
// #define show(n) printf("sd\n", n);
// #define entrou printf( "ENTROU\n" ) ;
#define swap(cl, c2) {processo c = cl; cl = c2; c2 = c;}
typedef struct {
int pid;
int tempo;
} processo;

void rm(processo *vet, int p, int tam)
{
    for (int i = p; i < tam; i++)
    {
        swap(vet [i], vet[i+1]);
    }
}

int main (void)
{

    int qtd, tempot;
    int quantum, aux;
    scanf("%d %d", &qtd, &quantum);
    processo fila[qtd];

    for (int i = 0; i < qtd; i++)
    {
        scanf("%d %d", &fila[i].pid, &aux);
        fila[i].tempo = aux * 1000;
    }

    tempot = 0;
    int controle = qtd;

    while( controle > 0)
    {
        for (int i = 0; i < controle; i++)
        {
            if (fila[i].tempo > quantum)
            {
            tempot += quantum;
            fila[i].tempo -= quantum;
            }
            else
            {
                tempot += fila[i]. tempo;
                printf("%d (%d)\n", fila[i].pid, tempot);
                rm (fila, i, qtd);
                controle--;
                i--;
            }
        }
    }
    return 0;
}