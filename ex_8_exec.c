#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// Se o fork() apenas clona o programa atual, como rodamos programas diferentes (como o ls, gcc ou os seus executáveis ex_2, ex_3)?
// É aí que entra a família de funções exec() (ex: execvp, execv). A chamada exec substitui o código e a memória do processo atual por um executável completamente novo vindo do disco.

int main(){
    int rc = fork();

    if(rc == 0){
        char *meus_args[3];
        meus_args[0] = "ls";
        meus_args[1] = "-l";
        meus_args[2] = NULL;
        
        execvp(meus_args[0], meus_args);

        printf("isso só imprime se o exec falhar");
    }else{
        wait(NULL);
        printf("pai: filho executou comando ls e finalizou\n");
    }

    return 0;
}

// O processo principal (ex_8) executou o fork().
// O filho executou o execvp(). O Kernel do Linux destruiu o código antigo do filho e carregou o código do utilitário /bin/ls no lugar.
// O ls -l rodou, imprimiu essa listagem inteira no terminal e finalizou.
// O pai, que estava travado na chamada wait(NULL), "acordou" imediatamente após o encerramento do ls e imprimiu a última linha: pai: filho executou comando ls e finalizou.