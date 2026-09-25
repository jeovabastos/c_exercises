#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int rc = fork();

    if(rc == 0){
        printf("filho: fazendo trabalho demorado\n");
        sleep(3);
    }else{
        wait(NULL);
        printf("pai: filho terminou, agora posso continuar\n");
    }

    return 0;
}