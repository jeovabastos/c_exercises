#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    printf("antes do fork PID: %d\n", getpid());

    int rc = fork();

    if(rc < 0){
        fprintf(stderr, "falha no fork\n");
    }else if(rc == 0){
        printf("eu sou o filho pid: %d\n", getpid());
    }else{
        printf("eu sou o pai %d e meu filho é %d\n", getpid(), rc);
    }
}