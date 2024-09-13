#include <stdio.h>
#define swap(cl, c2) {processo c = cl; cl = c2; c2 = c;}
typedef struct
{
    int pid;
    int tempo;
}processo;


void rm(processo *vet, int p, int tam)
{
    for (int i = p; i < tam; i++)
    {
        swap(vet [i], vet[i+1]);
    }
}
int main()
{
    int qtdProcessos,quantum, tempoAtual;
    scanf("%d %d",&qtdProcessos, &quantum);
    processo fila[qtdProcessos];
    int i;

    for (i = 0; i < qtdProcessos; i++)
    {
        scanf("%d %d", &fila[i].pid, &fila[i].tempo);
        fila[i].tempo *= 1000; // Convertendo para milissegundos
    }

    i = 0;
    tempoAtual = 0;
    while(qtdProcessos > 0)
    {   
        if(quantum < fila[i].tempo)
        {
            tempoAtual+= quantum;
            fila[i].tempo -= quantum;
        }
        else
        {   
            tempoAtual+= fila[i].tempo;
            printf("%d (%d)\n",fila[i].pid, tempoAtual);
            rm(fila,i,qtdProcessos-1);

            qtdProcessos--;
            i--;
        }

        if(i == qtdProcessos - 1)
            i = 0;
        else
            i++;
    }
    
    return 0;
}