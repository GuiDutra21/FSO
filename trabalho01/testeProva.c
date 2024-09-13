// #include<stdio.h>
// #include<stdlib.h>
// #include <unistd.h>
// int main()
// {
//     for(int i = 0; i < 6; i++)
//     {
//         if(fork() >= 0)
//             continue;
//         else
//             break;
//     }
//     return 0;
// }
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t id1 = fork();
    pid_t id2 = fork();

    if(id1>0)
        wait(NULL);
    if(id2>0)
        wait(NULL);

    sleep(2);
    return 0;
}

void handler (int signal_number)
{
    contador++;
}

int main ()
{   
    
    struct sigaction sa = {};
    sa.sa_handler = &handler;
    sigaction (SIGUSR1, &sa, NULL);
    pid_t idFilho = fork();
    if(idFilho > 0)
    {
        wait(NULL);
        printf ("'SIGUSR1 recebido %d vezes\n", contador);
    }
    else
    {
        kill(SIGURS1);
    }
    return 0;
}