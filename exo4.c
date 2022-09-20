#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

    while(1){

        printf("\n");
        char cmd[100];
        printf("\033[1;31m");
        printf("->\033\033[0;32m ");
        scanf("%[^\n]", cmd);
        printf("\n");
        printf("----->\033[0;37m\n");

        char *args[50];
        int i = 0;
        args[i] = strtok(cmd, " ");
        while(args[i] != NULL){
            i++;
            args[i] = strtok(NULL, " ");
        }

        int background = 0;
        if(strcmp(args[i-1], "&") == 0){
            background = 1;
            args[i-1] = NULL;
        }

        pid_t pid = fork();

        if(pid == 0){
            execvp(args[0], args);
            exit(0);
        }
        else{
            if(!background){
                wait(NULL);
                printf("\033[0;32m----->\n");
            }
        }

        
        getchar();
        
        
    }

}