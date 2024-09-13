#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h> // Para memset
// #define _XOPEN_SOURCE 700

// int main()
// {
    // __pid_t meuPid = getpid();
    // printf("Pid atual do processo : %d\n",meuPid);

    // __pid_t pidPai = getppid();
    // printf("Pid do processp pai : %d\n",pidPai);
    
    //----------------------

    // __pid_t idFilho;
    // printf("processo incial possui pid de %d\n",getpid());
    // idFilho = fork();
    // if(idFilho == 0)
    //     printf("Ola, sou o porcesso filho de pid %d e o meu pai tem o ppid %d\n",getpid(),getppid());
    // else
    //     printf("Ola, sou o processo pai de ppid %d e criei o filho %d\n",getpid(),idFilho);

    //----------------------

// }

// ------------------------

// int contador = 0;

// void handler (int signal_number)
// {
//     contador++;
// }

// int main ()
// {   
    
//     struct sigaction sa = {};
//     sa.sa_handler = &handler;
//     sigaction (SIGUSR1, &sa, NULL);
//     printf("Pressione E para terminar a execucao: \n");
//     while (getchar () != 'E');
//     printf ("'SIGUSR1 recebido %d vezes\n", contador);
//     return 0;
// }

int contador = 0;

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

// --------------------

// int main()
// {
    
//     __pid_t idFilho;
//     printf("processo incial possui pid de %d\n",getpid());
//     idFilho = fork();

//     if(idFilho == 0)
//     {
//         printf("Ola, sou o porcesso filho de pid %d e o meu pai tem o ppid %d\n",getpid(),getppid());
//         exit(0);
//     }
//         wait(NULL);
//         printf("Ola, sou o processo pai e o filho terminou de executar\n");
//     return 0;
// }

// ---------------------

// int main()
// {
//     __pid_t filho;
//     filho = fork();
//     if(filho > 0)
//         sleep(2);
//     else
//     {
//         printf("teste\n");
//         exit(0);
//     }
//     wait(NULL);
//     return 0;
// }

// ----------------

// int spawn (char* program, char** arg_list) 
// {
//     pid_t child_pid;
//     /* Duplicate this process. */
//     child_pid = fork ();

//     if (child_pid != 0)
//     {
//     /* This is the parent process. */
//         printf("father here\n");
//         return child_pid;
//     }
//     else
//     {
//         /* Now execute PROGRAM, searching for it in the path. */
//         execvp (program, arg_list);
//         /* The execvp function returns only if an error occurs. */
//         fprintf (stderr, "an error occurred in execvp\n");
//         abort ();
//     }
// }
// int main ()
// {
//     /* The argument list to pass to the "ls" command. */
//     char* arg_list[] = 
//     {
//         "ls", /* argv[0], the name of the program. */
//         "-l",
//         "/",
//         NULL /* The argument list must end with a NULL. */
//     };
//     /* Spawn a child process running the "ls" command. Ignore the
//     returned child process ID. */
//     spawn ("ls", arg_list);
//     printf ("done with main program\n");
//     return 0;
// } 

// -----------

// #include <signal.h>
// #include <stdio.h>
// #include <string.h>
// #include <sys/types.h>
// #include <unistd.h>
// sig_atomic_t sigusr1_count = 0;
// void handler (int signal_number)
// {
//     ++sigusr1_count;
// }
// int main ()
// {
//     struct sigaction sa;
//     memset (&sa, 0, sizeof (sa));
//     sa.sa_handler = &handler;
//     sigaction (SIGUSR1, &sa, NULL);
//      /* Do some lengthy stuff here. */
//      /* ... */ 
//     printf ("SIGUSR1 was raised %d times\n", sigusr1_count);
//     return 0;
// } 