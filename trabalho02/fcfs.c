#include <stdio.h>
#include <stdlib.h>
#define swap(cl, c2) {processo c = cl; cl = c2; c2 = c;}

typedef struct Processo
{   
    int num;
    char *instrucoes;
    int qtdInstrucoes;
    int instrucaoAtual;
}processo;

// Coloca o processo no fim do array para descarta-lo
void jogaFinal(processo *processos, int remover, int n)
{
    while(remover < n - 1)
    {
        swap(processos[remover], processos[remover + 1]);
        remover++;
    }
}

int main()
{   
    int n;
    scanf("%d",&n);

    processo processos[n];
    int qtdInstrucoes;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&qtdInstrucoes);
        processos[i].qtdInstrucoes = qtdInstrucoes;
        processos[i].instrucoes = malloc(qtdInstrucoes * sizeof(char));
        processos[i].instrucaoAtual = 0;
        processos[i].num = i + 1;
    }

    int instrucao;
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < processos[i].qtdInstrucoes; j++)
        {
            scanf("%d",&instrucao); 
            processos[i].instrucoes[j] = instrucao;
        }
        
    }

    int tempo = 0, processosAtivos = n, i = 0, j;
    while(processosAtivos > 0)
    {
        j = processos[i].instrucaoAtual;
        while(j < processos[i].qtdInstrucoes)
        {
            if(processos[i].instrucoes[j]) // Se a instrucao for igual a 1
            {
                processos[i].instrucoes[j] = 0;
                break;
            }
            else // Se for igual a zero
            {
                tempo += 10;
                if(++processos[i].instrucaoAtual == processos[i].qtdInstrucoes)
                {   
                    printf("%d (%d)\n",processos[i].num, tempo);
                    jogaFinal(processos,i,processosAtivos);
                    processosAtivos--;
                    i--;
                    break;
                }
                else j++;
            }
        }

        if(i == processosAtivos - 1) i = 0;
        else i++;
        // i = (i + 1)%processosAtivos;
    }
    return 0;
}