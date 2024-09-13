#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

double executa(char *str1, char *str2)
{   
    struct timeval inicio, fim;
    double segundos, microssegundos,tempo = 0.0;
    int status;

    pid_t idFIlho = fork();
    gettimeofday(&inicio, NULL);
    if(idFIlho == 0)
    {
        execl(str1,str1,str2,(char*)NULL);
        printf("> Erro: %s\n",strerror(errno));
        fclose(stdin);
        exit(errno);
    }
    
    if (waitpid(idFIlho, &status, WUNTRACED))
        gettimeofday(&fim, NULL);

    segundos = fim.tv_sec - inicio.tv_sec;
    microssegundos = fim.tv_usec - inicio.tv_usec;

    microssegundos /= 1000000;
    int segundosInteiros = segundos;
    tempo = segundosInteiros + microssegundos;
    
    printf("> Demorou %.1lf segundos, retornou %d\n",tempo,WEXITSTATUS(status));

    fflush(stdout);
    return tempo;
}


int main()
{
    char str1[256];
    char str2[256];
    double tempo = 0.0;

    while(scanf("%s %s",str1,str2) != EOF)
    {   
        tempo += executa(str1,str2);
    }

    printf(">> O tempo total foi de %.1lf segundos\n",tempo);
    return 0;
}