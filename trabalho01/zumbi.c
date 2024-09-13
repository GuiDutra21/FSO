#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h> // Para memset
#include <sys/types.h>
int qtdSinal = 0;

void handler (int signal_number)
{
    qtdSinal++;
    if(qtdSinal == 1)
    {   
        pid_t filho;
        filho = fork();

        if(filho == 0)
            exit(0);
    }
    if(qtdSinal == 2)
    {
        wait(NULL);
    }
    
    if(qtdSinal == 3)
        exit(0);
}

int main ()
{   
  
    struct sigaction sa = {};
    sa.sa_handler = &handler;
    sigaction (SIGUSR1, &sa, NULL);
    sigaction (SIGUSR2, &sa, NULL);
    while(qtdSinal != 3);
    
    return 0;
}