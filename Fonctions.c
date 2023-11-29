#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "Fonctions.h"

#define WELCOME_MSG "Bienvenue dans le Shell ENSEA\nPour quitter tapez 'exit'\nenseash % "
#define MAXSIZE 1024
#define ENSEA "\nenseash % "

void Question1_Acceuil() {
    write(STDOUT_FILENO, WELCOME_MSG, strlen(WELCOME_MSG));
}
void Question2_Cmd(){
    char cmd[MAXSIZE]={0};
    ssize_t nbChar;
    nbChar=read(STDIN_FILENO, cmd, MAXSIZE);
    cmd[nbChar-1]='\0';
    pid_t pid;
    int status;
    pid=fork(); //to create a child

    if(pid==0){ // for the child program
        execlp(cmd,cmd,NULL);//execlp replace process in progress by the command sent
        exit(EXIT_FAILURE);//the child program is shut down
    }
    else{ // the father program continues here (thanks to the while loop in the main.c code)
        wait(&status);
        write(STDOUT_FILENO,ENSEA, strlen(ENSEA));
    }

}
